#include <stdio.h>

struct vision {
	double left;
	double right;
};

void exchange(struct vision*);


int main() {
	struct vision robot;
	struct vision* pr = &robot;
	printf("시력 입력 : ");
	
	scanf_s("%lf%lf", &(robot.left), &(robot.right));
	// scanf_s("%lf%lf", &(pr->left), &(pr->right));
	// robot = exchange(robot);
	exchange(pr);
	printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);

	return 0;
}

void exchange(struct vision* robot) {
	double tmp;

	tmp = robot->left;
	robot->left = robot->right;
	robot->right = tmp;

	
	return robot;
}

