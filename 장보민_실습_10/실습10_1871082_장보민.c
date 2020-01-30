#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 20

int visited[MAX_VERTICES] = { 0 }; //visited라는 일차원 배열을 0으로 set함.
int count;
int v = 0;

//깊이 우선 탐색 함수
void dfs_mat(int** arr, int n, int v)
{
	int w; 
	printf("%d ", v);
	//방문했다는 도장을 찍음
	visited[v] = TRUE; 
	for (w = 0; w < n; w++)
		//v와 w vertex 사이에 연결이 되어있고, w를 방문하지 않았으면
		if (arr[v][w] && !visited[w])
			//dfs_mat 재귀호출
			dfs_mat(arr, n, w);
}
 //연결된 component를 찾는 함수
void find_connected_component(int** arr, int n)
{
	//visited 배열의 v번째 index에 count값을 넣음.
	visited[v] = count;
	//for 문을 돌면서 모든 vertex에 대해 알아봄.
	for (v = 0; v < n; v++)
	{
		//만약에 방문 안한 vertex일 때만 운행
		if (!visited[v])
		{
			printf("\n");
			//count값을 증가시키고
			count++;
			printf("연결성분%d :", count);
			//dfs_mat 호출. 이 때, v값도 같이 전달해야 함.
			dfs_mat(arr, n, v);
		}
	}
}

int main()
{
	//학번 : 1871082
	//이름 : 장보민
	//전공 : 사이버보안전공
	FILE* fp;
	int n, m; //정점, 에지
	int v1, v2;
	fp = fopen("graph3.txt", "r"); // 자신의 환경에 맞는 파일 경로 입력
	fscanf(fp, "%d %d", &n, &m);

	/*2차원 배열 선언, 초기화*/
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
	//2차원 배열에 할당
	for (int i = 0; i < m; i++)
	{
		fscanf(fp, "%d %d", &v1, &v2);
		arr[v1][v2] = 1;
	}

	printf("입력 파일 : \"graph3.txt\"\n");
	find_connected_component(arr, n);
	printf("\n");

	fclose(fp);

}