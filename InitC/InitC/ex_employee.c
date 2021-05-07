/*
	5명의 사원아이디, 사원이름, 한달 급여를 입력받아 출력한 뒤
	5명 사원의 급여 총액과 평균 급여액을 구하시오. 
	(이름은 동적할당)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ex_employee.h"


int main() {
	
	Employee list[_SIZE];
	Employee* pl = list;
	
	// 1. 사원 5명의 아이디/이름/급여 입력 
	input_Employee(list);
	// 2. 출력
	print_Employee(list);
	// 2.5 이름 메모리 반환
	for (int i = 0; i < _SIZE; i++) {
		if (list[i].name != NULL) {
			free(list[i].name);
			list[i].name = NULL;
		}
	}
	// 3. 급여 총액 / 평균 
	print_salary(list);
	
	return 0;
}


