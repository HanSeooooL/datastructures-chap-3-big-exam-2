//
//  mathh.c
//  datastructures chap 3 big exam 2
//
//  Created by 한설 on 2023/04/12.
//

#include "mathh.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>




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
            if(is_empty())
                return 2;
            prev = pop();
            if( (ch == ']' && prev != '[')
               || (ch == ')' && prev != '(')
               || (ch == '}' && prev != '{')) {
                return 3;
            }
        }
    }
    if( is_empty() == 0) return 1;
    return 0;
}

double calc_postfix(char *expr) //후위표기로 변환
{
    char c;
    int i = 0;
    double val, val1, val2;
    
    init_stack();
    while(expr != (void *)0)
    {
        c = expr[i++];
        if(c >= '0' && c <= '9')
        {
            val = c - '0';
            push(val);
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/')
        {
            val2 = pop();
            val1 = pop();
            switch(c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}


void inputchar(char str[])   //문자열을 사용자로부터 받기
{
    printf("수식을 입력해주세요.\n");
    fgets(str, 80, stdin);
}
