int main();

void input_lotto(int* lotto, int size) {
	int tmp = 0;
	for (int i = 0; i < size; i++) {
		printf("%d번째 숫자 입력 : ", i + 1);
		
		// 임시 저장
		scanf_s("%d", &tmp); 

		// 범위 검사
		if (tmp < 0 || tmp > 45) {
			printf("숫자 범위(1~45) 이탈. 재입력\n");
			i--;
			continue;
		}
		
		// 1번 입력
		if (i == 0) lotto[i] = tmp; 

		// 중복 검사
		for (int j = 0; j < i; j++) {
			if (tmp == lotto[j]) {
				printf("동일한 숫자 발견. 재입력\n");
				i--;
				break;
			}
			else lotto[i] = tmp; 
		}
	}
	while (getchar() != '\n');
}

// 입력 (tmp)		  <-┐
// 검사 (범위 / 중복)  -┘
// 대입 

void print_lotto(int* lotto) {
	printf("입력된 번호 : ");
	for (int i = 0; i < 6; i++) {
		printf("%d ", lotto[i]);
	}
}