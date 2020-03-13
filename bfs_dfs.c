#include<stdio.h>

#define N 5
#define initial 1
#define waiting 2
#define visited 3

int queue[N],front=-1,rear=-1,stack[N],top=-1,state[N],c,reach[N];
void bfs(int ,int [N][N]);
void dfs(int , int [N][N]);
void enq(int );
int deq();
void push(int );
int pop();

int main()
{
	int mat[N][N] = {{0,1,0,1,0},{1,0,0,0,1},{0,0,0,1,0},{1,0,1,0,0},{0,1,0,0,0}};
	printf("bfs\n");	
	bfs(2,mat);
	printf("\n");
	printf("dfs\n");
	dfs(2,mat);
	printf("\n");
	if(c==1)
		printf("cyclic\n");
	else
		printf("acyclic\n");
	return 0;
}

void dfs(int s,int mat[N][N])
{
	int i,count=0;
	c=0;
	for(i=0;i<N;i++)
		state[i]=initial;
	for(i=0;i<N;i++)
		reach[i]=0;
	push(s);
	state[s]=waiting;
	reach[s]=1;
	while(top!=-1)
	{
		int v=pop();
		state[v]=visited;
		printf("%d\t",v);
		for(i=0;i<N;i++)
		{
			if(mat[v][i]==1 && state[i]==waiting)
				c=1;
			
			if(mat[v][i]==1 && state[i]==initial)
			{				
				push(i);
				reach[i]=1;
				state[i]=waiting;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		if(reach[i]==1)
		{	
			count++;
		}
	}
	if(count==N)
		printf("\nconnected");
	else
		printf("\ndisconnected");

}

void push(int s)
{
	top++;
	stack[top]=s;
}

int pop()
{
	int d=stack[top];
	top--;
	return d;
}

int deq()
{
	int d=queue[front];
	front++;
	return d;
}

void enq(int s)
{
	if(front==-1 && rear==-1)
	{
		front++;
		rear++;
	}
	else
	{
		rear++;
	}
	queue[rear]=s;
}

void bfs(int s,int mat[][N])
{
	int i;
	for(i=0;i<N;i++)
	{
		state[i]=initial;
	}
	enq(s);
	state[s]=waiting;
	while(front<=rear)
	{
		int v=deq();
		printf("%d\t",v);
		state[v]=visited;
		for(i=0;i<N;i++)
		{
			if(mat[v][i]==1 && state[i]==initial)
			{
				enq(i);
				state[i]=waiting;
			}
		}
	}

}
