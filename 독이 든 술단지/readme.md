알고리즘 설계 구현 결과 : <독이 든 술단지>
 
<문제 정의>
문제이름: 독이 든 술단지를 찾기
문제설명: 독이 든 술단지를 가능한 최소한의 인원으로 단기간에 찾아낸다.
문제예시: 8개의 술단지에 필요한 인원은 3명이다.
 
<해결 아이디어>
1) 한설
이진탐색을 활용해 술단지를 반반 나눠가며 확인한다.
2) 한준규
마신 경우를 1 마시지 않은 경우를 0이라고 하자. 술단지에 0과 1을 겹치지 않도록 각각 채워넣었다. 남는 술단지가 생길때마다 칸을 늘리면서 넣는다.
ex) 0과 1로는 전부 표현이 안되면 00, 01, 10, 11로 표현.
반복한 후 모든 술단지가 커버되었을 때 필요한 칸이 최소 몇개인지 센다.
식으로 표현하면 (술단지의 수) <= 2^(사람의 수)에서 사람수의 최솟값.
-> 의논한 결과 더 낮은 복잡도로 적용되는 아이디어 2을 채택.
 
<알고리즘>
명칭: 독이든 술단지 찾기(find_poison)
입력: 술단지의 개수
출력: 찾는 과정에서 최소로 필요한 사람의 수
처리순서:
1. 술단지의 개수를 alcohol에 저장
2. log2(alcohol)을 계산한 값을 sin변수에 저장
3. sin에 1을 더한 값이 소수점을 뺀 sin에 1을 더한 값보다 큰 경우 1을 더해준다.
4. 소수점을 뺀 sin값 반환

<코드 설계>
1. 자료 구조 정의
- 술단지의 개수 : alcohol
- 사람의 수 : sin
 
2. 함수 정의
- 기능 : 술단지의 개수(alcohol)을 입력받아 필요한 사람수의 최솟값 출력
- 프로토타입: int find_poison(int alcohol)
3. 테스트 케이스 설계
TC1. 임의의 술단지의 수를 함수로 보내 최소 필요한 사람의 수를 반환받아 출력한다.
TC2. 딱 떨어지지 않는 수를 함수로 보내 TC1과 동일하게 테스트한다.
 
<C코드 구현 결과>
// 버전 1
/*
int find_poison(int alcohol)
{
double sin = 0;
return (int)sin;
}
*/
 
// 버전 2
int find_poison(int alcohol)
{
double sin = 0;
 
//2. log2(alcohol)을 계산한 값을 sin변수에 저장
sin = log2(alcohol);
 
//3. sin에 1을 더한 값이 소수점을 뺀 sin에 1을 더한 값보다 큰 경우 1을 더해준다.
if (sin + 1 > (int)sin + 1)
sin += 1;
 
//4. sin에서 소수점을 뺀 값 반환
return (int)sin;
}
 
 
// TC1: 테스트 코드1
// 임의의 술단지의 수를 함수로 보내 최소 필요한 사람의 수를 반환받아 출력한다.
int TC1_find_poison(void)
{
int alcohol, sin;
alcohol = 8;
sin = find_poison(alcohol);
printf("Need %d person\n", sin);
if (sin == 3)
return 0; //성공
else
return -1; //실패
}
 
// TC2: 테스트 코드2
// 딱 떨어지지 않는 수를 함수로 보내 TC1과 동일하게 테스트한다.
int TC2_find_poison(void)
{
int alcohol, sin;
alcohol = 9;
sin = find_poison(alcohol);
printf("Need %d person\n", sin);
if (sin == 4)
return 0; //성공
else
return -1; //실패
}
 
int main(int argc, char * argv[])
{
test1_findMaxNumber();
test2_findMaxNumber();
}
