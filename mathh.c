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
    
    init_stack();
    while(expr[i] != '\0')
    {
        ch = expr[i++];
        if(ch == '[' || ch == '{' || ch == '(')
            push(ch);
        else if( ch == ']' || ch == ')' || ch == '}') {
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


void inputchar(char str[])   //문자열을 사용자로부터 받기
{
    printf("수식을 입력해주세요.\n");
    fgets(str, 80, stdin);
}

void printchar(char *str)
{
    
}
