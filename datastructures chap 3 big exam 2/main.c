//
//  main.c
//  datastructures chap 3 big exam 2
//
//  Created by 한설 on 2023/04/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mathh.h"

Element data[MAX_STACK_DATA];   //문자열 스택
double datacal[MAX_STACK_DATA]; //double형 스택
int top, topcal;

int main(int argc, const char * argv[]) {
    
    char *expr = NULL;
    int errcode;
    expr =(char*)malloc(sizeof(char) * 80); //메모리 할당
    
    inputchar(expr); //키보드로 수식 입력 받기
    
    printf("\n");
    printf("입력받은 수식: %s", expr); //수식 출력
    
    errcode = check_matching(expr); //괄호 검사
        
    if(errcode == 0) {
        printf("정상: %s", expr);
        infix_to_postfix(expr); //후위표기 변환
        printf("후위표기: %s", expr);
        printf("\n계산값: %lf", calc_postfix(expr));   //후위표기식 계산 및 출력
    }
    else
        printf("오류: %s (%d항목에 위배)", expr, errcode); //괄호검사 실패시 출력
    return 0;
}

void error(char msg[])
{
    printf("%s", msg);
    exit(1);
}


//Element(문자열) STACK ADTs
void init_stack(void) {top = -1;}
int is_empty(void) {return top == -1;}
int is_full(void) {return top == MAX_STACK_DATA - 1;}
int size(void) {return top + 1;}

Element pop(void) {
    if (is_empty())
        error("스택 공백 에러");
    return data[top--];
}

Element peek(void) {
    if (is_empty())
        error("스택 공백 에러");
    return data[top];
}

void push(int a) {
    if (is_full())
        error("스택 포화 에러");
    data[++top] = a;
}

//double STACK ADTs
void init_stackcal(void) {topcal = -1;}
int is_emptycal(void) {return topcal == -1;}
int is_fullcal(void) {return topcal == MAX_STACK_DATA - 1;}
int sizecal(void) {return topcal + 1;}

double popcal(void) {
    if (is_emptycal())
        error("스택 공백 에러");
    return datacal[topcal--];
}

double peekcal(void) {
    if (is_emptycal())
        error("스택 공백 에러");
    return datacal[topcal];
}

void pushcal(int a) {
    if (is_fullcal())
        error("스택 포화 에러");
    datacal[++topcal] = a;
}
