#include <stdio.h>

typedef int element;
int size, i = 0;

int partition(element a[], int begin, int end) {
    int pivot, L, R, t;
    element temp;
    L = begin;
    R = end;
    pivot = (int)((begin + end) / 2.0);

    printf("\n[%d단계 : pivot=%d ] \n", ++i, a[pivot]);
    while (L < R) {
        while ((a[L] < a[pivot]) && (L < R)) L++; // 왼쪽 부분 집합 중 pivot 보다 큰 값 탐색
        while ((a[R] >= a[pivot]) && (L < R)) R--; // 오른쪽 부분 집합 중 pivot 보다 작은 값 탐색
        if (L < R) { // L, R 탐색 완료
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;

            if (L == pivot) pivot = R; // L이 pivot인 경우 ->
                                       // 왼쪽에 바꿀 값이 없을 경우 R이 pivot 
        }
    }

    temp = a[pivot];
    a[pivot] = a[R];
    a[R] = temp; 
    for (t = 0; t < size; t++) printf("%d ", a[t]);
    printf("\n");
    return R;
}

void quickSort(element a[], int begin, int end) {
    int p;
    if (begin < end) {
        p = partition(a, begin, end);
        quickSort(a, begin, p-1);
        quickSort(a, p+1, end);

    }
}

int main() {
    element list[8] = { 69, 10, 30, 2, 17, 8, 31, 22 };
    size = 8;
    int i;
    for (i = 0; i < size; i++) printf("%d ", list[i]);

    quickSort(list, 0, size-1);

    return 0;
}
