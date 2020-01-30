#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b){float t=a; a=b;b=t;}
long int count_insert;
long int count_quick;
//insertion_sort�Լ�
void insertion_sort(float list[], int n)
{
	int i, j;
	float key;
	//for���� ���� ����
	//�ε��� 0�� �̹� ���ĵ� ������ �� �� �ִ�.
	for (i = 1; i < n; i++)
	{
		//���� ���Ե� ������ i��° ������ key ������ ����
		key = list[i];
		//���� ���ĵ� �迭�� i-1���� �̹Ƿ� i-1��°���� �������� ����.
		//j ���� ������ �ƴϾ�� �ϰ�
		//key������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�.
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			//j��° ���� ��ĭ �ڷ� �̵���Ų��.
			list[j + 1] = list[j];
			count_insert++;
		}
		count_insert++;
		//j+1��° ���� key�� �ִ´�.
		list[j + 1] = key;
	}
}
//1.pivot�� �������� 2���� �κ� ����Ʈ�� ������.
//2.pivot ���� ���� ���� ��� ���� �κ� ����Ʈ��, ū ���� ������ �κ� ����Ʈ�� �ű��.
//2���� ��յ� �迭�� �պ�����
int partition(float list[], int left, int right)
{
	float pivot;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left]; //������ ����Ʈ�� ���� ���� �����͸� pivot���� ����.
	//low�� high�� ������ ������ �ݺ�.
	do {
		//list[low]�� pivot���� ������ ��� low�� ������Ŵ.
		do {
			++count_quick;
			low++;//low�� left+1�������� ����
		} while (low <= right && list[low] < pivot);

		//list[high]�� pivot���� ũ�� ��� high�� ����.
		do {
			++count_quick;
			high--;//high�� right�������� ����.
		} while (high >= left && list[high] > pivot);

		count_quick -= 2;
		//���� low�� high�� �������� �ʾ����� list[low]�� list[high]�� ��ȯ
		if (low < high) { SWAP(list[low], list[high]) };
	} while (low < high);
	//low�� high�� ���������� �ݺ����� �������� list[left]�� list[high]�� ��ȯ
	SWAP(list[left], list[high]);
	//pivot�� ��ġ�� high�� ��ȯ
	return high;
}
//������
void quick_sort(float list[], int left, int right)
{
	//������ ������ 2�� �̻��� �������̸�(����Ʈ�� ũ�Ⱑ 0�̳� 1�̸�
	if (left < right) {
		//partition�Լ��� ȣ���Ͽ� �ǹ��� �������� ����Ʈ�� ��յ� ����
		int q = partition(list, left, right);

		//pivot�� ������ �κ� ����Ʈ�� ������� ��ȯ ȣ��
		quick_sort(list, left, q - 1);//���� �κ� ����Ʈ ���� - ����
		quick_sort(list, q + 1, right);// ���� �κ� ����Ʈ ���� - ����
	}
}


int main()
{
	//�̸� : �庸��
	//�й� : 1871082
	//���� : ���̹���������
	FILE* fp;
	int n;
	float element;

	fp = fopen("r_data1.txt", "r"); // �ڽ��� ȯ�濡 �´� ���� ��� �Է�
	fscanf_s(fp, "%d", &n);

	//insert_list�� quick_list�� ����
	float* insert_list = (float*)malloc(sizeof(float) * n);
	float* quick_list = (float*)malloc(sizeof(float) * n);

	//for���� ���� elemet�� �޾Ƽ� �� �迭�� ����.
	for (int i = 0; i < n; i++)
	{
		fscanf_s(fp, "%f ", &element);
		insert_list[i] = element;
		quick_list[i] = element;
	}
	printf("�Է����� = r_data1(n=%d).txt\n\n", n);

	//insertion_sort ȣ��
	insertion_sort(insert_list, n);
	printf("�������� ��� = ");
	//for���� ���� ���
	for (int i = 0; i < 10; i++)
	{
		printf("%f\t", insert_list[i]);
	}
	printf(" ������ ");
	for (int i = n - 11; i < n; i++)
	{
		printf("%f\t", insert_list[i]);
	}
	printf("���� ���� �� Ƚ�� = %dȸ\n", count_insert);
	printf("\n");
	//quick_sort ȣ��
	quick_sort(quick_list, 0, n - 1);
	printf("�� ���� ��� = ");
	//for���� �̿��� ���
	for (int i = 0; i < 10; i++)
	{
		printf("%f\t", quick_list[i]);
	}
	printf(" ������ ");
	for (int i = n - 11; i < n; i++)
	{
		printf("%f\t", quick_list[i]);
	}
	printf("�� ���� �� Ƚ�� = %dȸ\n", count_quick);
	printf("\n");


	fclose(fp);
}