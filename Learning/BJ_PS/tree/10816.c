//https://sedangdang.tistory.com/24
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	int key;
	int cnt;
}TreeNode;

TreeNode* insert_Node(TreeNode* Root, int key)
{
	if (Root == NULL)
	{
		TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
		tmp->left = tmp->right = NULL;
		tmp->key = key;
		tmp->cnt = 1;

		return tmp;
	}

	if (key < Root->key)
		Root->left = insert_Node(Root->left, key);
	else if (key > Root->key)
		Root->right = insert_Node(Root->right, key);
	else if (key == Root->key)
		Root->cnt += 1;

	return Root;
}

TreeNode* Search(TreeNode* Root, int key)
{
	if (Root == NULL)
		return NULL;

	if (Root->key == key)
		return Root;
	else if (Root->key < key)
		return Search(Root->right, key);
	else
		return Search(Root->left, key);
}

int main()
{
	TreeNode* Root = NULL, * tmp = NULL;
	int N, M, i, j, e;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf(" %d", &e);
		Root = insert_Node(Root, e);
	}

	scanf(" %d", &M);

	for (i = 0; i < M; i++)
	{
		scanf(" %d", &e);
		tmp = Search(Root, e);

		if (tmp == NULL)
			printf("0 ");
		else
			printf("%d ", tmp->cnt);
	}

	return 0;
}