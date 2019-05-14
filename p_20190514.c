#include <stdio.h>
#include <stdlib.h>


void swap_max_min(int *x, int *y) {
    if (*x < *y)
        *x ^= *y ^= *x ^= *y;
}

int gcd_iter(int x, int y) {
    swap_max_min(&x, &y);
    for (int i = x % y; i > 0; i = x % y) {
        x = y;
        y = i;
    }

    return y;
}

int gcd_rec(int x, int y) {
    swap_max_min(&x, &y);
    if (y == 0)
        return x;
    return gcd_rec(y, x % y);
}

int add(int x, int y) {
    return x + y;
}

void use_case_about_function_pointer() {
    int (*func_var)(int, int) = gcd_rec;
    printf("%d\n", func_var(5, 4));

    func_var = gcd_iter;
    printf("%d\n", func_var(5, 4));

    func_var = add;
    printf("%d\n", func_var(5, 4));
    printf("%d\n", (*func_var)(5, 4));
}

typedef int (*CUSTOM_FUNC_POINTER_TYPE)(int, int);

void use_case_count_custom_type() {
    CUSTOM_FUNC_POINTER_TYPE func = add;
    printf("%d\n", func(1, 2));
}

void print_a() { printf("hi"); }

void print_b() { printf("hello"); }

void print_c() { printf("bye!"); }

int use_case_function_ptr() {
    void (*func_ptr_arr[3])() = {print_a, print_b, print_c};

    for (int i = 0; i < 3; i++) {
        func_ptr_arr[i]();
    }
}

int compare(int a, int b) {
    return a - b;
}

int qsort_sample() {
    use_case_function_ptr();

    int items[] = {1, 2, 3, 4, 5, 6};
    qsort(items, 6, sizeof(items[0]), compare);
}