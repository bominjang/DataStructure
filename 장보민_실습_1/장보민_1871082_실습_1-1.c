#include <stdio.h>
#include <stdlib.h>

//�������� ����
int n, min, max;
int* num;

//�ִ밪�� �ּҰ��� ����ϴ� �Լ� ����,����
int findMaxMin()
{
	//min�� max���� num�迭�� 0��° ������ �ʱ�ȭ
	min = num[0];
	max = num[0];

	//for���� ���� max�� min�� ���
	for (int i = 1; i < n; i++)
	{
		//num[i]�� max������ ũ�� max�� ����
		if (max < num[i])
			max = num[i];

		//num[i]�� min������ ������ min�� ����
		if (min > num[i])
			min = num[i];
	}
}


int main(void) {
	//�Ҽ�: ���̹�����
	//�й�: 1871082
	//����: �庸��

	printf("n= ");
	scanf("%d", &n); //n���� �Է¹���

	num = malloc(sizeof(int)*n); //num �迭 ���� �Ҵ�
	
	//for���� ���� ���� �Է¹ް�, ����
	printf("data= ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	//findMaxMin�Լ� ȣ��.
	findMaxMin();

	//�ִ��ּҰ��� ���
	printf("Maximum = %d\n", max);
	printf("Minimum = %d\n", min);


}