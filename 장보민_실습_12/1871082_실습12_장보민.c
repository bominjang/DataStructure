#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10000

int list[MAX_SIZE]; //전역 배열 선언
int b_count; //binary_count의 비교 횟수를 저장할 변수
int i_count;//보간 탐색의 비교횟수를 저장할 변수
//소수 만드는 함수
void prime_generate()
{
	int n; //배열에 넣을 값을 저장할 변수
	int i;//for문 제어변수
	int check=0; //배열의 index를 나타낼 check 변수
	list[check] = 2; //먼저, 0번째 index에 2를 저장.
	n = 3; //n=3을 할당.
	while(check!=MAX_SIZE){ // check가 10000이 될때까지 반복
		for (i = 2; i < n; i++)//n이 소수면 i가 n이 되면 반복문이 끝남
		{
			if (n%i == 0)//i는 n의 약수
			{
				break;//i가 n보다 작은 상태로 반복문 탈출
			}
		}
		if (i == n)//소수임
		{
			list[++check] = n; 
		}
		n++;
	}
}
//재귀 함수를 이용한 이진 탐색
int search_binary(int key, int low, int high)
{
	int middle = (low + high) / 2;
	b_count++; //if문에서의 비교 횟수를 미리 더함
	if (key == list[middle]) { return middle; } 
	else if (key < list[middle]) { b_count++; search_binary(key, 0, middle - 1); }
	else if (key > list[middle]) { b_count++; search_binary(key, middle + 1, high); }
	else { b_count++; return -1; } //비교 실패했을 때
}


//보간 탐색
int search_interpolation(int key)
{
	int low, high, j;
	low = 0;
	high = MAX_SIZE - 1;
	while ((list[high] >= key) && (key > list[low])) 
	{
		i_count+=2; //while문에서 두 번 비교하므로 i_count값을 2 증가시킴.
		j = ((float)(key - list[low]) / (list[high] - list[low])*(high - low)) + low;
		i_count++;//if문에서의 비교 횟수를 미리 더함.
		if (key > list[j]) { low = j + 1; }
		else if (key < list[j]) { i_count++; high = j - 1; }
		else { i_count++; low = j; }
	}
	if (list[low] == key) { i_count++; return (low); } //탐색 성공
	else { i_count++; return -1; }//탐색 실패
}


int main()
{
	//이름 : 장보민
	//전공 : 사이버보안전공
	//학번 : 1871082
	int key;
	prime_generate(); //소수 생성 함수를 호출

	printf("Key = ");
	scanf("%d", &key);


	printf("\nBinary search\n");
	printf("\tIndex = ");
	printf("%d\n",search_binary(key,0,MAX_SIZE)); //이진 탐색 함수 호출
	printf("\tThe number of comparisons = %d\n",b_count);

	printf("\nInterpolation search\n");
	printf("\tIndex = ");
	printf("%d\n", search_interpolation(key)); //보간 탐색 함수 호출
	printf("\tThe number of comparisons = %d\n", i_count);

	return 0;
}