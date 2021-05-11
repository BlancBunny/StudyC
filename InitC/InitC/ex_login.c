/*
	ex_login.c
	메모장 사용 
	1. id와 pw 저장, 파일 이름은 login.txt
	2. struct login 에 id와 password 멤버를 선언 
	3. 키보드로 입력되는 id와 pw를 비교하여 
	같으면 로그인 성공 문구 출력 / 다르면 실패 문구 출력 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct login {
	char* id; // 파일 ID 
	char* pw; // 파일 PW
}Login;

int main() {
	FILE* fp;
	Login login;
	int res;
	char tmp[80]; // 동적 할당용 임시 저장 
	char tmp_pw[80];
	char* id_chk, * pw_chk; // 입력 ID, 입력 PW

	// 파일 열기
	errno_t err = fopen_s(&fp, "login.txt", "r"); 
	if (err == 0) {
		printf("File is Opened!\n");
	}
	else {
		printf("File is not Opened!\n");
		return 1;
	}
	
	// 파일로부터 ID/PW 저장 
	while (1) { 
		if (fp) {
			res = fscanf_s(fp, "%s%s", tmp, sizeof(tmp), tmp_pw, sizeof(tmp_pw)); // 1줄 읽기 
			if (res == EOF) break;
		}
	}
	fclose(fp); // 파일 연결 끊기 

	// 문자열이 0으로 끝나지 않을 수 있음 (실제로는 0으로 끝남..) 
	strcat_s(tmp, sizeof(tmp), ""); 
	strcat_s(tmp_pw, sizeof(tmp_pw),""); 

	// 파일 ID/PW 메모리 동적할당
	login.id = (char*)malloc(strlen(tmp) + 1);
	if (login.id != NULL) 
		strcpy_s(login.id, strlen(tmp) + 1, tmp);
	login.pw = (char*)malloc(strlen(tmp_pw) + 1);
	if (login.pw != NULL) 
		strcpy_s(login.pw, strlen(tmp_pw) + 1, tmp_pw);
	
	// ID/PW 입력, 메모리 동적할당
	printf("아이디 입력 : "); 
	gets_s(tmp, sizeof(tmp));
	id_chk = (char*)malloc(strlen(tmp) + 1); 
	if (id_chk != NULL) 
		strcpy_s(id_chk, strlen(tmp)+1, tmp); 
	printf("비밀번호 입력 : ");
	gets_s(tmp, sizeof(tmp));
	pw_chk = (char*)malloc(strlen(tmp) + 1); 
	if (pw_chk != NULL) 
		strcpy_s(pw_chk, strlen(tmp)+1, tmp);

	// 로그인 검사
	if (id_chk && pw_chk && login.id && login.pw != NULL) {
		if (strcmp(login.id, id_chk) == 0 && strcmp(login.pw, pw_chk) == 0) {
			printf("로그인되었습니다.\n");
		}
		else printf("ID/PW를 찾을 수 없습니다.\n");
	}
	
	// 메모리 할당 해제
	free(login.id);
	free(login.pw);
	free(id_chk); 
	free(pw_chk);
	return 0;
}


/*
	1. 파일 ID/PW -> 파일로부터 가져와서 변수로 저장 
	2. 입력 ID/PW -> 사용자로부터 입력받아서 변수로 저장 
	3. ID / PW 비교, 결과 출력 
*/

