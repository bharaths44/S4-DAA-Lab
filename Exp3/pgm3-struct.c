#include<stdio.h>
#include<stdlib.h>

struct item
{
	int no;
	float weight;
	float profit;
	float ratio;
	float qty;
};


void swap(struct item *r1,struct item *r2)
{
	struct item temp;
	temp=*r1;
	*r1=*r2;
	*r2=temp;
}


void knapsack(int m,struct item items[],int n)
{
	double tp=0;
	int i,j=0,t[n];
	for(i=0;i<n;i++)
		items[i].qty=0.0;
	double u=m;
	
	//Comparison of weight and capacity
	for(i=0;i<n;i++)
	{
		if(items[i].weight>u)
			break;
		else
		{
			items[i].qty=1.0;
			tp+=items[i].profit;
			u=u-items[i].weight;		
		}
	}
	
	
	if(i<n)
		items[i].qty=u/items[i].weight;
	tp=tp+(items[i].qty*items[i].profit);
	
	//Sorting based on object number
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(items[i].no > items[j].no)
				swap(&items[i],&items[j]);
				
		}
	}
	
	printf("\nSOLUTION SET: \n");
	printf("Item number\tQuantity taken\n");
	for(i=0;i<n;i++)
		printf("   %d\t\t  %lf\n",items[i].no,items[i].qty);
	printf("\nTotal profit = %lf\n",tp);
}


void main()
{
	int n,i,m;
	printf("\n***************  Knapsack Problem  ***************\n");
	printf("Enter number of items : ");
	scanf("%d",&n);
	struct item items[n];
	printf("Enter capacity: ");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		items[i].no=i+1;
		printf("\nEnter for item %d \n",i+1);
		printf("Weight :");
		scanf("%f",&items[i].weight);
		printf("Profit : ");	
		scanf("%f",&items[i].profit);
		printf("\n");	
	}
	
	//Ratio calculation
	for(i=0;i<n;i++)
	{
		items[i].ratio= items[i].profit/items[i].weight ;
	}
	
	//Sorting based on ratio
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(items[i].ratio < items[j].ratio)
				swap(&items[i],&items[j]);
		}
	}
	knapsack(m,items,n);
}

			
						
