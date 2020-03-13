#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char data;
	struct node *next;
}*top1=NULL,*top2=NULL,*top3=NULL;


void push(struct node ** , char );
char pop(struct node ** );

int main()
{
	char s[100],ch,ch1,ch3;
	int i,n,flag=0;
	printf("enter string\n");
	scanf("%s",s);
	n=strlen(s);
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		push(&top1,s[i]);
		push(&top2,s[i]);
	}
	
	while(top2!=NULL)
	{	
		ch=pop(&top2);
		printf("%c popped from stack2\n",ch);
		push(&top3,ch);
	}		
	
	i=0;	

	while(i<n)
	{
		ch1=pop(&top1);
		printf("%c popped from stack1\n",ch1);
		ch3=pop(&top3);
		printf("%c popped from stack3\n",ch3);
		if(ch1!=ch3)
		{	
			flag=1;
		}
		i++;

	}
	if(flag==1)	
		printf("not palindrome\n");
	else
		printf("palindrome\n");

	return 0;
}

void push(struct node **top,char ch)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=ch;
	if(*top==NULL)
	{
		*top=new;
		new->next==NULL;
	}		

	else
	{
		new->next=*top;
		*top=new;
	}
}

char pop(struct node **top)
{
	struct node *temp=*top;
	char ch=temp->data;
	*top=(*top)->next;
	free(temp);
	return ch;
}








