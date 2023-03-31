/**********************
프로그램명 :거스름돈으로 받는 동전의 최소 개수
프로그램 내용 : 금액을 입력받고 최소 동전 개수 출력
실습일 : 2023.03.31
개발자 : 김민우 (201810198), 한준규(201811706), 한설(201911695)
**********************/



#include <stdio.h>


int change (int coins[], int amount, int length)
{
    int count = 0; // 총 동전 개수

    for (int i = 0; i < length; i++) { // 사용 가능한 동전 모두에 대한 시행
        while (amount >= coins[i]) { // 동전 값을 뺄 수 있는지 확인
            amount -= coins[i]; // 남은 금액에서 동전 값을 뺌
            count++; // 동전 개수 +1
        }
    }

    return count;
}

int main()
{
    int coins[] = { 500, 100, 50, 10 }; // 동전의 종류
    int amount = 730; // 거스름돈

    int count = change (coins, amount, 4); // 동전 개수 계산

    printf("최소한의 동전 수: %d\n", count);

    return 0;
}
