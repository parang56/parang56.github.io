#include <stdio.h>
#include <string.h>

#define MAX 102

typedef struct Stack{
    char arr[MAX];
    int top;
}Stack;

void init_stack(Stack* stack) //스택 초기화: top=-1
{
    stack->top=-1;
}

int full(Stack* stack)
{
    return (stack->top+1) == MAX;
}

int empty(Stack* stack)
{
    return (stack->top)==-1;
}

void push(Stack* stack, char cha)
{
    if (full(stack))
        return;
    stack->arr[++stack->top] = cha;
}

char pop(Stack* stack)
{
    if (empty(stack))
        return -1;
    char popcha = stack->arr[stack->top--]; 
    return popcha;
}

int main(void)
{
    Stack stack;
    char text[MAX], checkcha;
    while(1)
    {
        init_stack(&stack); //for문 반복마다 stack 초기화
        int checknum=1;      //for문 반복마다 YES, NO를 결정할 변수 초기화
        fgets(text, sizeof(text),stdin);
        if(strcmp(text,".\n")==0)
            break;
        for(int j=0;j<strlen(text);j++)
        {
            if(text[j]=='(' || text[j]=='[')
                push(&stack, text[j]); //'(' , '[' 마다 stack에 push
            else if(text[j]==')' || text[j]==']')
            {
                checkcha = pop(&stack); //')' , ']'가 입력되면 top에 있는 문자 확인.
                if(text[j]==')' && checkcha != '(')     //text[j]==')'이고 top이 '('가 아니면, 성립이 안되서 checknum가 NO 값인 0이 된다. 
                {
                    checknum=0;
                    break;
                }
                if(text[j]==']' && checkcha != '[')     //text[j]==']'이고 top이 '['가 아니면, 성립이 안되서 checknum가 NO 값인 0이 된다. 
                {
                    checknum=0;
                    break;
                }
            }
        }
        if(!empty(&stack)) //스택이 비어있지 않다는건, '('이나 '['이 남아있는 상황이라는 것이므로 checknum가 NO 값인 0이 된다.
            checknum=0;
        if(checknum==0)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}