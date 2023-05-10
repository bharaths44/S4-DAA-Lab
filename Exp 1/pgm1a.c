#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int next(int a[],int n,int t)
{	
	int i,larg;
	for(i=0;i<n-1;i++)
	{
		if(a[i]>t)
		{
			larg=a[i];
			break;
		}
	}
	for(i=0;i<n-1;i++)
	{
		if(a[i]>t && larg>a[i])
			larg=a[i];
	}
	return larg;
}

int main()
{
	int n,i,p,l,j;
	int *a;
	double total_t;
	printf("Enter number of elements :");
	scanf("%d",&n);
	a = (int*)malloc(sizeof(int)*n);
    srand( (unsigned) time(NULL) * getpid());
    if(a != NULL)
    {
        for(j =0;j<n; j++)
            a[j] = rand()%100;
    }
    
    //Deletion
	printf("Enter which position element to remove: ");
	scanf("%d",&p);
	printf("Deleted element is %d\n",a[p-1]);
	clock_t t;
	t=clock();
	j=a[p-1];
	for(i=p-1;i<n-1;i++)
		a[i]=a[i+1];
	t=clock()-t;
	total_t=(((double)t)/CLOCKS_PER_SEC);
	printf("%f to delete\n\n",total_t);
	
	//Next largest
	t=clock();
	l=next(a,n,j);
	t=clock()-t;
	total_t=(((double)t)/CLOCKS_PER_SEC);
	printf("The next largest element is %d\n",l);
	printf("%f to find next largest\n",total_t);
	return 0;
}



