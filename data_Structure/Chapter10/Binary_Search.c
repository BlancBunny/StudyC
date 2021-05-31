#include <stdio.h>

int BSearch(int* ary, int size, int data) {
    int first = 0;
    int last = size - 1;
    int mid;

    while (first <= last) {
        mid = (first + last) / 2; 
        if (data == ary[mid]) return mid;
        else {
            if (data > ary[mid]) first = mid + 1;
            else last = mid - 1;
        }  
    }
    return mid;
}

int main() {
    int ary[] = { 1, 2, 4, 6, 8, 9, 10 };
    int size = sizeof(ary) / sizeof(ary[0]);
    int index;
    int data = 9;

    index = BSearch(ary, size, data);
    if (index == -1) printf("탐색 실패\n");
    else printf("%d\n", index);
        
}
