#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//�Ǻ���ġ���� ��������� ����ϴ� �Լ�
int fib(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}


int main(void)
{
	//����: ���̹�����
	//�й�: 1871082
	//�̸�: �庸��
	int n = 0;//n���� �Է¹��� ���� ���� & �ʱ�ȭ
	int fib_num=0;//�Ǻ���ġ ���� ������ ���� ���� & �ʱ�ȭ
	time_t start, end;//time_t������ ���� ���� & �ʱ�ȭ
	double result = 0;//���ð��� ������ double�� ���� ���� & �ʱ�ȭ

	//n�� �Է¹���
	printf("n�� �Է��Ͻÿ� : ");
	scanf("%d", &n);
	
	//���� �ð��� ����
	start = clock();

	printf("n = %d\n", n);
	//�Ǻ���ġ�Լ� ȣ��
	fib_num = fib(n);
	printf("The %d-th Fibonacci number = %d\n", n, fib_num);
	//��ġ�� �ð��� ����
	end = clock();
	//�ð����� ����
	result = (double)(end - start);
	//����sec������ ���
	double n_result = result * (double)pow(10,-9);

	printf("The execution time = %f nsec\n", n_result);

	return 0;
}