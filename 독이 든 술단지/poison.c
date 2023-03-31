// 알고리즘 1장 7번 문제
// 독이 든 술단지


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int find_poison(int alcohol);
int TC1_find_poison(void);
int TC2_find_poison(void);

int main(int argc, const char * argv[]) {
    printf("TC1: %d\n", TC1_find_poison());
    printf("TC2: %d\n", TC2_find_poison());
    return 0;
}

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

/*
int find_poison(int alcohol)
{
    double sin = 0;
    
    return (int)sin;
}
*/

int find_poison(int alcohol){
    double sin = 0;
    //2. log2(alcohol)을 계산한 값을 sin변수에 저장
    sin = log2(alcohol);
    //3. sin에 1을 더한 값이 소수점을 뺀 sin에 1을 더한 값보다 큰 경우 1을 더해준다.
    if (sin + 1 > (int)sin + 1)
        sin += 1;
    //4. sin에서 소수점을 뺀 값 반환
    return (int)sin;
}
