#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){int temp=a;a=b;b=temp;} //��ũ���Լ��� swqp�Լ� ����
int count=0; //���� Ƚ���� ����� count ���� ����, �ʱ�ȭ

void adjust(int a[], int root, int n)
{
	int child, rootkey;
	rootkey = a[root];
	//i��° ����� ���� �ڽĳ�带 child�� set.
	child = 2 * root + 1;
	while (child <= n - 1)
	{
		if ((child < n - 1) && (a[child] < a[child + 1])) { count++; child++;}
		if (rootkey > a[child]) { count++; break; }
		else {
			a[(child - 1) / 2] = a[child];
			child = 2 * child + 1;
		}
	}
	a[(child - 1) / 2] = rootkey;
}


void heapSort(int a[], int n)
{
	int i;
	//�ʱ� �ִ� �� ����
	//�ڽ��� �ִ� ���((n-1)/2)���� ù��° ������ �ش� ��带 ��Ʈ�� �ϴ� �κ� Ʈ���� �ִ������� ����.
	for (i = (n - 1) / 2; i >= 0; i--)
		adjust(a, i, n);
	//��Ʈ�� �ڸ� ��ȯ�� �� �籸��
	for (i = n - 2; i >= 0; i--)
	{
		swap(a[0], a[i + 1]);
		adjust(a, 0, i + 1);
	}
}


int main()
{
	//����: ���̹�����
	//�й�: 1871082
	//�̸�: �庸��
	FILE *fp;
	int* heap;

	fp = fopen("input6.txt", "r"); // �ڽ��� ȯ�濡 �´� ���� ��� �Է�
	printf("1.�Է�����(\"input6.txt\")\n");
	int heap_size;
	fscanf(fp, "%d", &heap_size);
	heap = (int *)malloc(sizeof(int)*heap_size);
	int item;
	printf("���� ��� = ");
	//���İ�� ���
	for (int i = 0; i < heap_size; i++)
	{
		fscanf(fp, "%d", &item);
		heap[i] = item;
	}
	//heapSort�Լ� ȣ��
	heapSort(heap, heap_size);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", heap[i]);
	}
	printf(" ������ ");
	for(int i = heap_size-11;i<(heap_size);i++)
	{
		printf("%d\t", heap[i]);
	}
	printf("\n");
	printf("�� Ƚ�� : %d\n", count);

	fclose(fp);
}