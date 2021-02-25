#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main_random(void) {
	/* srand(time(NULL)); // 난수 초기화
	int i = rand() % 3 + 1 ;
	if (i == 1) {
		printf("가위\n");
	}
	else if (i == 2) {
		printf("바위\n");
	}
	else if (i == 3) {
		printf("보\n");
	}
	return 0; */

	// Up and Down 프로젝트
	srand(time(NULL));
	int num = rand() % 100 + 1;
	printf("숫자: %d\n", num);
	int answer = 0;
	int chance = 5;
	while (1) {
		printf("남은기회 %d 번 \n", chance--);
		printf("숫자를 맞춰보세요(1~100) : ");
		scanf_s("%d", &answer);

		if (answer > num) {
			printf("DOWN \n\n");
		}
		else if (answer < num) {
			printf("UP \n\n");
		}
		else if (answer == num) {
			printf("정답입니다 \n\n");
			break;
		}
		else {
			printf("알수없는 오류발생\n\n");
		}
		if (chance == 0) {
			printf("찬스를 다사용하셨어요");
			break;
		}
	}
	return 0;
}