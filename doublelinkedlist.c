#include <stdio.h>
#include <stdlib.h>
 
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head=NULL,*tail=NULL;

int count=0;

void insert1();
void insert2();
void insert3();
void display();
void search();
void delete();

int main()
{
	printf("1.insert at beginning\n2.insert at position i\n3.insert at end\n4.delete\n5.search\n6.display\n7.exit\n");
	while(1)
	{
		int choice;
		printf("enter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert1();
				break;
			case 2:
				insert2();
				break;
			case 3:
				insert3();
				break;
			case 4:
				delete();
				break;
			case 5:
				search();
				break;
			case 6:
				display();
				break;
			case 7:
				exit(-1);
			default:
				printf("choose a valid option\n");
		}


	}

	return 0;
}

void delete()
{

}

void search()
{
	int c=0,m;
	struct node *temp=head;
	if(temp==NULL)
	{
		printf("list empty\n");
		return;
	}
	printf("enter value to search : ");
	scanf("%d",&m);
	while(temp!=NULL)
	{
		if(temp->data==m)
		{
			printf("element found in position %d\n",c+1);
			return;
		}
		else
			temp=temp->next;
		c++;
	}
	printf("element not found\n");
}

void display()
{
	struct node *temp=head;
	if(temp==NULL)
		printf("list empty\n");
	else
	{
		printf("%d",temp->data);
		temp=temp->next;
		while(temp!=NULL)
		{
			printf("<->%d",temp->data);
			temp=temp->next;		
		}
	}
	printf("\n");
}

void insert1()
{
	int m;
	printf("enter value : ");
	scanf("%d",&m);
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=m;
	count++;
	if(head==NULL)
	{
		new->next=NULL;
		new->prev=NULL;
		head=new;
		tail=head;
	}
	else
	{
		new->next=head;
		new->prev=NULL;
		head=new;
	}
	printf("count : %d\n",count);
}

void insert2()
{
	int pos,m,i=2;
	struct node *new=(struct node *)malloc(sizeof(struct node));
	printf("Enter position to be inserted : ");
    	scanf("%d", &pos);
	struct node *temp=head;
	
	if ((head == NULL) && (pos != 1))
    	{
        	printf("Empty list cannot insert other than 1st position\n");
        	return;
    	}
	
	if ((pos < 1) || (pos > count + 1))
    	{
        	printf("Position out of range to insert\n");
        	return;
    	}

	if((head==NULL)&&(pos==1))
	{
		printf("enter value : ");
		scanf("%d",&m);
		new->data=m;
		//count++;
		new->next=NULL;
		new->prev=NULL;
		head=new;
		tail=head;
		//printf("count : %d\n",count);
	}
	else if((head!=NULL)&&(pos==1))
	{
		printf("enter value : ");
		scanf("%d",&m);		
		new->data=m;
		new->next=head;
		new->prev=NULL;
		temp->prev=new;
		head=new;
		//insert1();
	}
	else
	{
		printf("enter value : ");
		scanf("%d",&m);
		new->data=m;
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		new->prev=temp;
		new->next=temp->next;
		if(temp->next)
			temp->next->prev=new;
		temp->next=new;
	}
	count++;
	printf("count : %d\n",count);
}

void insert3()
{
	int m;
	printf("enter value : ");
	scanf("%d",&m);
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=m;
	count++;
	if(head==NULL)
	{
		new->next=NULL;
		new->prev=NULL;
		head=new;
	}
	else
	{
		new->prev=tail;
		tail->next=new;
		tail=new;
	}
	printf("count : %d\n",count);
}
