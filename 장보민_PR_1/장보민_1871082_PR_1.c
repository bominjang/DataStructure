#include <stdio.h>
#include <stdlib.h>

//���Ḯ��Ʈ�� ����� ����
typedef struct ListNode {
	int coef;
	int exp;
	struct ListNode* link;
}ListNode;

//���Ḯ��Ʈ ���
typedef struct ListHeader {
	int length;																			//����Ʈ ����� ���� �����ϴ� calumn
	ListNode* head;
	ListNode* tail;
}ListHeader;

//�ʱ�ȭ �Լ�
ListHeader* init(ListHeader* plist)
{
	plist->length = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

//���� ����� ���� ��带 �ִ� �Լ�
void insert_node_last(ListHeader* plist, int coef, int exp)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));								//���ο� ��� temp �Ҵ�
	if (temp == NULL) return -1;

	//���޹��� ����� ���ο� ��带 ����.
	temp->coef = coef;
	temp->exp = exp;
	temp->link = NULL;																	//���� ������ ����� link�̹Ƿ�
	if (plist->tail == NULL)															//��尡 �ϳ��� ���� ��.
	{
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;														//plist�� tail ����� link���� temp�� �ٲ���.
		plist->tail = temp;																//�������� temp���� �ٿ��ִ� ��
	}
}

//list3 = list1+list2
ListHeader* poly_add(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3)
{
	ListNode* a = plist1->head;															//ù��°����Ʈ ��带 ����Ű�� ������ a
	ListNode* b = plist2->head;															//�ι�°����Ʈ ��带 ����Ű�� ������ b
	int sum;
	int p3_length = 0;																	//p3�� length�� count�� ���� 
	while (a && b)																		//a�� b�� NULL�� �ƴ� ��
	{
		//a�� ������ b�� ������ ���� ��
		if (a->exp == b->exp) {
			sum = a->coef + b->coef;
			insert_node_last(plist3, sum, a->exp);
			a = a->link; b = b->link; 
		}

		//a�� ������ b�� �������� ���� ��
		else if (a->exp > b->exp) {
			insert_node_last(plist3, a->coef, a->exp);
			a = a->link;
		}

		//b�� ������ a�� �������� ���� ��
		else
		{
			insert_node_last(plist3, b->coef, b->exp);
			b = b->link;
		}
		p3_length++;
	}

	//a�� b ���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ��� ��� ���׽����� ����
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

//���׽��� �о���� �Լ�. ListHeader point���� FILE �����Ͱ��� ���ڷ� ����.
ListHeader* poly_read(ListHeader* plist, FILE* fp)
{
	int length, coef, exp;
	fscanf(fp, "%d ", &length);															//������ ù��° ���� �о�ͼ� ListHeader�� length���� �Ҵ�
	plist->length = length;
	//length����ŭ for���� �ݺ��ϸ鼭 insert_node_last�Լ��� ȣ���Ͽ� ��带 ����
	for (int i = 0; i < length; i++)
	{
		fscanf(fp, "%d %d ", &coef, &exp);
		insert_node_last(plist, coef, exp);
	}
	return plist;
}

//���׽��� ���� ����ϴ� �Լ�
int poly_eval(ListHeader* plist, int value)
{
	ListNode* p = plist->head;															//���޹��� plist(ListHeader�����Ͱ�)�� head���� ListNode�����Ͱ� p�� ����.

	//�� �����鿡 ���� �Ҵ�
	int length = plist->length;
	int result = 0;

	//p�� NULL�϶����� while���� �ݺ�
	while (p) {
		int xpower = 1;																	//while���� �� ������ xpower�� 1�� �ʱ�ȭ.
		//p�� ����Ű�� ����� exp����ŭ for���� ���Ƽ� xpower�� �����.
		for (int i = 0; i < p->exp; i++)
		{
			xpower *= value;
		}
		result = result + p->coef * xpower;												//result�� while���� �� ������ '���� ����� �����'�� ������.
		p = p->link;																	//p�� ���� ��带 ����Ű���� p���� ��������.
	}
	return result;																		//����� ������� return

}


void poly_print(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3)
{
	ListNode* p;																		//ListNode �����ͺ��� p�� ����
	int length;																			//�� polynomial�� length�� ������ intŸ���� ���� length����
	int plus = 0;																		//plus�� ����� �� ������ �� plus����. �Ź� ���ŵž���.	

	//plist1�� ���� ���
	p = plist1->head; length = plist1->length;
	printf("p(x) = ");
	for (; p; p = p->link)
	{
		printf("%dx^%d ", p->coef, p->exp);
		plus++;
		if (length != plus) { printf("+ "); }
	}
	printf("\n");

	
	//plist2�� ���� ���
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

	//plist3�� ���� ���
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
	ListHeader list1, list2, list3;														//ListHeader����.
	FILE* fp = fopen("poly5.txt", "r");													//�о�鿩�� ���� ����,�ʱ�ȭ

	//���Ḯ��Ʈ�� �ʱ�ȭ
	ListHeader* plist1 = init(&list1);
	ListHeader* plist2 = init(&list2);
	ListHeader* plist3 = init(&list3);

	//�� ���׽��� ��� ��带 ����Ű�� ������(ListHeader ������)�� �� ������ ����
	plist1 = poly_read(&list1, fp);
	plist2 = poly_read(&list2, fp);

	//�� ���׽��� ���Ͽ� ���ο� ���׽� r(x)�� ��� ��带 ����Ű�� �����͸� ��ȯ�޾� ����.
	plist3 = poly_add(plist1, plist2, plist3);

	//�� ���׽ĵ��� ���
	poly_print(plist1, plist2, plist3);

	//x ���� ������ value, ��� ����� ������ result ������ ����
	int value, result;

	fscanf(fp, "%d ", &value);															//file���� value���� �ҷ�����
	result = poly_eval(plist1, value);													//result�� ���׽��� ����� ���� ����
	printf("p(%d) = %d\n", value, result);												//�� ���

	fscanf(fp, "%d ", &value);															//file���� value���� �ҷ�����
	result = poly_eval(plist2, value);													//result�� ���׽��� ����� ���� ����
	printf("q(%d) = %d\n", value, result);												//�� ���

	fscanf(fp, "%d ", &value);															//file���� value���� �ҷ�����
	result = poly_eval(plist3, value);													//result�� ���׽��� ����� ���� ����
	printf("r(%d) = %d\n", value, result);												//�� ����								


	fclose(fp);																			//���� �ݱ�

}