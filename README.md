# SSU 19 PROGRAMMING(for developer) LECTURE


### 2019.04.30

- `malloc(sizeof(int) * n)` : 메모리 동적 할당
- `calloc(sizeof(int), n)`  : 메모리 동적 할당, 기본 값
- `realloc(sizeof(int), n)` : 메모리 재할당, memcopy없이 주소를 확장, 컨플릭트 나는 경우가 있긴 하나 보통 여유분을 두고 할당하므로 발생하지는 않는다.


*주의할 점*
- 가비지           : 할당은 받았으나, 메모리 주소를 잃어버린 경우
- 댕글링 포인터     : 목짤린 포인터, 포인터는 알고 있으나 이미 다른 코드에서 해제가 되어버린 포인터

### 2019.05.14 함수


#### 함수 포인터

```c
int get_gcd(int x, int y)
{
}
```
위와 같은 함수가 있다고 가정하고 이 함수를 변수에 할당하여 여러 곳에서 주소를 전달
하여 사용하고 싶다고 하자. 이 때 사용하는 것이 함수 포인터이다.

##### 함수 포인터 선언

```c
// FORMAT : RETURN_TYPE (*VAR_NAME)(PARAM_TYPES...)
int (*function_var)(int, int) = get_gcd;
```

위 코드에서 함수 포인터의 기본 선언 형식을 알 수 있으며 바로 아래 코드에서 사용할 수 있는
방법을 알 수 있다. 함수에 대한 주소는 배열과 같이 `&fun_name`과 `fun_name`를 이용하여 
얻을 수 있으며 모두 값은 값을 반환하고 있다.


##### 함수 포인터 사용

```c
# Use Cases

int result = (*function_var)(3, 5);
int result = function_var(3, 5);
```

함수 포인터를 사용하는 방법 또한 배열의 인덱스 접근과 유사하게 주소접근연산자 `*`
를 사용하여 접근할 수 있으나 일반적인 함수 호출 처럼 `function_var(x, y)`형태로
사용해도 된다.

##### 커스텀 함수 포인터 타입 정의

```c
// typedef RETURN_TYPE (*CUSTOM_POINTER_TYPE_NAME)(PARAM_TYPES...);
typedef int (*CUSTOM_FUNC_POINTER_TYPE)(int, int);
```

`int (*NAME)(int, int);` 매번 좌측과 같은 형태의 함수 포인터를 사용하게 되면
코드가 선언문으로 뒤 덮혀 더러워지게 될 것이므로 clang에서는 기본적으로 `typedef`
를 통해 해당 타입을 커스텀으러 선언할 수 있다. 

```c
CUSTOM_FUNC_POINTER_TYPE func_name = add;
func_name(1, 3);
```

다른 포인터 사용과 같이 위와 같이 여전히 사용이 가능하다.

##### 함수 포인터 배열

함수 포인터도 결과적으로 주소 값이므로 이를 배열로 사용할 수 있다.

```c
void print_a(){ printf("hi"); }
void print_b(){ printf("hello"); }
void print_c(){ printf("bye!"); }

int main() {
    void (*func_ptr_arr[3])() = { print_a, print_b, print_c };
    CUSTOM_FUNC_TYPE custom_ptr_arr[3] = {};
}
```

##### 사용 예, qsort

c언어 표준 인터페이스로 제공되는 qsort는 quick sort 구현체로 아래와 같이 사용이 가능하다.
`compare`는 비교 대상 로직을 받아 정렬할 수 있도록 넘겨주는 함수 포인터이다.

```c
    int items[] = {1, 2, 3, 4, 5, 6};
    qsort(items, 6, sizeof(items[0]), compare);
```

### 2019.05.21 struct, union, enum

#### 구조체

구조체는 여러 값들의 집합으로 하나의 구조체 변수 선언시 구조체 내부의 모든 필드의
메모리 공간을 합한 만큼 할당됨.

##### 구조체 선언

```c
// 선언 방식 1
struct Sample {
    char *name;
    int price;
};
struct Sample1 sample1;

// 선언 방식 2
struct Sample {
    char *name;
    int price;
} sample1;

// 선언 방식 3
typedef struct Sample { // 이름 Sample은 없어도 됨
    char *name;
    int price
} SAMPLE;

SAMPLE sample1;
```

##### 구조체 할당

```c
typedef {
    char *name;
    int price;
} PRODUCT;

PRODUCT product1 = { "something pen", 3200 };
```

#### 공용체

구조체와 선언 방식자체는 거의 유사함, 다만 모든 변수가 가장 큰 타입만큼 할당 받은
메모리 공간은 공유하므로 다른 필드의 값을 침해함. 사용시 유의해야함.

```c
union UnionSample {
    char *name;
    int price;
}
union UnionSample sample;
sample.price = 100;
```

#### 열거형 타입


### 2019.05.28 Standard FILE Input Output

#### 파일 읽기 쓰기 모드 설명

|옵션|기능|파일이 없을 경우| 파일이 있을 경우|파일 출력 기존 내용 유지 여부|
|---|----|-------------|------------|-----------------|
|r |읽기 |오류 발생 |기존 파일 이용| 오류 발생|
|r+ |읽기/쓰기 |오류 발생 |기존 파일 이용 |앞에서부터 겹쳐서 써짐|
|w |쓰기 |새 파일 생성 |새 파일 생성 |지우고 새로 써짐|
|w+ |쓰기/읽기 |새 파일 생성 |새 파일 생성 |지우고 새로 써짐|
|a |쓰기(이어서 쓰기) |새 파일 생성 |기존 파일 이용 |뒤에 이어서 써짐|
|a+ |쓰기/읽기|새 파일 생성|기존 파일 이용|뒤에 이어서 써짐|


