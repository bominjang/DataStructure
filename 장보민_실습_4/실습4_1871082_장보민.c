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
	//���̹��������� 1871082 �庸��
	int n;
	int key[3];
	int result;


	printf("---------�Է�---------\n");
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

	printf("\n---------���---------\n");
	ListNode* p = head;

	printf("n = %d\n", n);
	printf("List = ");

	while (p != NULL)//p�� NULL�� �� ����
	{
		printf("%d ", p->data);
		p = p->link; //p�� ��ũ�� ��� ����.
	}
	printf("\n\n");


	for (int i = 0; i < 3; i++) {
		ListNode* q = head;
		printf("Key = %d", key[i]);
		q = remove_node(head, key[i]);


		if (answer) //remove_node���� 1�̸�
		{
			printf("\n");
		}
		else { //remove_node���� 0�̸�
			printf("\"Ű�� ����\"\n");
		}
		
		printf("List = ");
		while (q != NULL)//p�� NULL�� �� ����
		{
			printf("%d ", q->data);
			q = q->link; //p�� ��ũ�� ��� ����.
		}
		printf("\n\n");
	}

}

ListNode* insert_node(ListNode* head, int num)
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = num; //new_node�� data���� num�� ����.

	ListNode* p = head; //ListNode�� ����ų �����ͺ��� p�� �����ϰ�, head�� ����Ű���� �ʱ�ȭ

	if (head == NULL) //���鸮��Ʈ�� ���
	{
		head = new_node; //head�����Ϳ��� new_node�� �ּҸ� �־���
		new_node->link = NULL; //new_node�� link���� NULL�� set.
	}
	else {
		while (p->link != NULL)//p�� NULL�� �� ����
		{
			p = p->link; //p�� ��ũ�� ��� ����.
		}
		p->link = new_node;//�� ��忡 �������� ��, p�� link�� newnode�� �ּҰ����� �־���
		new_node->link = NULL;//newnode�� link�� NULL�� set
	}
	return head;
}

ListNode* remove_node(ListNode* head, int key) //node�� remove�ϴ� function
{
	ListNode* p = head; //ù��° ��带 ����Ű�� ������	
	ListNode* p2 = p->link; //p����� ���� ��带 ����Ű�� ������

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