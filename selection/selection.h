/*************************************
 프로그램명 : 분할 정복 알고리즘
 실습일 : 2023.05.07
 개발자 : 김민우
**********************************/

#ifndef selection_h
#define selection_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int selection(int *arr, int l, int r, int k, int n);
int *filelead(char *name, int *n);
void filesave(char *name, int a);

#endif /* selection_h */
