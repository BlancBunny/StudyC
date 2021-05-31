#include <stdio.h>

void selectionSort(int* ary, int size) {
    int i, j, t, min, tmp;
    for (i = 0; i < size-1; i++) {
        min = i;
        for (j = i+1; j < size; j++) {
            if (ary[j] < ary[min]) min = j;
        }
        
        tmp = ary[i];
        ary[i] = ary[min];
        ary[min] = tmp;
        printf("%d단계 : ", i+1);
        for (t = 0; t < size; t++) printf("%d ", ary[t]);
        printf("\n");
    }
}


int main() {

    int ary[8] = {66, 72, 3, 50, 27, 35, 90, 5};
    int size = sizeof(ary) / sizeof(ary[0]);

    selectionSort(ary, size);

    
    return 0;
}
