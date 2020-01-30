#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef struct StackType {
	char stack[MAX_STACK_SIZE];
	int top;
}Stack;

Stack st;
Stack* s = &st;

//스택 초기화 함수
void init()
{
	s->top = -1;
}
//스택이 비었는 지 조사하는 함수
int is_empty()
{
	return (s->top == -1);
}
//스택이 다 차있는 지 조사하는 함수
int is_full() 
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
//스택에 char값을 넣는 함수
void push(char item)
{
	if (is_full()) printf("\"stack overflow \"");
	else s->stack[++(s->top)] = item;
}
//pop할 때
char pop()
{
	if (is_empty()) { printf("\"stack empty \""); exit(1); }
	else return s->stack[(s->top)--]; //배열의 top인덱스에 있는 원소를 return 한 후에 top값을 하나 감소시킨다.
}
//peek할 때
char peek()
{
	if (is_empty()) printf("\"stack emptyb \"");
	else return s->stack[s->top]; //배열의 top인덱스에 있는 원소를 return하지만, 여기서는 top값을 변경시키지 않는다.
}




int main(void)
{

	init(); //스택을 초기화시킴
	push('1'); printf("%c ", pop());
	push('2'); printf("%c ", pop());
	push('3'); printf("%c ", pop());
	printf("\n");
	push('1'); push('2');
	printf("%c ", pop()); printf("%c ", pop());
	push('3'); printf("%c ", pop());
	printf("\n");
	push('1'); printf("%c ", pop());
	push('2'); push('3');
	printf("%c ", pop()); printf("%c ", pop());
	printf("\n");
	push('1'); push('2');
	printf("%c ", pop()); push('3');
	printf("%c ", pop()); printf("%c ", pop());
	printf("\n");
	push('1'); push('2'); push('3');
	printf("%c ", pop());
	printf("%c ", pop());
	printf("%c ", pop());
	printf("\n");	return 0;
}