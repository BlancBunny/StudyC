#include <stdio.h>

void insertionSort(int* ary, int size) {
    int i, j, k, tmp;
    for (i = 1; i < size; i++) {
        tmp = ary[i];
        j = i;
        while ((j > 0) && ary[j-1] > tmp) {
            ary[j] = ary[j-1];
            j = j-1;
        }
        ary[j] = tmp;
        printf("\n%d단계 : ", i);
        for (k = 0; k < size; k++) printf("%3d ", ary[k]);
    }
}

int main() {
    int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    int size = 8;

    insertionSort(list, size);
    return 0;
}
