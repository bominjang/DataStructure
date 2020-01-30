#include <stdlib.h>
#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b)) //�ִ밪 ã�� ��ũ�θ� define

typedef struct Poly {
	int degree;
	int coef[100];
}polynomial; //���׽��� �ٷ� ����ü�� ����

int get_large(polynomial poly1, polynomial poly2)  //poly1�� poly2 �� degree�� �� ū ���� return �ϴ� �Լ�
{
	return MAX(poly1.degree, poly2.degree);
}


polynomial poly_add1(polynomial A, polynomial B, polynomial C) { //���׽��� ���ڷ� �޾� ���ϴ� �Լ�. return���� ����ü���̴�.
	int Apos = 0, Bpos = 0, Cpos = 0; // �迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	int degree_c = C.degree; //������ �Լ��� degree.
	while (Apos <= A.degree && Bpos <= B.degree) { //Apos�� A.degree�� ������ �� ����,Bpos�� B�� degree�� ������ �� ���� while���� ����.
		if (degree_a > degree_b) {// A���� > B���� �� ��,
			C.coef[C.degree - Cpos++] = A.coef[A.degree - Apos++]; //�ְ������� �迭�� �����̹Ƿ�, A�� �ְ����׺��� ���ʷ� C�� copy���ش�. 
			degree_a--; //�� �� copy�� ������ degree�� �����ش�.
		}
		else if (degree_a == degree_b) { // A�� == B��
			C.coef[C.degree - Cpos++] = A.coef[A.degree - Apos++] + B.coef[B.degree - Bpos++]; //A�� B�� coef�� �����ش�.
			degree_a--; degree_b--;//�� �� ���� �� ���� degree�� �����ش�.
		}
		else { // B�� > A��
			C.coef[C.degree - Cpos++] = B.coef[B.degree - Bpos++];//�ְ������� �迭�� �����̹Ƿ�, B�� �ְ����׺��� ���ʷ� C�� copy���ش�. 
			degree_b--;//�� �� ���� �� ���� degree�� �����ش�.
		}
	}
	return C; //C�� return�Ѵ�.
}

int compute(polynomial poly3, int x) //polynomial ����ü�� int���� ���ڷ� �޴� �Լ�.
{
	int p = poly3.coef[0]; //coef�� 0��° ���� �������� ���� p�� �����Ѵ�.
	int xpower = 1;//xpower�� �ʱⰪ�� 1�� set�Ѵ�.
	int n = poly3.degree;//for���� �ݺ��� Ƚ���� poly3�� degree�� �����Ѵ�.
	for (int i = 1; i <= n; i++) //for���� ���� ���� ���
	{
		xpower = xpower * x; //for���� �ݺ��� ������ x���� �������ش�.
		p += poly3.coef[i] * xpower; // ���� p���� poly3.coef[i]���� xpower�� ���� ���� �����ش�.
	}
	return p; //p�� return �Ѵ�.

}


int main(void)
{
	FILE* fp; //���� ������
	int x = 0;//�־����� x��
	polynomial poly1;
	polynomial poly2;
	polynomial poly3; //polynomial ����ü�� ����.

	fp = fopen("poly3.txt", "r"); // �ڽ��� ȯ�濡 �´� ���� ��� �Է�

	fscanf(fp, "%d", &poly1.degree); //fscanf�� 1��° polynomail�� dgree�� �ҷ���

	printf("p(x) = ");

	int p1 = 0; //�÷����� ����� �� �ʿ��� ����
	for (int i = 0; i <= poly1.degree ; i++) //poly1 �Լ��� ����ϴ� for��
	{
		fscanf(fp, "%d", &poly1.coef[i]);//fscanf�� ���� ���Ͽ��� poly1�� coef�� �޾ƿ´�.
		printf("%dx^%d ", poly1.coef[i], i);
		p1++;
		//�÷��� ���ڸ� ����ϱ� ���� if��
		if (p1 <= poly1.degree) 
			printf("+ ");
		else
			printf("\n");
	}
	
	fscanf(fp, "%d", &poly2.degree); //fsanf�� ���� ���Ͽ��� poly2�� degree�� �޾ƿ´�.

	printf("q(x) = ");
	int p2 = 0; //�÷����� ����� �� �ʿ��� ����
	for (int i = 0; i <= poly2.degree ; i++)//poly2 �Լ��� ����ϴ� for��
	{
		fscanf(fp, "%d", &poly2.coef[i]);//fscanf�� ���� ���Ͽ��� poly2�� coef�� �޾ƿ´�.
		printf("%dx^%d ", poly2.coef[i], i);
		p2++;
		//�÷��� ���ڸ� ����ϱ� ���� if��
		if (p2 <= poly2.degree)
			printf("+ ");
		else
			printf("\n");
	}

	fscanf(fp, "%d", &x); //fscanf�� ���� ���Ͽ��� x���� �޾ƿ´�.

	poly3.degree = get_large(poly1, poly2); //get_large�Լ��� ���� poly1,poly2 �߿��� �ְ������� �޾ƿ´�.
	poly3 = poly_add1(poly1, poly2, poly3); //poly_add1�Լ��� ���� poly1�� poly2�� ���� poly3�� �޾ƿ´�.

	printf("\nr(x) = ");
	int p3 = 0; //�÷����� ����� �� �ʿ��� ����
	for (int i = 0; i <= poly3.degree ; i++) //for���� ���� poly3�� ����Ѵ�.
	{
		printf("%dx^%d ", poly3.coef[i], i);
		p3++;
		//�÷��� ���ڸ� ����ϱ� ���� if��
		if (p3 <= poly3.degree)
			printf("+ ");
		else
			printf("\n");
	}

	printf("r(%d) = ", x); 
	int rvalue = compute(poly3, x); //rvalue�� poly3�� x�� x���� ������ ����� �����Ѵ�.
	printf("%d\n", rvalue); //rvalue�� ����Ѵ�.

	fclose(fp);//������ �ݴ´�.

}
