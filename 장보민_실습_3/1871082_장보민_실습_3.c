#include <stdlib.h>
#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b)) //최대값 찾는 매크로를 define

typedef struct Poly {
	int degree;
	int coef[100];
}polynomial; //다항식을 다룰 구조체를 정의

int get_large(polynomial poly1, polynomial poly2)  //poly1과 poly2 중 degree가 더 큰 것을 return 하는 함수
{
	return MAX(poly1.degree, poly2.degree);
}


polynomial poly_add1(polynomial A, polynomial B, polynomial C) { //다항식을 인자로 받아 더하는 함수. return값은 구조체값이다.
	int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	int degree_c = C.degree; //각각의 함수의 degree.
	while (Apos <= A.degree && Bpos <= B.degree) { //Apos가 A.degree와 같아질 때 까지,Bpos가 B의 degree와 같아질 때 까지 while문을 돈다.
		if (degree_a > degree_b) {// A차수 > B차수 일 때,
			C.coef[C.degree - Cpos++] = A.coef[A.degree - Apos++]; //최고차항이 배열의 끝값이므로, A의 최고차항부터 차례로 C에 copy해준다. 
			degree_a--; //한 번 copy할 때마다 degree를 낮춰준다.
		}
		else if (degree_a == degree_b) { // A항 == B항
			C.coef[C.degree - Cpos++] = A.coef[A.degree - Apos++] + B.coef[B.degree - Bpos++]; //A와 B의 coef를 더해준다.
			degree_a--; degree_b--;//한 번 더할 때 마다 degree를 낮춰준다.
		}
		else { // B항 > A항
			C.coef[C.degree - Cpos++] = B.coef[B.degree - Bpos++];//최고차항이 배열의 끝값이므로, B의 최고차항부터 차례로 C에 copy해준다. 
			degree_b--;//한 번 더할 때 마다 degree를 낮춰준다.
		}
	}
	return C; //C를 return한다.
}

int compute(polynomial poly3, int x) //polynomial 구조체와 int값을 인자로 받는 함수.
{
	int p = poly3.coef[0]; //coef의 0번째 값인 정수값을 변수 p에 저장한다.
	int xpower = 1;//xpower의 초기값을 1로 set한다.
	int n = poly3.degree;//for문을 반복할 횟수를 poly3의 degree로 설정한다.
	for (int i = 1; i <= n; i++) //for문을 통해 값을 계산
	{
		xpower = xpower * x; //for문을 반복할 때마다 x값을 갱신해준다.
		p += poly3.coef[i] * xpower; // 기존 p값에 poly3.coef[i]값과 xpower를 곱한 값을 더해준다.
	}
	return p; //p를 return 한다.

}


int main(void)
{
	FILE* fp; //파일 포인터
	int x = 0;//주어지는 x값
	polynomial poly1;
	polynomial poly2;
	polynomial poly3; //polynomial 구조체들 선언.

	fp = fopen("poly3.txt", "r"); // 자신의 환경에 맞는 파일 경로 입력

	fscanf(fp, "%d", &poly1.degree); //fscanf로 1번째 polynomail의 dgree를 불러옴

	printf("p(x) = ");

	int p1 = 0; //플러스를 출력할 때 필요한 변수
	for (int i = 0; i <= poly1.degree ; i++) //poly1 함수를 출력하는 for문
	{
		fscanf(fp, "%d", &poly1.coef[i]);//fscanf를 통해 파일에서 poly1의 coef를 받아온다.
		printf("%dx^%d ", poly1.coef[i], i);
		p1++;
		//플러스 문자를 출력하기 위한 if문
		if (p1 <= poly1.degree) 
			printf("+ ");
		else
			printf("\n");
	}
	
	fscanf(fp, "%d", &poly2.degree); //fsanf를 통해 파일에서 poly2의 degree를 받아온다.

	printf("q(x) = ");
	int p2 = 0; //플러스를 출력할 때 필요한 변수
	for (int i = 0; i <= poly2.degree ; i++)//poly2 함수를 출력하는 for문
	{
		fscanf(fp, "%d", &poly2.coef[i]);//fscanf를 통해 파일에서 poly2의 coef를 받아온다.
		printf("%dx^%d ", poly2.coef[i], i);
		p2++;
		//플러스 문자를 출력하기 위한 if문
		if (p2 <= poly2.degree)
			printf("+ ");
		else
			printf("\n");
	}

	fscanf(fp, "%d", &x); //fscanf를 통해 파일에서 x값을 받아온다.

	poly3.degree = get_large(poly1, poly2); //get_large함수를 통해 poly1,poly2 중에서 최고차항을 받아온다.
	poly3 = poly_add1(poly1, poly2, poly3); //poly_add1함수를 통해 poly1과 poly2의 합인 poly3를 받아온다.

	printf("\nr(x) = ");
	int p3 = 0; //플러스를 출력할 때 필요한 변수
	for (int i = 0; i <= poly3.degree ; i++) //for문을 통해 poly3를 출력한다.
	{
		printf("%dx^%d ", poly3.coef[i], i);
		p3++;
		//플러스 문자를 출력하기 위한 if문
		if (p3 <= poly3.degree)
			printf("+ ");
		else
			printf("\n");
	}

	printf("r(%d) = ", x); 
	int rvalue = compute(poly3, x); //rvalue에 poly3의 x에 x값을 대입한 결과를 저장한다.
	printf("%d\n", rvalue); //rvalue를 출력한다.

	fclose(fp);//파일을 닫는다.

}
