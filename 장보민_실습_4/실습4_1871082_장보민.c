#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;


ListNode* insert_node(ListNode* head, int num);

ListNode* remove_node(ListNode* head, int key);

int answer = 0;

int main(void)
{
	//사이버보안전공 1871082 장보민
	int n;
	int key[3];
	int result;


	printf("---------입력---------\n");
	printf("n = ");
	scanf("%d", &n);

	printf("List = ");
	int list[MAX] = {0};

	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	int h;
	scanf("%d ", &h);
	head->data = h;
	head->link = NULL;
	list[0] = h;

	for (int i = 1; i < n; i++)
	{
		scanf("%d", &list[i]);
		insert_node(head, list[i]);
	}

	printf("Key = ");
	scanf("%d", &key[0]);

	printf("Key = ");
	scanf("%d", &key[1]);

	printf("Key = ");
	scanf("%d", &key[2]);

	printf("\n---------출력---------\n");
	ListNode* p = head;

	printf("n = %d\n", n);
	printf("List = ");

	while (p != NULL)//p가 NULL일 때 까지
	{
		printf("%d ", p->data);
		p = p->link; //p의 링크를 계속 따라감.
	}
	printf("\n\n");


	for (int i = 0; i < 3; i++) {
		ListNode* q = head;
		printf("Key = %d", key[i]);
		q = remove_node(head, key[i]);


		if (answer) //remove_node값이 1이면
		{
			printf("\n");
		}
		else { //remove_node값이 0이면
			printf("\"키가 없음\"\n");
		}
		
		printf("List = ");
		while (q != NULL)//p가 NULL일 때 까지
		{
			printf("%d ", q->data);
			q = q->link; //p의 링크를 계속 따라감.
		}
		printf("\n\n");
	}

}

ListNode* insert_node(ListNode* head, int num)
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = num; //new_node의 data값에 num를 넣음.

	ListNode* p = head; //ListNode를 가리킬 포인터변수 p를 선언하고, head를 가리키도록 초기화

	if (head == NULL) //공백리스트인 경우
	{
		head = new_node; //head포인터에는 new_node의 주소를 넣어줌
		new_node->link = NULL; //new_node의 link값을 NULL로 set.
	}
	else {
		while (p->link != NULL)//p가 NULL일 때 까지
		{
			p = p->link; //p의 링크를 계속 따라감.
		}
		p->link = new_node;//끝 노드에 도착했을 때, p의 link를 newnode의 주소값으로 넣어줌
		new_node->link = NULL;//newnode의 link는 NULL로 set
	}
	return head;
}

ListNode* remove_node(ListNode* head, int key) //node를 remove하는 function
{
	ListNode* p = head; //첫번째 노드를 가리키는 포인터	
	ListNode* p2 = p->link; //p노드의 다음 노드를 가리키는 포인터

	while (p2->link != NULL) {
		if (head->data == key)
		{
			head = p->link;
			p = head;
			p2 = p2->link;
			answer = 1;
			return head;
		}
		else if (p2->data == key) {
			p->link = p2->link;
			answer = 1;
			return head;
		}
		p = p->link;
		p2 = p2->link;
	}
	answer = 0;
	return head;

}