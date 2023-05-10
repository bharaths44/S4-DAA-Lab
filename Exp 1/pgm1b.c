#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL, *tail=NULL, *pos=NULL;

int main()
{
	int c, n, j, m,size;
	clock_t t;
	double total_t;
	printf("Enter number of elements :");
	scanf("%d",&size);
	srand((unsigned)time(NULL)*getpid());
	for(int i=0;i<size;i++)
	{
		if(head==NULL)
		{
			head=(struct node*)malloc(sizeof(struct node));
			head->data=rand()%100;
			pos=head;
			tail=head;
		}
		else
		{
			tail->next=(struct node*)malloc(sizeof(struct node));
			tail=tail->next;
			tail->data=rand()%100;
			tail->next=NULL;
		}

		
	}
	
	
	//Deletion
	int i=0,b;
	printf("Enter position to be deleted:");
	scanf("%d", &m);
	pos=head;
	t=clock();
	if(m==1)
	{
		b=head->data;
		head=head->next;
		pos=head;
	}
	else
	{	
		while(i<m-1)
		{
			pos=pos->next;
			i++;
		}
		b=pos->next->data;
		pos->next=pos->next->next;
	}
	pos=head;
	printf("%d Deleted\n",b);
	t=clock()-t;
	total_t=(((double)t)/CLOCKS_PER_SEC);
	printf("Time taken :%f\n",total_t);
	
	//Next largest
	t=clock();
	pos=head;
	while(pos!=NULL)
	{
		if(pos->data>b)
		{
			j=pos->data;
			break;
		}
		else
			pos=pos->next;
	}
	while(pos!=NULL)
	{
		if(pos->data >b && pos->data<j)
		{
			j=pos->data;	
			pos=pos->next;
		}
	else
		pos=pos->next;
	}
	t=clock()-t;
	printf("\nThe next largest number is: %d", j);
	total_t=(((double)t)/CLOCKS_PER_SEC);
	printf("\nTime taken :%f\n",total_t);
}	

