#include<stdio.h>
#include<stdlib.h>

//TreeNode 구조체 생성
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;
//node를 count하는 함수
int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
	{
		count = 1 + get_node_count(node->left) + get_node_count(node->right); //재귀를 사용하여 모든 노드의 개수를 센다.
	}
	return count;
}
//트리의 높이를 세는 함수
int get_height(TreeNode* node)
{
	int height = -1;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right)); //재귀를 사용여 트리의 높이를 센다.
	return height;
}
//노드를 추가하는 함수
void insert_node(TreeNode** root, int key)
{
	TreeNode* p, * t; //t는 현재노드, p는 t의 부모노드
	TreeNode* new; //n은 삽입할 새로운 노드
	t = *root;
	p = NULL;

	while (t != NULL) //탐색 : 삽입 위치 찾기
	{
		if (key == t->data) return; //key가 이미 트리 안에 있으면 삽입 안됨.
		p = t;
		if (key < t->data) t = t->left;
		else t = t->right;
	}

	new = (TreeNode*)malloc(sizeof(TreeNode));
	if (new == NULL) return;
	new->data = key; //데이터 복사
	new->left = new->right = NULL;

	if (p != NULL) //부모노드와 링크 연결.
		if (key < p->data) p->left = new;
		else p->right = new;
	else *root = new;
}
//중순위 운행
void Inorder(TreeNode* root)
{
	if (root)
	{
		Inorder(root->left);		//L
		printf("%d ", root->data);	//V
		Inorder(root->right);		//R
	}
}

int main()
{
	//전공 : 사이버보안
	//학번 : 1871082
	//이름 : 장보민
	TreeNode* root = NULL;
	int key; //key값을 저장할 변수
	int count; 
	printf("입력할 데이터의 개수 : ");
	scanf("%d", &count);

	//count값만큼 돈다.
	for (int i = 0; i < count; i++)
	{
		printf("데이터 :");
		//scanf로 key값을 받아옴
		scanf("%d", &key);
		//root와 key를 인자로 넘겨서 insest_node를 호출
		insert_node(&root, key);
		printf("노드 개수 = %d\n", get_node_count(root));
		printf("높이 = %d\n", get_height(root));
		printf("중순위 운행=");
		Inorder(root);
		printf("\n");
	}
}