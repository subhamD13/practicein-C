#include<stdio.h>
#include<stdlib.h>

struct snode
{
	char data;
	struct snode *next;
}*stack=NULL;

FILE *fp;
int balance();
void push(struct snode ** ,char );
char pop(struct snode ** );

int main()
{
	//char s[100];
	int r;
	//scanf("%s",s);
	//printf("%s\n",s);
	r=balance();
	if(r)
		printf("balanced\n");
	else
		printf("not balanced\n");
	fclose(fp);
	return 0;
}

int balance()
{
	char c;
	fp=fopen("input.c","r");
	c=getc(fp);
	int i=0;
	while(c!=EOF)
	{
		if(c=='"')
			while((c=getc(fp))!='"')
				continue;
		if(c=='/')
		{
			c=getc(fp);
			if(c=='/')
				while((c=getc(fp))!='\n')
					continue;
			else if(c=='*')
			{
				while((c=getc(fp))!='*')
					continue;	
				while((c=getc(fp))!='/')
					continue;
			}
		}
		if (c == '{' || c == '(' || c == '[')
        		push(&stack,c);
		else if(c == '}' || c == ')' || c == ']')
		{
			if(stack==NULL)
				return 0;
			char ch=pop(&stack);
			if(c==')' && ch!='(')
				return 0;
			if(c=='}' && ch!='{')
				return 0;
			if(c==']' && ch!='[')
				return 0;	
		}
		c=getc(fp);
		i++;
	}
	if(stack==NULL)
		return 1;
	else 
		return 0;
}

void push(struct snode **top,char ch)
{
	struct snode *new=(struct snode *)malloc(sizeof(struct snode));
	new->data=ch;	
	if(*top==NULL)
	{
		new->next=NULL;
		*top=new;
	}
	else
	{
		new->next=*top;
		*top=new;
	}
}

char pop(struct snode **top)
{
	struct snode *temp=*top;
	char ch=temp->data;
	*top=(*top)->next;
	free(temp);
	return ch;
}
