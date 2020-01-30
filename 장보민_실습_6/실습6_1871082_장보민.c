#include<stdio.h>
#include<stdlib.h>

//TreeNode ����ü
typedef struct TreeNode {
	int data; //data�� ��� ���
	struct TreeNode* left, * right; //�ڽ� ������ ����Ű�� ���
}TreeNode;

//������. ���ڷ� �ϰ�; �����ڷ� 23�������� �ִ� ������ �����߽��ϴ�!
TreeNode n1 = { '3', NULL, NULL };
TreeNode n2 = { '2', NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { '4', NULL, NULL };
TreeNode n5 = { '2', NULL, NULL };
TreeNode n6 = { '/', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode n8 = { '2', NULL, NULL };
TreeNode n9 = { '3', NULL, NULL };
TreeNode n10 = { '5', NULL, NULL };
TreeNode n11 = { '*', &n9, &n10 };
TreeNode n12 = { '2', NULL, NULL };
TreeNode n13 = { '+', &n11, &n12 };
TreeNode n14 = { '+', &n8, &n13 };
TreeNode n15 = { '*', &n7, &n14 };
TreeNode* exp = &n15;

//�߼��� ����
Inorder(TreeNode* root)
{
	if (root)
	{
		Inorder(root->left);		//L
		printf("%c ", root->data);	//V
		Inorder(root->right);		//R
	}
}
//������ ����
preorder(TreeNode* root)
{
	if (root) {
		printf("%c ", root->data);	//V
		preorder(root->left);		//L
		preorder(root->right);		//R
	}

}
//�ļ��� ����
postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);		//L
		postorder(root->right);		//R
		printf("%c ", root->data);	//V
	}
}

tripleorder(TreeNode* root)
{
	if (root)
	{
		printf("%c ", root->data);	
		tripleorder(root->left);
		printf("%c ",root->data);
		tripleorder(root->right);
		printf("%c ", root->data);	
	}
}

void main()
{
	//���� : ���̹�����
	//�й� : 1871082
	//�̸� : �庸��

	printf("inorder = ");
	Inorder(exp);
	printf("\n");

	printf("preorder = ");
	preorder(exp);
	printf("\n");

	printf("postorder = ");
	postorder(exp);
	printf("\n");

	printf("tripleorder = ");
	tripleorder(exp);
	printf("\n");
}