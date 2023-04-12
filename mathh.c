//
//  mathh.c
//  datastructures chap 3 big exam 2
//
//  Created by 한설 on 2023/04/12.
//

#include "mathh.h"
#include "calcul.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


extern Element data[MAX_STACK_DATA];    //문자열 스택배열
extern double datacal[MAX_STACK_DATA];  //double형 스택배열
extern int top, topcal; //top -> 문자열, topcal -> double형


int check_matching(char expr[])
{
    int i = 0, prev;
    char ch;
    
    init_stack();   //스택 초기화
    while(expr[i] != '\0')  //문자열에서 \0이 출력되지 않을 때
    {
        ch = expr[i++]; //ch변수에 expr의 i번째 문자를 저장하고
        if(ch == '[' || ch == '{' || ch == '(') //저장된 문자가 대괄호, 중괄호, 소괄호의 왼쪽인 경우
            push(ch);   //스택에 push한다.
        else if( ch == ']' || ch == ')' || ch == '}') { //아니면 
            if(is_empty())  //스택이 비어있으면
                return 2;   //오른쪽 괄호가 먼저 나왔으므로 2번 조건에 위배
            prev = pop();   //스택에 저장된 괄호를 살펴봤는데
            if( (ch == ']' && prev != '[')  //대괄호끼리 매칭되지 않거나
               || (ch == ')' && prev != '(')    //소괄호끼리 매칭되지 않거나
               || (ch == '}' && prev != '{')) { //중괄호끼리 매칭되지 않는 경우
                return 3;   //다른 타입의 괄호를 혼용했으므로, 조건 3에 위배된다.
            }
        }
    }
    if( is_empty() == 0) return 1;  //스택이 비어있으면 왼쪽 괄오와 오른쪽 괄호의 개수가 다르므로 조건 1에 위배된다.
    return 0;   //정상
}

int precedence(char op)
{
    switch (op) {
        case '(' : case ')' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1;
}
double calc_postfix(char expr[]) //후위표기로 변환한 식을 스택을 이용해 계산
{
    char c;
    int i = 0;
    double val, val1, val2;
    
    init_stackcal();
    while(expr[i] != (void *)0)
    {
        c = expr[i++];
        if(c >= '0' && c <= '9')
        {
            val = c - '0';
            pushcal(val);
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/')
        {
            val2 = popcal();
            val1 = popcal();
            switch(c) {
                case '+': pushcal(val1 + val2); break;
                case '-': pushcal(val1 - val2); break;
                case '*': pushcal(val1 * val2); break;
                case '/': pushcal(val1 / val2); break;
            }
        }
    }
    return popcal();
}

void infix_to_postfix(char *expr)
{
    int i = 0, j = 0;
    char c, op, s1[80];
    
    init_stack();   //스택 초기화
    while (expr[i] != '\0') {   //문자열 i칸이 null이 아닐 때
        c = expr[i++];
        if((c >= '0' && c <= '9')) { //
            s1[j++] = c;
        }
        else if( c == '(')
            push(c);
        else if(c == ')') {
            while (is_empty() == 0) {
                op = pop();
                if(op == '(') break;
                else s1[j++] = op;
            }
        }
        else if( c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (is_empty() == 0) {
                op = peek();
                if(precedence(c) <= precedence(op)) {
                    s1[j++] = op;
                    pop();
                }
                else break;
            }
            push (c);
        }
    }
    while (is_empty() == 0)
        s1[j++] = pop();
    strcpy(expr, s1);
}

void inputchar(char str[])   //문자열을 사용자로부터 받기
{
    printf("수식을 입력해주세요.\n");
    fgets(str, 80, stdin);
}
