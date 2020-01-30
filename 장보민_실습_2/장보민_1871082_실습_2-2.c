#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//피보나치수를 재귀적으로 계산하는 함수
int fib(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}


int main(void)
{
	//전공: 사이버보안
	//학번: 1871082
	//이름: 장보민
	int n = 0;//n값을 입력받은 변수 선언 & 초기화
	int fib_num=0;//피보나치 수를 저장할 변수 선언 & 초기화
	time_t start, end;//time_t형식의 변수 선언 & 초기화
	double result = 0;//계산시간을 저장할 double형 변수 선언 & 초기화

	//n을 입력받음
	printf("n을 입력하시오 : ");
	scanf("%d", &n);
	
	//현재 시각을 구함
	start = clock();

	printf("n = %d\n", n);
	//피보나치함수 호출
	fib_num = fib(n);
	printf("The %d-th Fibonacci number = %d\n", n, fib_num);
	//마치는 시각을 구함
	end = clock();
	//시간차를 구함
	result = (double)(end - start);
	//나노sec단위로 계산
	double n_result = result * (double)pow(10,-9);

	printf("The execution time = %f nsec\n", n_result);

	return 0;
}