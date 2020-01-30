#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 20

int visited[MAX_VERTICES] = { 0 }; //visited��� ������ �迭�� 0���� set��.
int count;
int v = 0;

//���� �켱 Ž�� �Լ�
void dfs_mat(int** arr, int n, int v)
{
	int w; 
	printf("%d ", v);
	//�湮�ߴٴ� ������ ����
	visited[v] = TRUE; 
	for (w = 0; w < n; w++)
		//v�� w vertex ���̿� ������ �Ǿ��ְ�, w�� �湮���� �ʾ�����
		if (arr[v][w] && !visited[w])
			//dfs_mat ���ȣ��
			dfs_mat(arr, n, w);
}
 //����� component�� ã�� �Լ�
void find_connected_component(int** arr, int n)
{
	//visited �迭�� v��° index�� count���� ����.
	visited[v] = count;
	//for ���� ���鼭 ��� vertex�� ���� �˾ƺ�.
	for (v = 0; v < n; v++)
	{
		//���࿡ �湮 ���� vertex�� ���� ����
		if (!visited[v])
		{
			printf("\n");
			//count���� ������Ű��
			count++;
			printf("���Ἲ��%d :", count);
			//dfs_mat ȣ��. �� ��, v���� ���� �����ؾ� ��.
			dfs_mat(arr, n, v);
		}
	}
}

int main()
{
	//�й� : 1871082
	//�̸� : �庸��
	//���� : ���̹���������
	FILE* fp;
	int n, m; //����, ����
	int v1, v2;
	fp = fopen("graph3.txt", "r"); // �ڽ��� ȯ�濡 �´� ���� ��� �Է�
	fscanf(fp, "%d %d", &n, &m);

	/*2���� �迭 ����, �ʱ�ȭ*/
	int** arr;
	arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	//2���� �迭�� �Ҵ�
	for (int i = 0; i < m; i++)
	{
		fscanf(fp, "%d %d", &v1, &v2);
		arr[v1][v2] = 1;
	}

	printf("�Է� ���� : \"graph3.txt\"\n");
	find_connected_component(arr, n);
	printf("\n");

	fclose(fp);

}