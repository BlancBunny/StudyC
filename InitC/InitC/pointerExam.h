int main();

void input_arr(int* arr, int size) { 
	printf("%d개 정수 입력 : ", size);
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void print_arr(int* arr, int size) { 
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//void swap_arr(int* arr, int size) {
//	int tmp;
//	for (int i = 0; i < size / 2; i++) {
//		tmp = arr[i]; 
//		arr[i] = arr[size - i - 1];
//		arr[size - i - 1] = tmp;
//	}
//}

void swap_arr(int* pa, int* pb, int size) {
	int tmp;
	for (int i = 0; i < size / 2; i++) {
		tmp = *pa;
		*pa = *pb;
		*pb = tmp;
		pa++;
		pb--;
	}
}
