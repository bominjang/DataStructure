#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10000

int list[MAX_SIZE]; //���� �迭 ����
int b_count; //binary_count�� �� Ƚ���� ������ ����
int i_count;//���� Ž���� ��Ƚ���� ������ ����
//�Ҽ� ����� �Լ�
void prime_generate()
{
	int n; //�迭�� ���� ���� ������ ����
	int i;//for�� �����
	int check=0; //�迭�� index�� ��Ÿ�� check ����
	list[check] = 2; //����, 0��° index�� 2�� ����.
	n = 3; //n=3�� �Ҵ�.
	while(check!=MAX_SIZE){ // check�� 10000�� �ɶ����� �ݺ�
		for (i = 2; i < n; i++)//n�� �Ҽ��� i�� n�� �Ǹ� �ݺ����� ����
		{
			if (n%i == 0)//i�� n�� ���
			{
				break;//i�� n���� ���� ���·� �ݺ��� Ż��
			}
		}
		if (i == n)//�Ҽ���
		{
			list[++check] = n; 
		}
		n++;
	}
}
//��� �Լ��� �̿��� ���� Ž��
int search_binary(int key, int low, int high)
{
	int middle = (low + high) / 2;
	b_count++; //if�������� �� Ƚ���� �̸� ����
	if (key == list[middle]) { return middle; } 
	else if (key < list[middle]) { b_count++; search_binary(key, 0, middle - 1); }
	else if (key > list[middle]) { b_count++; search_binary(key, middle + 1, high); }
	else { b_count++; return -1; } //�� �������� ��
}


//���� Ž��
int search_interpolation(int key)
{
	int low, high, j;
	low = 0;
	high = MAX_SIZE - 1;
	while ((list[high] >= key) && (key > list[low])) 
	{
		i_count+=2; //while������ �� �� ���ϹǷ� i_count���� 2 ������Ŵ.
		j = ((float)(key - list[low]) / (list[high] - list[low])*(high - low)) + low;
		i_count++;//if�������� �� Ƚ���� �̸� ����.
		if (key > list[j]) { low = j + 1; }
		else if (key < list[j]) { i_count++; high = j - 1; }
		else { i_count++; low = j; }
	}
	if (list[low] == key) { i_count++; return (low); } //Ž�� ����
	else { i_count++; return -1; }//Ž�� ����
}


int main()
{
	//�̸� : �庸��
	//���� : ���̹���������
	//�й� : 1871082
	int key;
	prime_generate(); //�Ҽ� ���� �Լ��� ȣ��

	printf("Key = ");
	scanf("%d", &key);


	printf("\nBinary search\n");
	printf("\tIndex = ");
	printf("%d\n",search_binary(key,0,MAX_SIZE)); //���� Ž�� �Լ� ȣ��
	printf("\tThe number of comparisons = %d\n",b_count);

	printf("\nInterpolation search\n");
	printf("\tIndex = ");
	printf("%d\n", search_interpolation(key)); //���� Ž�� �Լ� ȣ��
	printf("\tThe number of comparisons = %d\n", i_count);

	return 0;
}