#include <stdio.h>
#include <stdlib.h>

//¿¬°á¸®½ºÆ®ÀÇ ³ëµåÀÇ ±¸Á¶
typedef struct ListNode {
	int coef;
	int exp;
	struct ListNode* link;
}ListNode;

//¿¬°á¸®½ºÆ® Çì´õ
typedef struct ListHeader {
	int length;																			//¸®½ºÆ® ³ëµåÀÇ ¼ö¸¦ ÀúÀåÇÏ´Â calumn
	ListNode* head;
	ListNode* tail;
}ListHeader;

//ÃÊ±âÈ­ ÇÔ¼ö
ListHeader* init(ListHeader* plist)
{
	plist->length = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

//±âÁ¸ ³ëµåÀÇ ³¡¿¡ ³ëµå¸¦ ³Ö´Â ÇÔ¼ö
void insert_node_last(ListHeader* plist, int coef, int exp)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));								//»õ·Î¿î ³ëµå temp ÇÒ´ç
	if (temp == NULL) return -1;

	//Àü´Ş¹ŞÀº °ªµé·Î »õ·Î¿î ³ëµå¸¦ ¸¸µê.
	temp->coef = coef;
	temp->exp = exp;
	temp->link = NULL;																	//Á¦ÀÏ ¸¶Áö¸· ³ëµåÀÇ linkÀÌ¹Ç·Î
	if (plist->tail == NULL)															//³ëµå°¡ ÇÏ³ªµµ ¾øÀ» ¶§.
	{
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;														//plistÀÇ tail ³ëµåÀÇ link°ªÀ» temp·Î ¹Ù²ãÁÜ.
		plist->tail = temp;																//¸¶Áö¸·¿¡ temp°ªÀ» ºÙ¿©ÁÖ´Â °Í
	}
}

//list3 = list1+list2
ListHeader* poly_add(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3)
{
	ListNode* a = plist1->head;															//Ã¹¹øÂ°¸®½ºÆ® ³ëµå¸¦ °¡¸®Å°´Â Æ÷ÀÎÅÍ a
	ListNode* b = plist2->head;															//µÎ¹øÂ°¸®½ºÆ® ³ëµå¸¦ °¡¸®Å°´Â Æ÷ÀÎÅÍ b
	int sum;
	int p3_length = 0;																	//p3ÀÇ length¸¦ countÇÒ º¯¼ö 
	while (a && b)																		//a¿Í b°¡ NULLÀÌ ¾Æ´Ò ¶§
	{
		//aÀÇ Â÷¼ö¿Í bÀÇ Â÷¼ö°¡ °°À» ¶§
		if (a->exp == b->exp) {
			sum = a->coef + b->coef;
			insert_node_last(plist3, sum, a->exp);
			a = a->link; b = b->link; 
		}

		//aÀÇ Â÷¼ö°¡ bÀÇ Â÷¼öº¸´Ù ³ôÀ» ¶§
		else if (a->exp > b->exp) {
			insert_node_last(plist3, a->coef, a->exp);
			a = a->link;
		}

		//bÀÇ Â÷¼ö°¡ aÀÇ Â÷¼öº¸´Ù ³ôÀ» ¶§
		else
		{
			insert_node_last(plist3, b->coef, b->exp);
			b = b->link;
		}
		p3_length++;
	}

	//a³ª b ÁßÀÇ ÇÏ³ª°¡ ¸ÕÀú ³¡³ª°Ô µÇ¸é ³²¾ÆÀÖ´Â Ç×µéÀ» ¸ğµÎ °á°ú ´ÙÇ×½ÄÀ¸·Î º¹»ç
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

//´ÙÇ×½ÄÀ» ÀĞ¾î¿À´Â ÇÔ¼ö. ListHeader point°ª°ú FILE Æ÷ÀÎÅÍ°ªÀ» ÀÎÀÚ·Î °¡Áü.
ListHeader* poly_read(ListHeader* plist, FILE* fp)
{
	int length, coef, exp;
	fscanf(fp, "%d ", &length);															//ÆÄÀÏÀÇ Ã¹¹øÂ° °ªÀ» ÀĞ¾î¿Í¼­ ListHeaderÀÇ length°ª¿¡ ÇÒ´ç
	plist->length = length;
	//length°ª¸¸Å­ for¹®À» ¹İº¹ÇÏ¸é¼­ insert_node_lastÇÔ¼ö¸¦ È£ÃâÇÏ¿© ³ëµå¸¦ »ı¼º
	for (int i = 0; i < length; i++)
	{
		fscanf(fp, "%d %d ", &coef, &exp);
		insert_node_last(plist, coef, exp);
	}
	return plist;
}

//´ÙÇ×½ÄÀÇ °ªÀ» °è»êÇÏ´Â ÇÔ¼ö
int poly_eval(ListHeader* plist, int value)
{
	ListNode* p = plist->head;															//Àü´Ş¹ŞÀº plist(ListHeaderÆ÷ÀÎÅÍ°ª)ÀÇ head°ªÀ» ListNodeÆ÷ÀÎÅÍ°ª p¿¡ ´ëÀÔ.

	//°¢ º¯¼öµé¿¡ °ªÀ» ÇÒ´ç
	int length = plist->length;
	int result = 0;

	//p°¡ NULLÀÏ¶§±îÁö while¹®À» ¹İº¹
	while (p) {
		int xpower = 1;																	//while¹®À» µ¹ ¶§¸¶´Ù xpower¸¦ 1·Î ÃÊ±âÈ­.
		//p°¡ °¡¸®Å°´Â ³ëµåÀÇ exp°ª¸¸Å­ for¹®À» µ¹¾Æ¼­ xpower¸¦ °è»êÇÔ.
		for (int i = 0; i < p->exp; i++)
		{
			xpower *= value;
		}
		result = result + p->coef * xpower;												//result´Â while¹®À» µ¹ ¶§¸¶´Ù 'Ç×À» °è»êÇÑ °á°ú°ª'ÀÌ ´õÇØÁü.
		p = p->link;																	//p°¡ ´ÙÀ½ ³ëµå¸¦ °¡¸®Å°µµ·Ï p°ªµµ °»½ÅÇØÁÜ.
	}
	return result;																		//°è»êÇÑ °á°ú°ªÀ» return

}


void poly_print(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3)
{
	ListNode* p;																		//ListNode Æ÷ÀÎÅÍº¯¼ö p¸¦ ¼±¾ğ
	int length;																			//°¢ polynomialÀÇ length¸¦ ÀúÀåÇÒ intÅ¸ÀÔÀÇ º¯¼ö length¼±¾ğ
	int plus = 0;																		//plus¸¦ Ãâ·ÂÇÒ ¶§ µµ¿òÀ» ÁÙ plusº¯¼ö. ¸Å¹ø °»½ÅµÅ¾ßÇÔ.	

	//plist1¿¡ ´ëÇÑ Ãâ·Â
	p = plist1->head; length = plist1->length;
	printf("p(x) = ");
	for (; p; p = p->link)
	{
		printf("%dx^%d ", p->coef, p->exp);
		plus++;
		if (length != plus) { printf("+ "); }
	}
	printf("\n");

	
	//plist2¿¡ ´ëÇÑ Ãâ·Â
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

	//plist3¿¡ ´ëÇÑ Ãâ·Â
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
	ListHeader list1, list2, list3;														//ListHeader¼±¾ğ.
	FILE* fp = fopen("poly5.txt", "r");													//ÀĞ¾îµé¿©¿Ã ÆÄÀÏ ¼±¾ğ,ÃÊ±âÈ­

	//¿¬°á¸®½ºÆ®ÀÇ ÃÊ±âÈ­
	ListHeader* plist1 = init(&list1);
	ListHeader* plist2 = init(&list2);
	ListHeader* plist3 = init(&list3);

	//°¢ ´ÙÇ×½ÄÀÇ Çì´õ ³ëµå¸¦ °¡¸®Å°´Â Æ÷ÀÎÅÍ(ListHeader Æ÷ÀÎÅÍ)¸¦ °¢ º¯¼ö¿¡ ÀúÀå
	plist1 = poly_read(&list1, fp);
	plist2 = poly_read(&list2, fp);

	//µÎ ´ÙÇ×½ÄÀ» ´õÇÏ¿© »õ·Î¿î ´ÙÇ×½Ä r(x)ÀÇ Çì´õ ³ëµå¸¦ °¡¸®Å°´Â Æ÷ÀÎÅÍ¸¦ ¹İÈ¯¹Ş¾Æ ÀúÀå.
	plist3 = poly_add(plist1, plist2, plist3);

	//°¢ ´ÙÇ×½ÄµéÀ» Ãâ·Â
	poly_print(plist1, plist2, plist3);

	//x °ªÀ» ÀúÀåÇÒ value, °è»ê °á°ú¸¦ ÀúÀåÇÒ result º¯¼ö¸¦ ¼±¾ğ
	int value, result;

	fscanf(fp, "%d ", &value);															//file¿¡¼­ value°ªÀ» ºÒ·¯¿À°í
	result = poly_eval(plist1, value);													//result¿¡ ´ÙÇ×½ÄÀ» °è»êÇÑ °ªÀ» ÀúÀå
	printf("p(%d) = %d\n", value, result);												//°ª Ãâ·Â

	fscanf(fp, "%d ", &value);															//file¿¡¼­ value°ªÀ» ºÒ·¯¿À°í
	result = poly_eval(plist2, value);													//result¿¡ ´ÙÇ×½ÄÀ» °è»êÇÑ °ªÀ» ÀúÀå
	printf("q(%d) = %d\n", value, result);												//°ª Ãâ·Â

	fscanf(fp, "%d ", &value);															//file¿¡¼­ value°ªÀ» ºÒ·¯¿À°í
	result = poly_eval(plist3, value);													//result¿¡ ´ÙÇ×½ÄÀ» °è»êÇÑ °ªÀ» ÀúÀå
	printf("r(%d) = %d\n", value, result);												//°ª ­‹·Â								


	fclose(fp);																			//ÆÄÀÏ ´İ±â

}