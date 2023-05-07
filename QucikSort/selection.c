/*************************************
 프로그램명 : 퀵 정
 실습일 : 2023.05.07
 개발자 : 김민우
**********************************/

#include "selection.h"

static int median(int *arr, int l, int r);          //왼쪽, 중간, 오른쪽에서 각각의 값을 받아 중간값을 출력하는 함수
static int median_of_medians(int *arr, int l, int r);   //median을 왼쪽 오른쪽 중간 3분할로 수행하는 함수.
static void swap (int *a, int *b);                  //자리바꿈 함수

int selection(int *arr, int l, int r, int k, int n)
{
    int pivot;
    int i, j;
    
    if (l >= r) {
        return *(arr + r);
    }
    
    //pivot 설정
    pivot = median_of_medians(arr, l, r);
    printf("pivot: %d\n", pivot);
    
    //pivot과 가장 앞 원소 위치 변환
    swap((arr + l), (arr + pivot));
    pivot = l;
    i = l + 1;
    j = r;
    printf("k : %d\n", k);
    while(i <= j){
        while (i <= r && arr[i] <= arr[pivot])   //왼쪽에서 오른쪽으로 가는데, pivot값보다 큰값 나타나면 정지.
            i++;
        
        while (j > l && arr[j] > arr[pivot])     //오른쪽에서 왼쪽으로 가는데, pivot값보다 작은 값 나타나면 정지.
            j--;
        
        if(i > j){                              //교차했을 경우. (pivot 위치를 제외하곤 문제 없는 상황)
            swap(arr + j, arr + pivot);         //pivot만 올바른 위치로 이동 (j가 오른쪽에서부터 pivot보다 작은 값을 찾으며 왔으므로. j가 멈춘 곳은 pivot이 위치했을 때, 왼쪽에 작은값, 오른쪽엔 큰 값이 있다.)
        }
        else{                                   //교차하지 않았을 경우.
            swap(arr + i, arr + j);             //위치 서로 변환.
        }
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    if (j < k) {                                //피벗 기준 오른쪽에 위치한 경우
        printf("right\n");
        return selection(arr, j + 1, r, k, n);
    }
    else if (j == k)                            //피벗과 찾는 값이 동일한 경우
        return arr[j];
    
    else                                        //피벗 기준 왼쪽에 위치한 경우
        printf("left\n");
        return selection(arr, l, j - 1, k, n);
}

void swap (int *a, int *b)      //자리바꿈 함수
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int median(int *arr, int l, int r)
{
    int m = (r + l) / 2;
    if (*(arr + l) > *(arr +r))              //l > r
    {
        if (*(arr + l) < *(arr + m))          //m > l > r
            return l;
        else {              //l > r, m <= l
            if(*(arr + m) > *(arr + r))       //r < m <= l
                return m;
            else            //m <= r <= l
                return r;
        }
    }
    else {              //l <= r
        if (*(arr + l) > *(arr + m))      //m < l <= r
            return l;
        else {          //r >= l, m >= l
            if (*(arr + m) < *(arr + r))  //r > m >= l
                return m;
            else        //m >= r >= l
                return r;
        }
    }
}

int median_of_medians(int *arr, int l, int r)
{
    int left, right, mid;
    left = median(arr, l, (r - l) / 3 + l);
    mid = median(arr, (r - l) / 3 + l + 1, (((r - l) / 3 * 2) + l));
    right = median(arr, (((r - l) / 3 * 2) + l) + 1, r);
    if (*(arr + left) > *(arr + right))              //l > r
    {
        if (*(arr + left) < *(arr + mid))          //m > l > r
            return left;
        else {              //l > r, m <= l
            if(*(arr + mid) > *(arr + right))       //r < m <= l
                return mid;
            else            //m <= r <= l
                return right;
        }
    }
    else {              //l <= r
        if (*(arr + left) > *(arr + mid))      //m < l <= r
            return left;
        else {          //r >= l, m >= l
            if (*(arr + mid) < *(arr + right))  //r > m >= l
                return mid;
            else        //m >= r >= l
                return right;
        }
    }
}
