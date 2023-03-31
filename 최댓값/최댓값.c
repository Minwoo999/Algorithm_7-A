/**********************
프로그램명 : 최대값 찾기 알고리즘
프로그램 내용 : 배열에서 숫자를 입력 받고 최댓값을 출력
실습일 : 2023.03.31
개발자 : 김민우 (201810198), 한준규 (201811706), 한  설 (201911695 

**********************/



#include <stdio.h>


int findMaxNumber(int NumArray[], int count) // 최대값 구하는 함수, 배열과 크기를 입력 받음
{
    int max = NumArray[0]; // 처음 숫자를 max에 저장

    for (int i = 1; i < count; i++) {
        if (NumArray[i] > max) {   
            max = NumArray[i];   // 현재값이 max보다 크면 max 교체
        }
    }

    return max;
}

int main()

{
    int NumArray[] = { 45, 20, 35, 60, 55, 10, 90, 85, 25, 75 }; // 임의의 숫자 배열
    int count = sizeof(NumArray) / sizeof(NumArray[0]); 
    int max = findMaxNumber(NumArray, count);

    printf("최대값은 %d입니다.\n", max);


    return 0;
}
