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

Element data[MAX_STACK_DATA];
int top;

int main(int argc, const char * argv[]) {
    
    char *expr = NULL;
    int i, errcode;
    expr =(char*)malloc(sizeof(char) * 80);
    
    for (i = 0; i < 4; i++)
        inputchar(expr); //키보드로 수식 입력 받기
    
    printf("\n");
    printf("입력받은 수식: %s", expr); //수식 출력
    
    for(i = 0; i < 4; i++) {
        errcode = check_matching(expr);
        
        if(errcode == 0)
            printf("정상: %s", expr);
        else
            printf("오류: %s (%d에 위배)", expr, errcode);
    }

    return 0;
}

void error(char msg[])
{
    printf("%s", msg);
    exit(1);
}


//STACK ADTs
void init_stack(void) {top = -1;}
int is_empty(void) {return top == -1;}
int is_full(void) {return top == MAX_STACK_DATA - 1;}
int size(void) {return top + 1;}

int pop(void) {
    if (is_empty())
        error("스택 공백 에러");
    return data[top--];
}

int peek(void) {
    if (is_empty())
        error("스택 공백 에러");
    return data[top];
}

void push(int a) {
    if (is_full())
        error("스택 포화 에러");
    data[++top] = a;
}

