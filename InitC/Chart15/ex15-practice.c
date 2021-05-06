/*
	1. 5명 학생의 국어, 영어, 수학, 체육 점수 입력 (2차원 배열 사용)
	2. 개인별 총점과 평균
	3. 과목별의 총점과 평균
*/

#include <stdio.h>
#include "ex15.h"

int print() {
	printf("야호!");
	// return 1;
}


int main() {
	int grade[5][4] = { 0 };
	int sum_p[5] = { 0 }; // 학생별 합계
	int sum_s[4] = { 0 }; // 과목별 합계 
	
	int num = print();
	printf("%d", num);

	// 입력 
	input_grade(grade);
	// 총점 계산
	sum_person(grade, sum_p); 
	sum_subject(grade, sum_s);
	// 출력 
	// print_grade(grade);
	print_grade(grade, sum_p, sum_s);

	return 0;
}



