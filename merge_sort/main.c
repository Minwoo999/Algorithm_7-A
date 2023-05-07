/*************************************
 프로그램명 : 합병 정렬
 실습일 : 2023.05.07
 개발자 : 김민우
**********************************/

#include "merge.h"
#include <string.h>
#include <time.h>

static void checktime(void(*func)(void));

int main(int argc, const char * argv[]) {
    checktime(TC1_Tennumber);
    checktime(TC2_Twentyonenumber);
    checktime(TC3_hundrednumber);
    return 0;
}

void checktime(void(*func)(void))
{
    clock_t start, finish;
    double duration;
    start = clock();
    (*func)();
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("\n================%lf초입니다.================\n", duration);
}
Footer
© 2023 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
