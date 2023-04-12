//
//  mathh.h
//  datastructures chap 3 big exam 2
//
//  Created by 한설 on 2023/04/12.
//

void error(char msg[]);

#define MAX_STACK_DATA 100

typedef int Element;

//STACK ADTs
void init_stack(void);
int is_empty(void);
int is_full(void);
int size(void);
Element pop(void);
Element peek(void);
void push(int a);

//double STACK ADTs
void init_stackcal(void);
int is_emptycal(void);
int is_fullcal(void);
int sizecal(void);
double popcal(void);
double peekcal(void);
void pushcal(int a);


int check_matching(char expr[]);
void inputchar(char str[]);
void printchar(char *str);
double calc_postfix(char *expr);
void infix_to_postfix(char *expr);
int precedence(char op);
