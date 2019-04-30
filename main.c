#include <stdio.h>
#include <malloc.h>

void exam() {
    int *p;
    int a;

    scanf("%d", &a);

    /**
     * malloc : 할당만 받음
     * calloc : 메모리 할당 후 기본 값 설정
     * realloc : 재할당 메모리 체계 확장
     *
     * 가비지
     * 맹글링 포인터
     */
//    p = (int *) malloc(sizeof(int) * a);
    p = (int *) calloc(sizeof(int), a);

    for (int i = 0; i < a; i++) {
        printf("숫자를 입력하세요: ");
        scanf("%d", p + i);
    }


    int result = 0;
    for (int i = 0; i < a; i++) {
        result += *(p + i);
    }

    printf("RESULT : %d\n", result);
}

void exam1(){
    int *a = malloc(sizeof(int) * 3);

    a[0] = 1;
    a[1] = 1;
    a[2] = 1;

    printf("%p\n", a);

    a = realloc(a, 5);

    a[3] = 3;

    printf("%d\n", a[3]);
    printf("%p\n", a);

}

int main() {
    exam1();
    return 0;
}