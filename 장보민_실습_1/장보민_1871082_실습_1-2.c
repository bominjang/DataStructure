#include <stdio.h>
#include <stdlib.h>

//�Լ� ����
void computeMatrix(int** A, int **B, int** C);

//�������� ����
int n, m, l;
int** A;
int** B;
int** C;

int main(void) {
	//�Ҽ�: ���̹�����
	//�й�: 1871082
	//����: �庸��

	printf("n m n\n:");
	scanf("%d %d %d", &n, &m, &l); //n,m,l ���� �Է¹���

	//�迭 A,B,C ���� �Ҵ�
	A = malloc(sizeof(int*)*n);
	B = malloc(sizeof(int*)*m);
	C = malloc(sizeof(int*)*n);

	//�迭 A,B,C ������ ���ҿ� 2���� �迭�� �ǵ��� ���� �Ҵ�����.
	for (int i = 0; i < n; i++)
		A[i] = malloc(sizeof(int)*m);
	for (int i = 0; i < m; i++)
		B[i] = malloc(sizeof(int)*l);
	for (int i = 0; i < n; i++)
		C[i] = malloc(sizeof(int)*l);

	//����for���� ����Ͽ� ��� A�� ��� ���� �� ���� �Է¹ް�, ����
	printf("Matrix A:");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	//����for���� ����Ͽ� ��� B�� ��� ���� �� ���� �Է¹ް�, ����
	printf("Matrix B:");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < l; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}

	//computeMatrix�Լ��� ȣ������. ���ڷ� ���������� A,B,C���� ��������.
	computeMatrix(A,B,C);

	//��� A�� ���
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

	//��� B�� ���
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

	//��� C�� ���
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

//computeMatix�Լ� ����
void computeMatrix(int** A, int** B, int** C) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			//��� A�� B�� ���� ��� ������ ���� temp ����.
			//�� ������ j���� ������ ������ 0���� �ʱ�ȭ�ǵ��� ��.
			int temp = 0; 
			for (int k = 0; k < m; k++)
			{
				//A,B�� ���� temp���� ����
				temp += A[i][k] * B[k][j];
			}
			//��� C�� �� ����.
			C[i][j] = temp;
		}
	}

}