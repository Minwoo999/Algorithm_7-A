알고리즘 설계 구현 결과 1: <가장 큰 수 찾기>
<문제 정의>
문제 이름 : 최대 숫자 찾기
문제 설명 : 주어진 숫자 중 가장 큰 수를 찾는다.
문제 예시 : [45, 20, 35, 60, 55, 10, 90, 85, 25, 75]
->총 10개의 숫자 중 가장 큰 수는 90이다.

<해결 아이디어>
1) 김민우 :
임의의 카드를 선택, 차례로 비교하여 임의의 카드보다 크면 교체, 작으면 유지한다. 모든 카드에 대하여 반복한다.
2) 한준규 : 
카드를 2개씩 짝을 지어 큰 수만 취사선택한다. 1개가 남을 때까지 반복한다.
-> 두가지 경우 모두 시행 횟수는 8번으로 같으나, 2번의 경우에는 홀수 개수인 경우에는 알고리즘이 조금 더 복잡해진다. 그럼으로 1번을 선택하였다.

<알고리즘>
이름: 최대값 찾기(findMaxNumber)
입력: 숫자 목록
출력: 가장 큰 숫자
처리 순서:
1. 첫번째 카드 번호를 최대값으로 저장한다.
2. 두번째 카드를 최대값과 비교 후, 두번째 카드가 더 크면 두번째 카드를 최대값으로 저장한다.
3. 나머지 카드에 2번을 반복한다.
4. 가장 큰 값을 반환한다.
 
<코드 설계>
1. 자료 구조 정의
- 가장 큰 숫자: max (int) - 정수
- 숫자 목록: NumArray (int []) - 정수 배열

2. 함수 정의
기능 : 정수 배열을 입력 받고 비교하여 가장 큰 수를 출력
프로토타입: int findMaxNumber(int NumArray[], int countc

3. 테스트 케이스 설계
: 임의의 숫자의 정수 배열을 선언, 위의 함수를 호출 후 최대값을 반환 후 출력
<C코드 구현 결과>

// 버전 1
int findMaxNumber(int NumArray[], int count) // 최대값 구하는 함수, 배열과 크기를 입력 받음
{
    int max = NumArray[0]; // 처음 숫자를 max에 저장

    }

    return max;
}

// 버전 2
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

TC)
int main()

{
    int NumArray[] = { 45, 20, 35, 60, 55, 10, 90, 85, 25, 75 }; // 임의의 숫자 배열
    int count = sizeof(NumArray) / sizeof(NumArray[0]); 
    int max = findMaxNumber(NumArray, count);

    printf("최대값은 %d입니다.\n", max);


    return 0;
}
