/*************************************
 프로그램명 : 최근접 쌍 찾기 문제
 실습일 : 2023.05.07
 개발자 : 김민우
**********************************/

#include "Closet.h"
#define MAX_CHAR_PER_LINE 30


static void filesave(Point *a, char *name);        //파일 저장
static Point *filelead(char *name, int *n);        //파일 읽기
static int compare(const void *a, const void *b);  //비교함수

void TC1_TwoPoint(void)     //2개의 점일 때
{
    printf("\n=================TC1 TwoPoint=================\n");
    Point *arr = NULL, *res = NULL;
    int n = 0; //n은 점의 개수를 표현
    arr = filelead("test1.txt", &n);
    
    for(int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    if (n < 2)
    {
        printf("점의 갯수가 부족합니다.");
        exit(1);
    }
    printf("n: %d\n", n);
    qsort(arr, n, sizeof(Point), compare);  //정렬
    printf("\n");
    printf("정렬 후 \n");
    for(int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    printf("\n");
    
    res = closet(arr, 0, n - 1, n);
    
    printf("최단 점의 쌍은 %d %d와 %d %d입니다.\n", res[0].x, res[0].y, res[1].x, res[1].y);
    printf("거리는 %.3lf", distance(res[0], res[1]));
    filesave(res, "result1.txt");
}

void TC2_TenPoint(void)     //10개의 점일 때
{
    printf("\n=================TC2 TenPoint=================\n");
    Point *arr = NULL, *res = NULL;
    int n = 0; //n은 점의 개수를 표현
    arr = filelead("test2.txt", &n);
    
    for(int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    if (n < 2)
    {
        printf("점의 갯수가 부족합니다.");
        exit(1);
    }
    printf("n: %d\n", n);
    qsort(arr, n, sizeof(Point), compare);  //정렬
    printf("\n");
    printf("정렬 후 \n");
    for(int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    printf("\n");
    
    res = closet(arr, 0, n - 1, n);
    
    printf("최단 점의 쌍은 %d %d와 %d %d입니다.\n", res[0].x, res[0].y, res[1].x, res[1].y);
    printf("거리는 %.3lf", distance(res[0], res[1]));
    filesave(res, "result2.txt");
}

void TC3_OddPoint(void)     //홀수갯수의 점일 때 (11개)
{
    printf("\n=================TC3 OddPoint=================\n");
    Point *arr = NULL, *res = NULL;
    int n = 0; //n은 점의 개수를 표현
    arr = filelead("test3.txt", &n);
    
    for(int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    if (n < 2)
    {
        printf("점의 갯수가 부족합니다.");
        exit(1);
    }
    printf("n: %d\n", n);
    qsort(arr, n, sizeof(Point), compare);  //정렬
    printf("\n");
    printf("정렬 후 \n");
    for(int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    printf("\n");
    
    res = closet(arr, 0, n - 1, n);
    
    printf("최단 점의 쌍은 %d %d와 %d %d입니다.\n", res[0].x, res[0].y, res[1].x, res[1].y);
    printf("거리는 %.3lf", distance(res[0], res[1]));
    filesave(res, "result3.txt");
}

void TC4_Hunnitpoint(void)      //100개의 점일 때
{
    printf("\n=================TC4 HunnitPoint=================\n");
    Point *arr = NULL, *res = NULL;
    int n = 0; //n은 점의 개수를 표현
    arr = filelead("test4.txt", &n);
    
    for(int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    if (n < 2)
    {
        printf("점의 갯수가 부족합니다.");
        exit(1);
    }
    printf("n: %d\n", n);
    qsort(arr, n, sizeof(Point), compare);  //정렬
    printf("\n");
    printf("정렬 후 \n");
    for(int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
    printf("\n");
    
    res = closet(arr, 0, n - 1, n);
    
    printf("최단 점의 쌍은 %d %d와 %d %d입니다.\n", res[0].x, res[0].y, res[1].x, res[1].y);
    printf("거리는 %.3lf", distance(res[0], res[1]));
    filesave(res, "result4.txt");
}

Point *filelead(char *name, int *n)
{
    int count = 1;
    char str[10], *x, *y;
    Point point, *arr;                              //point구조체 선언
    FILE *fp;                                   //파일 포인터
    fp = fopen(name, "r");                          //파일 읽기
    arr = (Point*)malloc(sizeof(Point) * 3);        //3칸 메모리 할당
    if (fp == NULL) {
        printf("파일이 없습니다.\n");
        exit(1);
    }
    else if(fp != NULL) {
        while(fgets(str, MAX_CHAR_PER_LINE, fp))    //한줄씩 읽어들이고
        {
            if ((*n % 3) == 0 && !(*n == 0)) {      //n을 3으로 나눴을 때 나머지가 없고, (3의 배수) n이 0이 아닐 때
                count += 1; //count를 1 늘리고
                arr = realloc(arr, sizeof(Point) * (count * 3));    //초기값이 3칸이므로 조건을 처음 만족했을 때 6칸 다음은 9칸. 3의 배수로 칸을 늘려간다.
            }
            x = strtok(str, " ");                   //공백기준 토큰화
            y = strtok(NULL, " ");                  //공백기준 토큰화
            point.x = atoi(x);                      //Ascii형태 int형으로 형변환
            point.y = atoi(y);                      //Ascii형태 int형으로 형변환
            *(arr + *n) = point;                    //arr배열의 n번째 칸에 point 대입
            *n = *n + 1;                            //반복할때마다 +1 (점의 개수 파악)
        }
        fclose(fp);
    }
    return arr;
}

void filesave(Point *a, char *name)
{
    char x1[6], y1[6], x2[6], y2[6];
    sprintf(x1,"%d", (a + 0) -> x); //int형을 문자열로 형변환.
    sprintf(y1,"%d", (a + 0) -> y);
    sprintf(x2,"%d", (a + 1) -> x);
    sprintf(y2,"%d", (a + 1) -> y);
    FILE *fp = fopen(name, "w");    //파일 쓰기 모드로 open
    if (fp != NULL) {
        fprintf(fp, "%s %s \n", x1, y1);   //파일에 입력
        fprintf(fp, "%s %s", x2, y2);   //파일에 입력
    }
    fclose(fp); //파일 닫기
}

int compare(const void *a, const void *b)
{
    Point num1 = *(Point *)a;   //구조체 a 기입
    Point num2 = *(Point *)b;   //구조체 b 기입
    
    if (num1.x < num2.x)    //num2(b)의 x값이 더 큰 경우
        return -1;
    
    if (num1.x > num2.x)    //num1(a)의 x값이 더 큰 경우
        return 1;
    
    return 0;               //같을 경우
}
