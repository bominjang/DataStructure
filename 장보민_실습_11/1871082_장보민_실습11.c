#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define INF 1000
#define MAX_VERTICES 20
#define MAX_EDGE 200

int distance[MAX_VERTICES]; //���� �������κ��� �ִ� ��� �Ÿ�
int found[MAX_VERTICES]; //�湮�� ���� ǥ��
int weight[MAX_VERTICES][MAX_VERTICES]; //2���� �������

//choose�Լ�
int choose(int distance[], int n, int found[])
{
	/*���� distance �迭���� ���� ���� ����ġ ���� ��ġ�ϰ� �ִ�
	�迭�� �ε����� ã�� ��ȯ�ϴ� �Լ�*/

	int i, min, minpos;

	min = INT_MAX;
	minpos = -1;
	/*�ּҰ� min�� ã�� �ݺ�����
	�湮�� ���� ���� ������ ���� distance �迭�� ������ ����*/
	for (i = 0; i < n; i++)
	{
		//�湮�� ���� ���� �����̰� ��������� �ּҰ� min���� �۴ٸ�
		if (distance[i] < min && !found[i]) {
			//�ּҰ��� �ǹ��ϴ� min������ ��������.
			min = distance[i];
			//�ּҰ��� ������ �ش� ������ �ε����� minpos�� ������.
			minpos = i;
		}
	}
	//distance �迭���� �ּҰ��� ��ġ�ϰ� �ִ� �ε����� ��ȯ
	return minpos;
}

/*start �������� n���������� �ִ� ��θ� ã�� �Լ�*/
void shortest_path(int start, int n)
{
	int i, u, w;
	/*�ʱ�ȭ �۾�*/
	for (i = 0; i < n; i++) 
	{
		//���� ���� start�� �������� ���� ���� ����ġ ������ distance �迭�� �ʱ�ȭ ��
		distance[i] = weight[start][i];
		//���� ������ ���� �ʾ����Ƿ� �湮 ǥ���� ������ �ϴ� found�迭�� FALSE�� �ʱ�ȭ ��.
		found[i] = FALSE;
	}
	//���� ������ ���������� �湮 ���θ� TRUE�� ����.
	found[start] = TRUE;
	//start�κ��� start������ distance �� 0���� set
	distance[start] = 0;

	//������ ���� ���� ���� set�����Ƿ� ���⼭��, �ϳ��� �� ��ŭ�� �ݺ���.
	for (i = 0; i < n - 1; i++) {
		//�ּҰ��� �ִ� �ε����� ������ u�� ����.
		u = choose(distance, n, found);
		//���� distance �迭���� ���� ���� ���� ��ġ�� �ε����� u�̹Ƿ�
		//u�� ������ �����Ѵ�. �����԰� ���ÿ� TRUE�� ���� ���ָ� �湮 ǥ�ø� ��.
		found[u] = TRUE;
		//�ּ� ����ġ�� �ִ� ������ ���� S�� �߰��� ��, ������ �� �ִ� ������ �ִٸ� �� ������
		//��������� ��. 
		for (w = 0; w < n; w++)
		{
			//���� ���õ��� �ʴ� �����̰�
			if (!found[w])
			{
				//���� �� ����(u)������ �Ÿ� (distance[u])+����w������ �Ÿ���
				//���� w���������� �Ÿ����� �����ٸ� �� ������ ��������.
				if (distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w];
			}
		}
	}
}

int main()
{
	//�̸� : �庸��
	//���� : ���̹���������
	//�й� : 1871082
	int n, m;//vertex�� edge�� ���� ������ ���� 
	int v1, v2, w; //�� ���� �������, ����ġ�� ������ ����
	FILE *fp = fopen("sp3.txt", "r");
	fscanf(fp, "%d %d", &n, &m);

	//2���� �迭 weight�� �ʱⰪ : INF�� set
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (i == j) weight[i][j] = 0;
			weight[i][j] = INF;
		}
	}
	
	//2���� �迭�� �Ҵ�
	for (int i = 0; i < m; i++)
	{
		fscanf(fp, "%d %d %d", &v1, &v2, &w);
		weight[v1][v2] = w;
	}
	//�Լ� ȣ��
	shortest_path(0, n);

	printf("�Է����� = \"sp3.txt\"\n");
	printf("v0�κ����� �ִ� ��� : ");
	//�ִܰ�� ���
	for (int i = 0; i < n; i++)
	{
		printf("%d ", distance[i]);
	}
	printf("\n");
}