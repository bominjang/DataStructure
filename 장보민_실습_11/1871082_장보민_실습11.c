#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define INF 1000
#define MAX_VERTICES 20
#define MAX_EDGE 200

int distance[MAX_VERTICES]; //시작 정점으로부터 최단 경로 거리
int found[MAX_VERTICES]; //방문한 정점 표시
int weight[MAX_VERTICES][MAX_VERTICES]; //2차원 인접행렬

//choose함수
int choose(int distance[], int n, int found[])
{
	/*현재 distance 배열에서 가장 작은 가중치 값이 위치하고 있는
	배열의 인덱스를 찾아 반환하는 함수*/

	int i, min, minpos;

	min = INT_MAX;
	minpos = -1;
	/*최소값 min을 찾는 반복문임
	방문한 적이 없는 정점에 대해 distance 배열의 값들을 비교함*/
	for (i = 0; i < n; i++)
	{
		//방문된 적이 없는 정점이고 현재까지의 최소값 min보다 작다면
		if (distance[i] < min && !found[i]) {
			//최소값을 의미하는 min정보를 갱신해줌.
			min = distance[i];
			//최소값이 등장한 해당 정점의 인덱스를 minpos에 저장함.
			minpos = i;
		}
	}
	//distance 배열에서 최소값이 위치하고 있는 인덱스를 반환
	return minpos;
}

/*start 정점부터 n정점까지의 최단 경로를 찾는 함수*/
void shortest_path(int start, int n)
{
	int i, u, w;
	/*초기화 작업*/
	for (i = 0; i < n; i++) 
	{
		//시작 정점 start를 기준으로 했을 때의 가중치 값으로 distance 배열을 초기화 함
		distance[i] = weight[start][i];
		//아직 시작을 하지 않았으므로 방문 표시의 역할을 하는 found배열을 FALSE로 초기화 함.
		found[i] = FALSE;
	}
	//시작 정점을 선택했으니 방문 여부를 TRUE로 설정.
	found[start] = TRUE;
	//start로부터 start까지의 distance 는 0으로 set
	distance[start] = 0;

	//위에서 시작 정점 값을 set했으므로 여기서는, 하나를 뺀 만큼만 반복함.
	for (i = 0; i < n - 1; i++) {
		//최소값이 있는 인덱스의 정보를 u에 저장.
		u = choose(distance, n, found);
		//현재 distance 배열에서 가장 작은 값이 위치한 인덱스는 u이므로
		//u번 정점을 선택한다. 선택함과 동시에 TRUE로 값을 써주며 방문 표시를 함.
		found[u] = TRUE;
		//최소 가중치가 있는 정점을 집합 S에 추가한 후, 갱신할 수 있는 정보가 있다면 그 정보를
		//갱신해줘야 함. 
		for (w = 0; w < n; w++)
		{
			//아직 선택되지 않는 정점이고
			if (!found[w])
			{
				//현재 그 정점(u)까지의 거리 (distance[u])+정점w까지의 거리가
				//기존 w정점까지의 거리보다 가깝다면 그 정보를 갱신해줌.
				if (distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w];
			}
		}
	}
}

int main()
{
	//이름 : 장보민
	//전공 : 사이버보안전공
	//학번 : 1871082
	int n, m;//vertex와 edge의 값을 저장할 변수 
	int v1, v2, w; //두 개의 정점들과, 가중치를 저장할 변수
	FILE *fp = fopen("sp3.txt", "r");
	fscanf(fp, "%d %d", &n, &m);

	//2차원 배열 weight의 초기값 : INF로 set
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (i == j) weight[i][j] = 0;
			weight[i][j] = INF;
		}
	}
	
	//2차원 배열에 할당
	for (int i = 0; i < m; i++)
	{
		fscanf(fp, "%d %d %d", &v1, &v2, &w);
		weight[v1][v2] = w;
	}
	//함수 호출
	shortest_path(0, n);

	printf("입력파일 = \"sp3.txt\"\n");
	printf("v0로부터의 최단 경로 : ");
	//최단경로 출력
	for (int i = 0; i < n; i++)
	{
		printf("%d ", distance[i]);
	}
	printf("\n");
}