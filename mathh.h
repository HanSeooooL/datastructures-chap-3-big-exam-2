//
//  mathh.h
//  datastructures chap 3 big exam 2
//
//  Created by 한설 on 2023/04/12.
//

void error(char msg[]);

#define MAX_STACK_DATA 100

typedef int Element;

extern Element data[MAX_STACK_DATA];
extern int top;

//STACK ADTs
void init_stack(void);
int is_empty(void);
int is_full(void);
int size(void);
int pop(void);
int peek(void);
void push(int a);

int check_matching(char expr[]);
void inputchar(char str[]);
void printchar(char *str);
double calc_postfix(char *expr);
