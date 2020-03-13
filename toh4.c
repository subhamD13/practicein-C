#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
	int capacity;
	int top;
	int *a;
}*src,*aux,*dest;

int n,x;

struct node * createStack(int );
void toh(int , struct node *,struct node *,struct node *);
void push(struct node * ,int );
void moveDisks(struct node *,struct node *,char , char);
int pop(struct node *);
void display(struct node *,struct node *,struct node *,int );

int main()
{
	//struct node *src,*aux,*dest;
	printf("enter the no.of disks\n");
	scanf("%d",&n);
	printf("\n");
	src=createStack(n);
	aux=createStack(n);
	dest=createStack(n);
	
	toh(n,src,aux,dest);
	return 0;
}


struct node * createStack(int n)
{
	struct node *stack=(struct node *)malloc(sizeof(struct node));
	stack->capacity=n;
	stack->top=-1;	
	stack->a=(int *) malloc(n*sizeof(int));
	return stack;
}

void toh(int n,struct node *src,struct node *aux,struct node *dest)
{
	display(src,dest,aux,n);
	printf("\n");		
		
	int i;
	char s,a,d;
	x=pow(2,n)-1;
	//printf("total no.of moves = %d\n\n",x);
	/*if(n%2==0)
	{
		char temp=d;			
		d=a;
		a=temp;
	}*/
	printf("enter source\n");
	scanf(" %c",&s);
	
	printf("enter destination\n");
	scanf(" %c",&d);
	
	//printf("enter auxiliary\n");
	//scanf(" %c",&a);
	
	printf("\n");
	
	if(s=='A')
	{	
		for(i=n;i>=1;i--)
			push(src,i);
		if(d=='B')
		{	
			a='C';
			struct node *temp;
			temp=aux;
			aux=dest;
			dest=temp;
		}
		else if(d=='C')
			a='B';
		printf("Initial Configuration\n");
			display(src,aux,dest,n);
	}
	
	if(s=='B')
	{	
		for(i=n;i>=1;i--)
			push(aux,i);
	
		if(d=='A')
		{
			a='C';
			struct node *temp;
			temp=aux;
			aux=src;
			src=temp;
			
			struct node *temp1;
			temp1=dest;
			dest=aux;
			aux=temp1;
		
			printf("Initial Configuration\n");
			display(aux,src,dest,n);
		}		
				
		else if(d=='C')
		{
			a='A';
			struct node *temp;
			temp=aux;
			aux=src;
			src=temp;

			printf("Initial Configuration\n");
			display(aux,src,dest,n);
		}
	}

	if(s=='C')
	{	
		for(i=n;i>=1;i--)
			push(dest,i);

		if(d=='A')
		{
			a='B';
			struct node *temp;
			temp=src;
			src=dest;
			dest=temp;
		
			printf("Initial Configuration\n");
			display(aux,dest,src,n);
		}
		
		else if(d=='B')
		{
			a='A';
			struct node *temp;
			temp=src;
			src=dest;
			dest=temp;	

			struct node *temp1;
			temp1=aux;
			aux=dest;
			dest=temp1;
			
			printf("Initial Configuration\n");
			display(aux,dest,src,n);
		}
		
	}
	
	//printf("Initial Configuration\n");
	//display(src,aux,dest,n);	
	printf("\n");
	
	if(n%2==1)
	for(i=1;i<=x;i++)
	{
		if(i%3==1)
			moveDisks(src,dest,s,d);
		else if(i%3==2)
			moveDisks(src,aux,s,a);
		else if(i%3==0)
			moveDisks(aux,dest,a,d);
	}

	else if(n%2==0)
	for(i=1;i<=x;i++)
	{
		if(i%3==1)
			moveDisks(src,aux,s,a);
		else if(i%3==2)
			moveDisks(src,dest,s,d);
		else if(i%3==0)
			moveDisks(aux,dest,a,d);
	}

	printf("total no.of moves = %d\n\n",x);
}

void moveDisks(struct node *source,struct node *destination,char s,char d)
{
	int at=pop(source);
	int bt=pop(destination);
	if(at==INT_MIN)
	{	
		push(source,bt);
		//printf("move %d from %c to %c\n",bt,d,s);
	}
	else if(bt==INT_MIN)
	{
		push(destination,at);
                //printf("move %d from %c to %c\n",at,s,d);
	}
	else if(at>bt)
	{
		push(source,at);
		push(source,bt);
                //printf("move %d from %c to %c\n",bt,d,s);	
	}
	else
	{
		push(destination,bt);
		push(destination,at);
                //printf("move %d from %c to %c\n",at,s,d);

	}
	display(src,aux,dest,n);
}

void push(struct node *stack,int item)
{
	stack->a[++(stack->top)]=item;
}

int pop(struct node *stack)
{
	if(stack->top==-1)
		return INT_MIN;
	else
	{
		int temp=stack->a[stack->top];
		stack->a[stack->top]=0;
		(stack->top)--;
		return temp;
	}
}

void display(struct node *src,struct node *aux,struct node *dest,int n)
{
	int i;
	for(i=n-1;i>=0;i--)
	{	
		printf("%d\t",src->a[i]);
		printf("%d\t",aux->a[i]);
		printf("%d\t",dest->a[i]);
		printf("\n");
	}
	
		printf("--\t--\t--\n");
		printf("A\tB\tC\n\n");	

}
