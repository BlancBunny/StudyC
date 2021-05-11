/*
	ex_login.c
	�޸��� ��� 
	1. id�� pw ����, ���� �̸��� login.txt
	2. struct login �� id�� password ����� ���� 
	3. Ű����� �ԷµǴ� id�� pw�� ���Ͽ� 
	������ �α��� ���� ���� ��� / �ٸ��� ���� ���� ��� 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct login {
	char* id; // ���� ID 
	char* pw; // ���� PW
}Login;

int main() {
	FILE* fp;
	Login login;
	int res;
	char tmp[80]; // ���� �Ҵ�� �ӽ� ���� 
	char tmp_pw[80];
	char* id_chk, * pw_chk; // �Է� ID, �Է� PW

	// ���� ����
	errno_t err = fopen_s(&fp, "login.txt", "r"); 
	if (err == 0) {
		printf("File is Opened!\n");
	}
	else {
		printf("File is not Opened!\n");
		return 1;
	}
	
	// ���Ϸκ��� ID/PW ���� 
	while (1) { 
		if (fp) {
			res = fscanf_s(fp, "%s%s", tmp, sizeof(tmp), tmp_pw, sizeof(tmp_pw)); // 1�� �б� 
			if (res == EOF) break;
		}
	}
	fclose(fp); // ���� ���� ���� 

	// ���ڿ��� 0���� ������ ���� �� ���� (�����δ� 0���� ����..) 
	strcat_s(tmp, sizeof(tmp), ""); 
	strcat_s(tmp_pw, sizeof(tmp_pw),""); 

	// ���� ID/PW �޸� �����Ҵ�
	login.id = (char*)malloc(strlen(tmp) + 1);
	if (login.id != NULL) 
		strcpy_s(login.id, strlen(tmp) + 1, tmp);
	login.pw = (char*)malloc(strlen(tmp_pw) + 1);
	if (login.pw != NULL) 
		strcpy_s(login.pw, strlen(tmp_pw) + 1, tmp_pw);
	
	// ID/PW �Է�, �޸� �����Ҵ�
	printf("���̵� �Է� : "); 
	gets_s(tmp, sizeof(tmp));
	id_chk = (char*)malloc(strlen(tmp) + 1); 
	if (id_chk != NULL) 
		strcpy_s(id_chk, strlen(tmp)+1, tmp); 
	printf("��й�ȣ �Է� : ");
	gets_s(tmp, sizeof(tmp));
	pw_chk = (char*)malloc(strlen(tmp) + 1); 
	if (pw_chk != NULL) 
		strcpy_s(pw_chk, strlen(tmp)+1, tmp);

	// �α��� �˻�
	if (id_chk && pw_chk && login.id && login.pw != NULL) {
		if (strcmp(login.id, id_chk) == 0 && strcmp(login.pw, pw_chk) == 0) {
			printf("�α��εǾ����ϴ�.\n");
		}
		else printf("ID/PW�� ã�� �� �����ϴ�.\n");
	}
	
	// �޸� �Ҵ� ����
	free(login.id);
	free(login.pw);
	free(id_chk); 
	free(pw_chk);
	return 0;
}


/*
	1. ���� ID/PW -> ���Ϸκ��� �����ͼ� ������ ���� 
	2. �Է� ID/PW -> ����ڷκ��� �Է¹޾Ƽ� ������ ���� 
	3. ID / PW ��, ��� ��� 
*/

