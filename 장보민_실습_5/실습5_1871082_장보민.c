#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef struct StackType {
	char stack[MAX_STACK_SIZE];
	int top;
}Stack;

Stack st;
Stack* s = &st;

//���� �ʱ�ȭ �Լ�
void init()
{
	s->top = -1;
}
//������ ����� �� �����ϴ� �Լ�
int is_empty()
{
	return (s->top == -1);
}
//������ �� ���ִ� �� �����ϴ� �Լ�
int is_full() 
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
//���ÿ� char���� �ִ� �Լ�
void push(char item)
{
	if (is_full()) printf("\"stack overflow \"");
	else s->stack[++(s->top)] = item;
}
//pop�� ��
char pop()
{
	if (is_empty()) { printf("\"stack empty \""); exit(1); }
	else return s->stack[(s->top)--]; //�迭�� top�ε����� �ִ� ���Ҹ� return �� �Ŀ� top���� �ϳ� ���ҽ�Ų��.
}
//peek�� ��
char peek()
{
	if (is_empty()) printf("\"stack emptyb \"");
	else return s->stack[s->top]; //�迭�� top�ε����� �ִ� ���Ҹ� return������, ���⼭�� top���� �����Ű�� �ʴ´�.
}




int main(void)
{

	init(); //������ �ʱ�ȭ��Ŵ
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