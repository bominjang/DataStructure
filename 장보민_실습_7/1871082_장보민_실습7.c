#include<stdio.h>
#include<stdlib.h>

//TreeNode ����ü ����
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;
//node�� count�ϴ� �Լ�
int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
	{
		count = 1 + get_node_count(node->left) + get_node_count(node->right); //��͸� ����Ͽ� ��� ����� ������ ����.
	}
	return count;
}
//Ʈ���� ���̸� ���� �Լ�
int get_height(TreeNode* node)
{
	int height = -1;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right)); //��͸� ��뿩 Ʈ���� ���̸� ����.
	return height;
}
//��带 �߰��ϴ� �Լ�
void insert_node(TreeNode** root, int key)
{
	TreeNode* p, * t; //t�� ������, p�� t�� �θ���
	TreeNode* new; //n�� ������ ���ο� ���
	t = *root;
	p = NULL;

	while (t != NULL) //Ž�� : ���� ��ġ ã��
	{
		if (key == t->data) return; //key�� �̹� Ʈ�� �ȿ� ������ ���� �ȵ�.
		p = t;
		if (key < t->data) t = t->left;
		else t = t->right;
	}

	new = (TreeNode*)malloc(sizeof(TreeNode));
	if (new == NULL) return;
	new->data = key; //������ ����
	new->left = new->right = NULL;

	if (p != NULL) //�θ���� ��ũ ����.
		if (key < p->data) p->left = new;
		else p->right = new;
	else *root = new;
}
//�߼��� ����
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
	//���� : ���̹�����
	//�й� : 1871082
	//�̸� : �庸��
	TreeNode* root = NULL;
	int key; //key���� ������ ����
	int count; 
	printf("�Է��� �������� ���� : ");
	scanf("%d", &count);

	//count����ŭ ����.
	for (int i = 0; i < count; i++)
	{
		printf("������ :");
		//scanf�� key���� �޾ƿ�
		scanf("%d", &key);
		//root�� key�� ���ڷ� �Ѱܼ� insest_node�� ȣ��
		insert_node(&root, key);
		printf("��� ���� = %d\n", get_node_count(root));
		printf("���� = %d\n", get_height(root));
		printf("�߼��� ����=");
		Inorder(root);
		printf("\n");
	}
}