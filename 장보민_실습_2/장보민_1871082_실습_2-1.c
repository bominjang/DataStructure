#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//��°��� ���ϴ� ��� �Լ�
int fact(int n)
{
	if (n == 0) return 1;
	else return(n*fact(n - 1));

}




int main(void)
{
	//����: ���̹�����
	//�й�: 1871082
	//�̸�: �庸��

	//n�� �Է¹���
	int n = 0;
	printf("n�� �Է��Ͻÿ� : ");
	scanf("%d", &n);

	//time_t������ 
	time_t start, end;
	double result = 0;
	
	//���� �ð��� ����
	start = clock();

	printf("n = %d\n", n);
	//���丮���Լ��� ȣ��
	int fact_num = fact(n);
	printf("The factorial of %d = %d\n", n,fact_num);

	end = clock();
	//�ð����� ����
	result = (double)(end - start);
	//����sec������ ���
	double n_result = result * (double)pow(10, -9);

	printf("The execution time = %d nsec\n", n_result);

	return 0;	
}

