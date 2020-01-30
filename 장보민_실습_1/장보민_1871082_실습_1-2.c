#include <stdio.h>
#include <stdlib.h>

//함수 선언
void computeMatrix(int** A, int **B, int** C);

//전역변수 선언
int n, m, l;
int** A;
int** B;
int** C;

int main(void) {
	//소속: 사이버보안
	//학번: 1871082
	//성명: 장보민

	printf("n m n\n:");
	scanf("%d %d %d", &n, &m, &l); //n,m,l 변수 입력받음

	//배열 A,B,C 동적 할당
	A = malloc(sizeof(int*)*n);
	B = malloc(sizeof(int*)*m);
	C = malloc(sizeof(int*)*n);

	//배열 A,B,C 각각에 원소에 2차원 배열이 되도록 동적 할당해줌.
	for (int i = 0; i < n; i++)
		A[i] = malloc(sizeof(int)*m);
	for (int i = 0; i < m; i++)
		B[i] = malloc(sizeof(int)*l);
	for (int i = 0; i < n; i++)
		C[i] = malloc(sizeof(int)*l);

	//이중for문을 사용하여 행렬 A의 행과 열에 들어갈 값을 입력받고, 저장
	printf("Matrix A:");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	//이중for문을 사용하여 행렬 B의 행과 열에 들어갈 값을 입력받고, 저장
	printf("Matrix B:");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < l; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}

	//computeMatrix함수를 호출해줌. 인자로 이중포인터 A,B,C값을 전달해줌.
	computeMatrix(A,B,C);

	//행렬 A를 출력
	printf("A=\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//행렬 B를 출력
	printf("B=\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < l; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//행렬 C를 출력
	printf("C=\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

//computeMatix함수 정의
void computeMatrix(int** A, int** B, int** C) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			//행렬 A와 B의 곱을 잠시 저장할 변수 temp 선언.
			//이 변수는 j값이 증가할 때마다 0으로 초기화되도록 함.
			int temp = 0; 
			for (int k = 0; k < m; k++)
			{
				//A,B의 곱을 temp값에 저장
				temp += A[i][k] * B[k][j];
			}
			//행렬 C의 값 저장.
			C[i][j] = temp;
		}
	}

}