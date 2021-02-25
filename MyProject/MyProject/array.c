#include <stdio.h>
#include <time.h>

int main_array(void) {
	srand(time(NULL));
	printf("\n\n === 아빠는 대머리 게임 ===\n\n");
	int answer;
	int treatment = rand() % 4;	// 발모제 선택(0~3)

	int cntShowBottle = 0;	// 이번게임에 보여줄 병 갯수
	int pervCntShowBottle = 0; // 앞 게임에 보여준 병 갯수
	// 서로 보여주는 병 갯수를 다르게 하여 정답률 향상(처음에 2개-> 다음에 3개)

	// 3번의 기회
	for (int i = 1; i <= 3; i++) {
		int bottle[4] = { 0, 0, 0, 0 };	//4개의 병
		do {
			cntShowBottle = rand() % 2 + 2; // 보여줄 병갯수(0~1, +2 -> 2,3)
		} while (cntShowBottle == pervCntShowBottle);
		pervCntShowBottle = cntShowBottle;

		int isInclueded = 0; // 보여줄 병 중에 발모제가 포함되었는지 여부
		printf(" > %d 번째 시도: ", i);

		// 보여줄 병 종류를 선택
		for (int j = 0; j < cntShowBottle; j++) {
			int randBottle = rand() % 4;

			// 아직 선택되지 않은 병이면, 선택 처리
			if (bottle[randBottle] == 0) {
				bottle[randBottle] = 1;
				if (randBottle == treatment) {
					isInclueded = 1;
				}
			}
			// 이미 선택된 병이면, 중복이므로 다시선택
			else {
				j--;
			}
		}
		// 사용자에게 문제 표시
		for (int k = 0; k < 4; k++) {
			if (bottle[k] == 1) {
				printf("%d", k + 1);
			}
		}
		printf("물약을 머리에 바릅니다\n\n");
		if (isInclueded == 1) {
			printf("성공 머리가 났어요\n");
		}
		else {
			printf("실패 머리가 나지 않았어요\n");
		}
		printf("\n.. 게쏙하려면 아무키나 누르세요");
		getchar();
	}
	printf("\n\n발모제는 몇번일까요?");
	scanf_s("%d", &answer);
	if (answer == treatment + 1) {
		printf("\n정답입니다\n");
	}
	else {
		printf("\n 땡 틀렸어요 정답은 %d입니다", treatment+1);
	}
	return 0;
}