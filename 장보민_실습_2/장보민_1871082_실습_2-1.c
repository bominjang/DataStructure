#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//계승값을 구하는 재귀 함수
int fact(int n)
{
	if (n == 0) return 1;
	else return(n*fact(n - 1));

}




int main(void)
{
	//전공: 사이버보안
	//학번: 1871082
	//이름: 장보민

	//n을 입력받음
	int n = 0;
	printf("n을 입력하시오 : ");
	scanf("%d", &n);

	//time_t형식의 
	time_t start, end;
	double result = 0;
	
	//현재 시각을 구함
	start = clock();

	printf("n = %d\n", n);
	//팩토리얼함수를 호출
	int fact_num = fact(n);
	printf("The factorial of %d = %d\n", n,fact_num);

	end = clock();
	//시간차를 구함
	result = (double)(end - start);
	//나노sec단위로 계산
	double n_result = result * (double)pow(10, -9);

	printf("The execution time = %d nsec\n", n_result);

	return 0;	
}

