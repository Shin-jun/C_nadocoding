#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main_random(void) {
	/* srand(time(NULL)); // ���� �ʱ�ȭ
	int i = rand() % 3 + 1 ;
	if (i == 1) {
		printf("����\n");
	}
	else if (i == 2) {
		printf("����\n");
	}
	else if (i == 3) {
		printf("��\n");
	}
	return 0; */

	// Up and Down ������Ʈ
	srand(time(NULL));
	int num = rand() % 100 + 1;
	printf("����: %d\n", num);
	int answer = 0;
	int chance = 5;
	while (1) {
		printf("������ȸ %d �� \n", chance--);
		printf("���ڸ� ���纸����(1~100) : ");
		scanf_s("%d", &answer);

		if (answer > num) {
			printf("DOWN \n\n");
		}
		else if (answer < num) {
			printf("UP \n\n");
		}
		else if (answer == num) {
			printf("�����Դϴ� \n\n");
			break;
		}
		else {
			printf("�˼����� �����߻�\n\n");
		}
		if (chance == 0) {
			printf("������ �ٻ���ϼ̾��");
			break;
		}
	}
	return 0;
}