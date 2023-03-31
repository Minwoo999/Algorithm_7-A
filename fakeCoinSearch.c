#include <stdio.h>
#include <stdlib.h>

// 가짜 동전을 찾는 함수
int findFakeCoin(int left, int right, int coins[]) {

	// 저울에 동전을 올려서 양팔 저울의 균형을 맞춤
	int sumLeft = 0, sumRight = 0;
	int mid = (left + right) / 2;

	for (int i = left; i <= mid; i++) {
		sumLeft += coins[i];
	}

	for (int i = mid + 1; i <= right; i++) {
		sumRight += coins[i];
	}

	if (sumLeft < sumRight) {
		// 오른쪽 저울이 무거움
		if (left == right - 1) {
			// 가짜 동전을 찾음
			return right;
		}
		// 오른쪽 저울에서 가짜 동전을 찾음
		return findFakeCoin(mid + 1, right, coins);
	}
	else if (sumLeft > sumRight) {
		// 왼쪽 저울이 무거움
		if (left == right - 1) {
			// 가짜 동전을 찾음
			return left;
		}
		// 왼쪽 저울에서 가짜 동전을 찾음
		return findFakeCoin(left, mid, coins);
	}
	else {
		// 균형을 이룸
		if (left == right - 1) {
			// 가짜 동전을 찾음
			return -1; // 가짜 동전이 없는 경우를 -1로 처리
		}
		// 양쪽 저울에서 가짜 동전을 찾음
		return findFakeCoin(mid + 1, right, coins);
	}
}

int main() {
	int n;
	int fake;

	printf("동전의 개수를 입력하세요: ");
	scanf_s("%d", &n);
	int* coins = (int*)malloc(sizeof(int) * n); // 동적 메모리 할당

	for (int i = 0; i < n; i++) {
		printf("%d번 동전의 무게를 입력하세요: ", i + 1);
		scanf_s("%d", &coins[i]);
	}

	fake = findFakeCoin(0, n - 1, coins);
	if (fake == -1) {
		printf("가짜 동전이 없습니다.\n");
	}

	else {
		printf("가짜 동전은 %d번째 동전입니다.\n", fake + 1);
	}

	free(coins); // 동적 메모리 해제

	return 0;
}
