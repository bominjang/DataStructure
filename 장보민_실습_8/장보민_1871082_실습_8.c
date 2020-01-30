#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){int temp=a;a=b;b=temp;} //매크로함수로 swqp함수 정의
int count=0; //연산 횟수를 계산할 count 변수 선언, 초기화

void adjust(int a[], int root, int n)
{
	int child, rootkey;
	rootkey = a[root];
	//i번째 노드의 왼쪽 자식노드를 child로 set.
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
	//초기 최대 힙 구성
	//자식이 있는 노드((n-1)/2)부터 첫번째 노드까지 해당 노드를 루트로 하는 부분 트리를 최대힙으로 구성.
	for (i = (n - 1) / 2; i >= 0; i--)
		adjust(a, i, n);
	//루트의 자리 교환과 힙 재구성
	for (i = n - 2; i >= 0; i--)
	{
		swap(a[0], a[i + 1]);
		adjust(a, 0, i + 1);
	}
}


int main()
{
	//전공: 사이버보안
	//학번: 1871082
	//이름: 장보민
	FILE *fp;
	int* heap;

	fp = fopen("input6.txt", "r"); // 자신의 환경에 맞는 파일 경로 입력
	printf("1.입력파일(\"input6.txt\")\n");
	int heap_size;
	fscanf(fp, "%d", &heap_size);
	heap = (int *)malloc(sizeof(int)*heap_size);
	int item;
	printf("정렬 결과 = ");
	//정렬결과 출력
	for (int i = 0; i < heap_size; i++)
	{
		fscanf(fp, "%d", &item);
		heap[i] = item;
	}
	//heapSort함수 호출
	heapSort(heap, heap_size);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", heap[i]);
	}
	printf(" ……… ");
	for(int i = heap_size-11;i<(heap_size);i++)
	{
		printf("%d\t", heap[i]);
	}
	printf("\n");
	printf("비교 횟수 : %d\n", count);

	fclose(fp);
}