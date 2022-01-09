#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node //노드 정의
{
	int index;
	int height;
	struct Node *next;
}Node;

typedef struct Stack //스택 구조체 정의
{
	Node* top; //맨 앞 노드
}Stack;

void push(int height, int index, Stack* stack)
{

	Node* newnode = (Node*)malloc(sizeof(Node)); //노드 생성 (동적할당)
	newnode->height = height; //높이 설정
	newnode->index = index; //인덱스 설정
	newnode->next = stack->top; //newnode의 next링크를 현재 top으로 설정
	stack->top = newnode; //스택의 맨 앞 newnode로 설정
}

void InitStack(Stack *stack)
{
    stack->top = NULL; //스택 초기화에서는 top을 NULL로 설정
}

int peak(Stack* stack)
{
	if (stack->top == NULL)
		return -1;
	return stack->top->height;
}

void pop(Stack* stack)
{
	Node* now = stack->top; //now를 top으로 설정
	stack->top = now->next; //top을 now의 next로 설정
	free(now);              //필요없으니 메모리 해제
}

int main(void)
{
	Stack* stack = (Stack *)malloc(sizeof(Stack));
	InitStack(stack);// 스택 초기화
	
	int N;
	scanf("%d", &N);

	for (int i=0; i<N; i++)
	{
		int h;
		scanf("%d", &h);
		if (i==0) //첫 번째 경우 무조건 0 출력
		{
			push(h, i+1, stack); //push(높이, 인덱스, 스택)
			printf("0 ");
			continue; //아래 코드 무시 (바로 i=1 실행)
		}
		else
		{
			if (peak(stack)>h) //스택의 맨 위 높이 > 방금 입력한 높이인 경우
			{
				printf("%d ", stack->top->index); //맨 위 높이의 인덱스 출력
				push(h, i+1, stack); //비교, 출력 후 스택에 방금 입력한 것들 push
			}

			else if (peak(stack)<=h) //스택의 맨 위 높이 <= 방금 입력한 높이인 경우
			{
				while (peak(stack)<=h) 
				{
					pop(stack); //peak(stack)>h인 경우 밑에 if와 else문으로 탈출
					
					if (stack->top == NULL) //pop을 끝까지 했을 경우 (스택에 남아있는 것이 없는 경우)
						break;
				}
				if (stack->top != NULL) //stack->top!=NULL(스택에 숫자 남아있는 경우)이고 peak(stack)>h인 경우이므로 peak(stack)>h의 인덱스 출력
				{
					printf("%d ", stack->top->index);
					push(h, i + 1, stack); //인덱스 출력 후 스택에 방금 입력한 것들 push
				}
				else //stack->top==NULL
				{
					printf("0 "); //peak(stack)>h인 경우가 없으므로 0 출력
					push(h, i + 1, stack);
				}
			}
		}
	}
    return 0;
}