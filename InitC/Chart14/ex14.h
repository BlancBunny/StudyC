int main();

// 단어 입력
// 1. 입력 단어가 exit 일때 프로그램 종료 
void input_word(char* word, int* length) {
	printf("단어 입력(exit 입력 시 종료) : ");
	gets_s(word, sizeof(*word) * 20);
	*length = strlen(word);
	if (strcmp(word, "exit") == 0) {
		printf("프로그램 종료!\n");
		exit(0);
	}
}

// 회문 체크 
// 1. 단어 미입력 체크
// 2. 길이의 반만큼 돌면서 글자 비교 
// 3. 결과 출력 

void palindrome_check(char* pc, int size) {
	char* ps = pc; // 단어의 시작 주소
	char* pe = ps + size - 1; // 단어의 끝 주소 
	
	if (*ps == '\0') {
		printf("단어를 입력하세요.\n");
		return;
	}
	for (int i = 0; i < size / 2; i++) {
		if (*(ps + i) != *(pe - i)) {
			printf("회문이 아닙니다.\n");
			return;
		}
	}
	printf("회문입니다.\n");
}

