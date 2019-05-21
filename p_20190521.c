#include <stdio.h>


typedef enum { false = 0, true = 1 } bool;


void swap(int *a, int *b) {
    if (a != b)
        *a ^= *b ^= *a ^= *b;
}

void selection_sort(int *items, int count, int(*cond)(int, int)) {
    for (int i = 0; i < count - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < count; j++) {
            if (cond(items[j], items[min_index]))
                min_index = j;
        }

        swap(items + i, items + min_index);
    }
}


void bubble_sort(int *items, int count, int(*cond)(int, int)) {
    for (int i = count - 1; i > 0; i--) {
        for (int j = 0; j < i; j++){
            if (cond(items[j + 1], items[j]))
                swap(items + j, items + j + 1);
        }
    }
}

void insert_sort(int *items, int count, int(*cond)(int, int)) {
    for (int i = 1; i < count; i++){
        int value = items[i];
        int insertion_index = i;
        for (int j = i-1; j >= 0; j--){
            if (cond(value, items[j])) {
                items[j + 1] = items[j];
                insertion_index = j;
            }
            else
                break;
        }
        items[insertion_index] = value;
    }
}

int up_sort(int a, int b) {
    return a < b ? 1 : 0;
}

int down_sort(int a, int b){
    return a > b ? 1 : 0;
}

int sort_sample() {
    int numbers[5] = {5, 3, 4, 2, 1};

    insert_sort(numbers, 5, down_sort);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]);
    }

}