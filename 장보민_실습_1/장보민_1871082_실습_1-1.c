#include <stdio.h>
#include <stdlib.h>

//전역변수 선언
int n, min, max;
int* num;

//최대값과 최소값을 계산하는 함수 선언,정의
int findMaxMin()
{
	//min과 max값은 num배열의 0번째 값으로 초기화
	min = num[0];
	max = num[0];

	//for문을 통해 max와 min값 계산
	for (int i = 1; i < n; i++)
	{
		//num[i]이 max값보다 크면 max값 변경
		if (max < num[i])
			max = num[i];

		//num[i]이 min값보다 작으면 min값 변경
		if (min > num[i])
			min = num[i];
	}
}


int main(void) {
	//소속: 사이버보안
	//학번: 1871082
	//성명: 장보민

	printf("n= ");
	scanf("%d", &n); //n값을 입력받음

	num = malloc(sizeof(int)*n); //num 배열 동적 할당
	
	//for문을 통해 값을 입력받고, 저장
	printf("data= ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	//findMaxMin함수 호출.
	findMaxMin();

	//최대최소값을 출력
	printf("Maximum = %d\n", max);
	printf("Minimum = %d\n", min);


}