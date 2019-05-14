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