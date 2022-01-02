//숫자를 하나씩 스캔 받아서 차례차례 수열이 만들어지는지 안 되는지 확인하는 풀이 

#include <stdio.h>
#define MAX 100000

int main(void)
{
	int i,n,k,stkIdx=0,resIdx=0,max=0;
	int stack[MAX];
	char res[MAX*2];
	scanf("%d",&n);
	while(n--) //while(0)이 되면 바로 멈춤
	{
		scanf("%d",&k);
		if(k>max)
		{
			for(i=max;i<k;i++)
			{
				stack[stkIdx++]=i+1; //스택 쌓기
				res[resIdx++]='+'; // '+' 저장
			}
			max=k; 
		}
		
		//k<max인 경우 stack[stkIdx]의 바로 전 경우가 k와 일치하지 않는 이상 수열을 만들 수 없음
		//stack[stkIdx-1]!=k 이면 max와 입력한 수 사이의 출력 안한 숫자가 있다는 뜻
		else if(k<max && stack[stkIdx-1]!=k) 
		{
			printf("NO\n");
			return 0;
		}
		
		//k==max
		stkIdx--; //한 숫자의 push들이 끝나면(+를 다 입력하면), 항상 pop이 일어나야함.
		res[resIdx++]='-'; //마찬가지로 항상 pop하면서 '-' 출력.
	}
	
	for(i=0;i<resIdx;i++)
		printf("%c\n",res[i]);
	return 0;
}

//숫자를 한번에 스캔 받아서 arr에 넣은 다음 arr와 stack을 비교해가면서 결과를 도출
//stack[top]이 arr[idx] 보다 낮으면 push, 같으면 pop, 크면 "NO"

#include <stdio.h>
#define MAX 100000

int stack[MAX];
char res[MAX*2];
int top=-1;

int main(void)
{
	int n,num=0,idx=0,res_idx=0;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int k=n*2;
	while(k--) //while(0)이 되면 바로 멈춤
	{
		//stack[top]이 arr[idx]보다 낮은 경우 (push)
		if(top==-1 || stack[top]<arr[idx])
		{
			stack[++top]=++num; //push
			res[res_idx++]='+';
		}
		
		//stack[top]이 arr[idx]와 같은 경우 (pop)
		else if(stack[top] == arr[idx])
		{
			top--; //pop
			res[res_idx++]='-';
			idx++; //배열의 다음 숫자로 넘어감
		}
		
		//stack[top]이 arr[idx]보다 큰 경우 ("NO")
		else
		{
			printf("NO"); //수열을 만들 수가 없음
			return 0;
		}
	}
	
	for(int i=0;i<res_idx;i++)
		printf("%c\n",res[i]);
	return 0;
}