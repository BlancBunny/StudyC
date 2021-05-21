#include <stdio.h>

int LSearch(int* ary, int size, int data) {
    int i;
    for (i = 0; i < size; i++) {
        if (*(ary+i) == data) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int i;
    int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
    int size = sizeof(ary) / sizeof(ary[0]);
    int data = 2;
    int index = LSearch(ary, size, data);
    printf("배열 : [ ");   
    for (i = 0; i < size; i++) {
        printf("%d ", ary[i]);
    }
    printf("]\n");
    printf("%d : %d번째\n", data, index+1);
    return 0;

}
