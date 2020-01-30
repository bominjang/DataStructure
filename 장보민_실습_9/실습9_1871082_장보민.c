#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b){float t=a; a=b;b=t;}
long int count_insert;
long int count_quick;
//insertion_sort함수
void insertion_sort(float list[], int n)
{
	int i, j;
	float key;
	//for문을 통해 정렬
	//인덱스 0은 이미 정렬된 것으로 볼 수 있다.
	for (i = 1; i < n; i++)
	{
		//현재 삽입될 숫자인 i번째 정수를 key 변수로 복사
		key = list[i];
		//현재 정렬된 배열은 i-1까지 이므로 i-1번째부터 역순으로 조사.
		//j 값은 음수가 아니어야 하고
		//key값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동.
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			//j번째 값을 한칸 뒤로 이동시킨다.
			list[j + 1] = list[j];
			count_insert++;
		}
		count_insert++;
		//j+1번째 값에 key를 넣는다.
		list[j + 1] = key;
	}
}
//1.pivot을 기준으로 2개의 부분 리스트로 나눈다.
//2.pivot 보다 작은 값은 모두 왼쪽 부분 리스트로, 큰 값은 오른쪽 부분 리스트로 옮긴다.
//2개의 비균등 배열의 합병과정
int partition(float list[], int left, int right)
{
	float pivot;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left]; //정렬할 리스트의 가장 왼쪽 데이터를 pivot으로 선택.
	//low와 high가 교차할 때까지 반복.
	do {
		//list[low]가 pivot보다 작으면 계속 low를 증가시킴.
		do {
			++count_quick;
			low++;//low는 left+1에서부터 시작
		} while (low <= right && list[low] < pivot);

		//list[high]가 pivot보다 크면 계속 high를 감소.
		do {
			++count_quick;
			high--;//high는 right에서부터 시작.
		} while (high >= left && list[high] > pivot);

		count_quick -= 2;
		//만약 low와 high가 교차하지 않았으면 list[low]와 list[high]를 교환
		if (low < high) { SWAP(list[low], list[high]) };
	} while (low < high);
	//low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
	SWAP(list[left], list[high]);
	//pivot의 위치인 high를 반환
	return high;
}
//퀵정렬
void quick_sort(float list[], int left, int right)
{
	//정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이면
	if (left < right) {
		//partition함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할
		int q = partition(list, left, right);

		//pivot은 제외한 부분 리스트를 대상으로 순환 호출
		quick_sort(list, left, q - 1);//앞쪽 부분 리스트 정렬 - 정복
		quick_sort(list, q + 1, right);// 뒤쪽 부분 리스트 정렬 - 정복
	}
}


int main()
{
	//이름 : 장보민
	//학번 : 1871082
	//전공 : 사이버보안전공
	FILE* fp;
	int n;
	float element;

	fp = fopen("r_data1.txt", "r"); // 자신의 환경에 맞는 파일 경로 입력
	fscanf_s(fp, "%d", &n);

	//insert_list와 quick_list를 생성
	float* insert_list = (float*)malloc(sizeof(float) * n);
	float* quick_list = (float*)malloc(sizeof(float) * n);

	//for문을 통해 elemet를 받아서 각 배열에 저장.
	for (int i = 0; i < n; i++)
	{
		fscanf_s(fp, "%f ", &element);
		insert_list[i] = element;
		quick_list[i] = element;
	}
	printf("입력파일 = r_data1(n=%d).txt\n\n", n);

	//insertion_sort 호출
	insertion_sort(insert_list, n);
	printf("삽입정렬 결과 = ");
	//for문을 통해 출력
	for (int i = 0; i < 10; i++)
	{
		printf("%f\t", insert_list[i]);
	}
	printf(" ……… ");
	for (int i = n - 11; i < n; i++)
	{
		printf("%f\t", insert_list[i]);
	}
	printf("삽입 정렬 비교 횟수 = %d회\n", count_insert);
	printf("\n");
	//quick_sort 호출
	quick_sort(quick_list, 0, n - 1);
	printf("퀵 정렬 결과 = ");
	//for문을 이용해 출력
	for (int i = 0; i < 10; i++)
	{
		printf("%f\t", quick_list[i]);
	}
	printf(" ……… ");
	for (int i = n - 11; i < n; i++)
	{
		printf("%f\t", quick_list[i]);
	}
	printf("퀵 정렬 비교 횟수 = %d회\n", count_quick);
	printf("\n");


	fclose(fp);
}