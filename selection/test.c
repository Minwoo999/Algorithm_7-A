/*************************************
 프로그램명 : 퀵 정렬
 실습일 : 2023.05.07
 개발자 : 김민우
**********************************


#include "selection.h"

#define MAX_CHAR_PER_LINE 100

void TC1_Tennumber(void)
{
    printf("TC1_Tennumber: \n");
    int *arr, res;
    int n = 0, k;
    arr = filelead("data1.txt", &n);
    while(1) {
        printf("몇번째 작은 원소를 찾으시겠습니까? ");
        scanf("%d", &k);
        if (k > n || k <= 0)
            printf("잘못 입력하셨습니다. 다시 입력해주세요. \n");
        else
            break;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    res = selection(arr, 0, n - 1, k - 1, n);
    printf("결과: %d \n", res);
    filesave("result1.txt", res);
}

void TC2_Twentyonenumber(void)
{
    printf("TC2_Twentyonenumber: \n");
    int *arr, res;
    int n = 0, k;
    arr = filelead("data2.txt", &n);
    while(1) {
        printf("몇번째 작은 원소를 찾으시겠습니까? ");
        scanf("%d", &k);
        if (k > n || k <= 0)
            printf("잘못 입력하셨습니다. 다시 입력해주세요. \n");
        else
            break;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    res = selection(arr, 0, n - 1, k - 1, n);
    printf("결과: %d \n", res);
    filesave("result2.txt", res);
}

void TC3_hundrednumber(void)
{
    printf("TC2_hundrednumber: \n");
    int *arr, res;
    int n = 0, k;
    arr = filelead("data3.txt", &n);
    while(1) {
        printf("몇번째 작은 원소를 찾으시겠습니까? ");
        scanf("%d", &k);
        if (k > n || k <= 0)
            printf("잘못 입력하셨습니다. 다시 입력해주세요. \n");
        else
            break;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    res = selection(arr, 0, n - 1, k - 1, n);
    printf("결과: %d \n", res);
    filesave("result3.txt", res);
}

int *filelead(char *name, int *n)
{
    int count = 1;
    char str[100], *a;
    int num, *arr;
    FILE *fp;                                   //파일 포인터
    fp = fopen(name, "r");                          //파일 읽기
    arr = (int*)malloc(sizeof(int) * 3);        //3칸 메모리 할당
    if (fp == NULL) {
        printf("파일이 없습니다.\n");
        exit(1);
    }
    else if(fp != NULL) {
        while(fgets(str, MAX_CHAR_PER_LINE, fp)) {    //한줄씩 읽어들이고
            a = strtok(str, " ");
            while (a != NULL) {
                if ((*n % 3) == 0 && !(*n == 0)) {      //n을 3으로 나눴을 때 나머지가 없고, (3의 배수) n이 0이 아닐 때
                    count += 1; //count를 1 늘리고
                    arr = realloc(arr, sizeof(int) * (count * 3));    //초기값이 3칸이므로 조건을 처음 만족했을 때 6칸 다음은 9칸. 3의 배수로 칸을 늘려간다.
                }
                num = atoi(a);                      //Ascii형태 int형으로 형변환
                *(arr + *n) = num;                    //arr배열의 n번째 칸에 point 대입
                *n = *n + 1;                            //반복할때마다 +1 (숫자 개수 파악)
                a = strtok(NULL, " ");                   //공백기준 토큰화
            }
        }
        fclose(fp);
    }
    return arr;
}

void filesave(char *name, int a)
{
    char ia[10];
    sprintf(ia, "%d", a);
    FILE *fp = fopen(name, "w");    //파일 쓰기 모드로 open
        fputs(ia, fp);
    fclose(fp); //파일 닫기
}
