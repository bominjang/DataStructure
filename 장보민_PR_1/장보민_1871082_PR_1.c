#include <stdio.h>
#include <stdlib.h>

//연결리스트의 노드의 구조
typedef struct ListNode {
	int coef;
	int exp;
	struct ListNode* link;
}ListNode;

//연결리스트 헤더
typedef struct ListHeader {
	int length;																			//리스트 노드의 수를 저장하는 calumn
	ListNode* head;
	ListNode* tail;
}ListHeader;

//초기화 함수
ListHeader* init(ListHeader* plist)
{
	plist->length = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

//기존 노드의 끝에 노드를 넣는 함수
void insert_node_last(ListHeader* plist, int coef, int exp)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));								//새로운 노드 temp 할당
	if (temp == NULL) return -1;

	//전달받은 값들로 새로운 노드를 만듦.
	temp->coef = coef;
	temp->exp = exp;
	temp->link = NULL;																	//제일 마지막 노드의 link이므로
	if (plist->tail == NULL)															//노드가 하나도 없을 때.
	{
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;														//plist의 tail 노드의 link값을 temp로 바꿔줌.
		plist->tail = temp;																//마지막에 temp값을 붙여주는 것
	}
}

//list3 = list1+list2
ListHeader* poly_add(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3)
{
	ListNode* a = plist1->head;															//첫번째리스트 노드를 가리키는 포인터 a
	ListNode* b = plist2->head;															//두번째리스트 노드를 가리키는 포인터 b
	int sum;
	int p3_length = 0;																	//p3의 length를 count할 변수 
	while (a && b)																		//a와 b가 NULL이 아닐 때
	{
		//a의 차수와 b의 차수가 같을 때
		if (a->exp == b->exp) {
			sum = a->coef + b->coef;
			insert_node_last(plist3, sum, a->exp);
			a = a->link; b = b->link; 
		}

		//a의 차수가 b의 차수보다 높을 때
		else if (a->exp > b->exp) {
			insert_node_last(plist3, a->coef, a->exp);
			a = a->link;
		}

		//b의 차수가 a의 차수보다 높을 때
		else
		{
			insert_node_last(plist3, b->coef, b->exp);
			b = b->link;
		}
		p3_length++;
	}

	//a나 b 중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 결과 다항식으로 복사
	for (; a != NULL; a = a->link)
	{
		insert_node_last(plist3, a->coef, a->exp); p3_length++;
	}
	for (; b != NULL; b = b->link)
	{
		insert_node_last(plist3, b->coef, b->exp); p3_length++;
	}


	plist3->length = p3_length;
	return plist3;
}

//다항식을 읽어오는 함수. ListHeader point값과 FILE 포인터값을 인자로 가짐.
ListHeader* poly_read(ListHeader* plist, FILE* fp)
{
	int length, coef, exp;
	fscanf(fp, "%d ", &length);															//파일의 첫번째 값을 읽어와서 ListHeader의 length값에 할당
	plist->length = length;
	//length값만큼 for문을 반복하면서 insert_node_last함수를 호출하여 노드를 생성
	for (int i = 0; i < length; i++)
	{
		fscanf(fp, "%d %d ", &coef, &exp);
		insert_node_last(plist, coef, exp);
	}
	return plist;
}

//다항식의 값을 계산하는 함수
int poly_eval(ListHeader* plist, int value)
{
	ListNode* p = plist->head;															//전달받은 plist(ListHeader포인터값)의 head값을 ListNode포인터값 p에 대입.

	//각 변수들에 값을 할당
	int length = plist->length;
	int result = 0;

	//p가 NULL일때까지 while문을 반복
	while (p) {
		int xpower = 1;																	//while문을 돌 때마다 xpower를 1로 초기화.
		//p가 가리키는 노드의 exp값만큼 for문을 돌아서 xpower를 계산함.
		for (int i = 0; i < p->exp; i++)
		{
			xpower *= value;
		}
		result = result + p->coef * xpower;												//result는 while문을 돌 때마다 '항을 계산한 결과값'이 더해짐.
		p = p->link;																	//p가 다음 노드를 가리키도록 p값도 갱신해줌.
	}
	return result;																		//계산한 결과값을 return

}


void poly_print(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3)
{
	ListNode* p;																		//ListNode 포인터변수 p를 선언
	int length;																			//각 polynomial의 length를 저장할 int타입의 변수 length선언
	int plus = 0;																		//plus를 출력할 때 도움을 줄 plus변수. 매번 갱신돼야함.	

	//plist1에 대한 출력
	p = plist1->head; length = plist1->length;
	printf("p(x) = ");
	for (; p; p = p->link)
	{
		printf("%dx^%d ", p->coef, p->exp);
		plus++;
		if (length != plus) { printf("+ "); }
	}
	printf("\n");

	
	//plist2에 대한 출력
	plus = 0;
	p = plist2->head; length = plist2->length;
	printf("q(x) = ");
	for (; p; p = p->link)
	{
		printf("%dx^%d ", p->coef, p->exp);
		plus++;
		if (length != plus) { printf("+ "); }
	}
	printf("\n");

	//plist3에 대한 출력
	plus = 0;
	p = plist3->head; length = plist3->length;
	printf("r(x) = ");
	for (; p; p = p->link)
	{
		printf("%dx^%d ", p->coef, p->exp);
		plus++;
		if (length != plus) { printf("+ "); }
	}
	printf("\n");

}

void main()
{
	ListHeader list1, list2, list3;														//ListHeader선언.
	FILE* fp = fopen("poly5.txt", "r");													//읽어들여올 파일 선언,초기화

	//연결리스트의 초기화
	ListHeader* plist1 = init(&list1);
	ListHeader* plist2 = init(&list2);
	ListHeader* plist3 = init(&list3);

	//각 다항식의 헤더 노드를 가리키는 포인터(ListHeader 포인터)를 각 변수에 저장
	plist1 = poly_read(&list1, fp);
	plist2 = poly_read(&list2, fp);

	//두 다항식을 더하여 새로운 다항식 r(x)의 헤더 노드를 가리키는 포인터를 반환받아 저장.
	plist3 = poly_add(plist1, plist2, plist3);

	//각 다항식들을 출력
	poly_print(plist1, plist2, plist3);

	//x 값을 저장할 value, 계산 결과를 저장할 result 변수를 선언
	int value, result;

	fscanf(fp, "%d ", &value);															//file에서 value값을 불러오고
	result = poly_eval(plist1, value);													//result에 다항식을 계산한 값을 저장
	printf("p(%d) = %d\n", value, result);												//값 출력

	fscanf(fp, "%d ", &value);															//file에서 value값을 불러오고
	result = poly_eval(plist2, value);													//result에 다항식을 계산한 값을 저장
	printf("q(%d) = %d\n", value, result);												//값 출력

	fscanf(fp, "%d ", &value);															//file에서 value값을 불러오고
	result = poly_eval(plist3, value);													//result에 다항식을 계산한 값을 저장
	printf("r(%d) = %d\n", value, result);												//값 춮력								


	fclose(fp);																			//파일 닫기

}