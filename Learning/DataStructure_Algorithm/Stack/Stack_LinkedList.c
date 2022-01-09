//스택을 연결리스트로 구현하기

//push X: 정수 X를 스택에 넣는 연산이다.
//pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size -> 단순한 구현
//full -> 연결리스트로 스택을 구현하면 full함수를 구현할 수 없다.
//empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
//peak: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stacksize=0;

typedef struct Stack{ //스택 구현할 연결리스트 노드 구조체 정의
	int data;
	struct Stack* link; //다음 노드를 가리키는 포인터 변수
}Stack;

Stack* top; //top 노드를 가리킬 포인터 변수, 기본 값은 NULL
//Stack* top을 전역으로 설정하므로 함수들이 (Stack* stack)을 받을 필요가 없어진다.

int empty()
{
	if(top==NULL) //기본 값이 NULL. 다른 스택 구현 예로 top==-1 상태
		return 1;
	return 0;
}

void push(int num)
{
	Stack* newnode = (Stack*)malloc(sizeof(Stack)); //동적할당
	newnode->data=num; //newnode의 data값에 num값 저장
	newnode->link=top; //newnode의 link에 맨 위의 노드 주소 저장(top이 맨 위의 노드 주소를 갖고 있음)
	top=newnode; //newnode가 맨위 노드이므로 값 넣어주기
	stacksize++;
}

int pop()
{
	if(empty()==1)
		return -1;
	//비어있지 않은 경우
	Stack* temp = top; //temp 포인터 변수를 선언해 맨 위의 노드 주소값 저장
	int newdata = temp->data; //data 변수 새로 선언: newdata, 맨 위의 노드 데이터 저장
	top=temp->link; //top 포인터에 맨 위에서 두번째에 있는 노드의 주소값 저장
	free(temp); //맨 위 노드 제거
	stacksize--; //크기 1 감소
	return newdata;
}

int size()
{
	return stacksize;
}

//int full() -> 연결리스트는 스택의 크기에 제약이 없으므로 full 함수 구현이 불가능하다.

int peak()
{
	if(empty()==1)
		return -1;
	return top->data;
}

int main(void)
{
	char Get_Com[10];
	int N,pushnum;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",Get_Com);
		if(strcmp(Get_Com,"push")==0)
		{
			scanf("%d",&pushnum);
			push(pushnum);
		}
		else if(strcmp(Get_Com,"pop")==0)
			printf("%d\n",pop());
		else if(strcmp(Get_Com,"empty")==0)
			printf("%d\n",empty());
		else if(strcmp(Get_Com,"peak")==0)
			printf("%d\n",peak());
		else if(strcmp(Get_Com,"size")==0)
			printf("%d\n",size());
	}
	return 0;
}