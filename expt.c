#include<stdio.h>
#include<stdlib.h>
#define size 30

char stack[size];
int top=-1;

void push(char x)
{
stack[++top]=x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int priority(char x)
{
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    else if(x=='^')
         return 3;
}
 
int isoperand(char ch) 
{ 
    if(ch>='0' && ch<='9')
    return 1;
    else
     return 0;
} 

int isoperator(char x)
{
  if(x=='^' || x=='*' || x=='+' || x=='/' || x=='-')
   return 1;
  else 
   return 0;
}
void intopos(char infix[size],char postfix[size])
{
  int i,j;
  char item,x;
  i=j=0;
  push('(');
  while(infix[j]!='\0')
  {
   j++;
  }
  infix[j]=')';
 
/* int m=0;
 while(infix[m]!='\0')
  {
   printf("%c",infix[m]);
   m++;

  }
*/

  int y=0;
  item=infix[y];

  while(item!='\0')
 {
  if(isoperand(item))
  {
   postfix[i]=item;

    i++;
   }
 
  else if(item == '(')
		{
			push(item);
		}
   else if(isoperator(item))
    {
      x=pop();
      while(isoperator(x)==1 && (priority(x)>=priority(item)))
       {
          postfix[i]=x;
           i++;
          x=pop();
       }
       push(x);
       push(item);
     }
    else if(item==')')
   {
      x=pop();
      while(x!='(')
      {
        postfix[i]=x;
        i++;
        x=pop();
        }
    }
     y++;
    	item = infix[y]; 

 }

 
	postfix[i] = '\0';

}

typedef struct tree
{
 char data;
 struct tree *left;
 struct tree *right;
}*pos;

pos stk[size];

pos newnode(char b)
{
 pos temp;
temp=(struct tree*)malloc(sizeof(struct tree));
temp->data=b;
temp->left=NULL;
temp->right=NULL;
return (temp);
}
void psh(pos temp)
{
 stk[++top]=temp;
}

pos pp()
{
  pos p;
 p=stk[top--];
 return (p);
}

void preorder(pos t)
{
if(t!=NULL)
{
 printf("%c",t->data);
 preorder(t->left);
 preorder(t->right);
 }
}


void exptree(char postfix[])
{
 int j;
 char item;
 pos temp;
 j=0;
 item=postfix[j];
 while(item!='\0')
  {
   if(isoperand(item))
    {
     temp=newnode(item);
     psh(temp);

     }
    else if(isoperator(item))
    {
     temp=newnode(item);
     temp->right=pp();
      temp->left=pp();
      psh(temp);
    }
   j++;
   item=postfix[j];
  }
 preorder(temp);
}
   int power(int n1, int n2)
   {
    int result=1;
    while (n1 != 0)
    {
        result *= n2;
        --n1;
    }
    return result;
 }
void postfixevaluation(char postfix[])
{
 int ch;
 int i=0;
  ch=postfix[i];
  int n1,n2,res;
  while(ch!='\0')
  {
    if(isoperand(ch))
     {
       push(ch-'0');
      }
    else if(isoperator(ch))
     {
              n1=pop();
              n2=pop();
      
      switch(ch) 
       {
         case '^':
           res=power(n1,n2);
          break;
         
         case '*':
          res=n2*n1;
          break;
        case '/':
          res=n2/n1;
          break;
        case '+':
          res=n2+n1;
          break;
        case '-':
          res=n2-n1;
          break;
        }
         push(res);
      }
      i++;
     ch=postfix[i];
     
   }

 printf("\n Result of Expression Evaluation %d\n",pop());

}

int main()
{
char infix[size],postfix[size];
printf("Enter the Expression\n");

scanf("%s",infix);

intopos(infix,postfix);
int k=0;
while(postfix[k]!='\0')
{
printf("%c",postfix[k]);
k++;
}
printf("\n");

exptree(postfix);
postfixevaluation(postfix);
}
