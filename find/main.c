
/*************************************
 프로그램명 : 최근접 쌍 찾기 문제
 실습일 : 2023.05.07
 개발자 : 김민우
**********************************/

#include "Closet.h"
#include <time.h>

static void checktime(void(*func)(void));          //시간 체크

int main(int argc, const char * argv[]) {
    checktime(TC1_TwoPoint);
    checktime(TC2_TenPoint);
    checktime(TC3_OddPoint);
    checktime(TC4_Hunnitpoint);
    return 0;
}

void checktime(void(*func)(void))   //실행시간 체크
{
    clock_t start, finish;
    double duration;
    start = clock();
    (*func)();
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("\n================%lf초입니다.================\n", duration);
}
