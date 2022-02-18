#include <stdio.h>
#include <stdlib.h>

//트리 노드 정의
typedef struct TreeNode{
	char ele;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

//새로운 노드 생성
TreeNode *New_TreeNode(char data)
{
	TreeNode *New = (TreeNode*)malloc(sizeof(TreeNode));
	New->ele = data;
	New->left = NULL; New->right = NULL;
	return New;
}

//트리 검색 함수
TreeNode *Search_TreeNode(TreeNode *TN, char data)
{
	if(TN != NULL)
	{
		if(TN->ele == data)
			return TN;
		else
		{
			TreeNode *temp = Search_TreeNode(TN->left, data);
			if(temp != NULL)
				return temp;
			
			return Search_TreeNode(TN->right, data);
		}
		
	}
	return NULL;
}

//data1이 부모 노드, data2가 왼쪽 자식 노드, data3가 오른쪽 자식 노드
void Insert_TreeNode(TreeNode *TN, char data1, char data2, char data3)
{
	TN->ele = data1;
	if(data2 != '.')
		TN->left = New_TreeNode(data2);
	if(data3 != '.')
		TN->right = New_TreeNode(data3);
}

//전위 순회
void Preorder_Traversal(TreeNode *TN)
{
	if(TN == NULL)
		return;
	printf("%c",TN->ele);
	Preorder_Traversal(TN->left);
	Preorder_Traversal(TN->right);
}

//중위 순회
void Inorder_Traversal(TreeNode *TN)
{
	if(TN == NULL)
		return;
	Inorder_Traversal(TN->left);
	printf("%c",TN->ele);
	Inorder_Traversal(TN->right);
}

//후위 순회
void Postorder_Traversal(TreeNode *TN)
{
	if(TN == NULL)
		return;
	Postorder_Traversal(TN->left);
	Postorder_Traversal(TN->right);
	printf("%c",TN->ele);
}

int main(void)
{
	int N;
	TreeNode *Tree = New_TreeNode(NULL); 
	TreeNode *Temp_Node;
	
	scanf("%d",&N);
	getchar();
	for(int i=0; i<N; i++)
	{
		char parent, left, right;
		scanf("%c %c %c",&parent,&left,&right);
		getchar();
		Temp_Node = Search_TreeNode(Tree, parent);
		if(Temp_Node == NULL)
			Insert_TreeNode(Tree, parent, left ,right);
		else
			Insert_TreeNode(Temp_Node, parent, left, right);
	}
	Preorder_Traversal(Tree); printf("\n");
	Inorder_Traversal(Tree); printf("\n");
	Postorder_Traversal(Tree); printf("\n");
	
	return 0;
}