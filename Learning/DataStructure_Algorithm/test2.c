//스택을 연결리스트로 구현하기

//push X: 정수 X를 스택에 넣는 연산이다.
//pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size -> 증감을 이용한 단순한 구현
//full -> 연결리스트로 스택을 구현하면 full함수를 구현할 수 없다.
//empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
//peak: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node //노드 정의
{
    int data;
    struct Node *next;
}Node;
 
typedef struct Stack //Stack 구조체 정의
{
    Node *top;    //맨 앞 노드(가장 최근에 생성한 노드)
}Stack;

int peak(Stack *stack)
{
	Node *now;
	int re;
	if(stack->top==NULL)
		return -1;
	now=stack->top;
	re=now->data;
	return re;
}

void InitStack(Stack *stack)
{
    stack->top = NULL; //스택 초기화에서는 top을 NULL로 설정
}
 
int empty(Stack *stack)
{
    return stack->top == NULL;    //top이 NULL이면 빈 상태    
}
void push(Stack *stack, int data)
{
    Node *now = (Node *)malloc(sizeof(Node)); //노드 생성
    now->data = data;//데이터 설정
    now->next = stack->top;//now의 next링크를 현재 top으로 설정   
    stack->top = now;   //스택의 맨 앞은 now로 설정
}
int pop(Stack *stack)
{
    Node *now;
    int re;
    if (empty(stack))
        return -1;
	
    now = stack->top;//now를 top으로 설정
    re = now->data;//꺼낼 값은 now의 data로 설정
 
    stack->top = now->next;//top을 now의 next로 설정
    free(now);//필요없으니 메모리 해제
    return re;
}

int size(Stack *stack)
{
	int cnt;
	Node* p;
	p = stack->top;
	for(stack->top;stack->top!=NULL;p=next->p)
		cnt++;
	return cnt;
}

int main(void)
{
	Stack stack;
    InitStack(&stack);//스택 초기화
	char Get_Com[10];
	int N,pushnum;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",Get_Com);
		if(strcmp(Get_Com,"push")==0)
		{
			scanf("%d",&pushnum);
			push(&stack, pushnum);
		}
		else if(strcmp(Get_Com,"size")==0)
			printf("%d\n",size(&stack));
		else if(strcmp(Get_Com,"pop")==0)
			printf("%d\n",pop(&stack));
		else if(strcmp(Get_Com,"peak")==0)
			printf("%d\n",peak(&stack));
		else if(strcmp(Get_Com,"empty")==0)
			printf("%d\n",empty(&stack));
	}
    return 0;
}