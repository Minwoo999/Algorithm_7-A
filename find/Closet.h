/*************************************
 프로그램명 : 최근접 쌍 찾기 문제
 실습일 : 2023.05.07
 개발자 : 김민우
**********************************/

#ifndef Closet_h
#define Closet_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _point {     //좌표 구조체
    int x;
    int y;
}Point;

//ADTs
Point *closet(Point *a, int left, int right, int n);       //최단 거리 점의 쌍의 주소 반환 함수
double distance(Point a, Point b);          //점 2개의 거리 반환 함수

//TestFunc
void TC1_TwoPoint(void);    //두개의 점
void TC2_TenPoint(void);    //열개의 점
void TC3_OddPoint(void);    //홀수개의 점
void TC4_Hunnitpoint(void); //100개의 점

#endif /* Closet_h */
