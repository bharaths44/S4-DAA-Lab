#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) 
    {
    	if (arr[j] < pivot)
		{
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quicksort(int *arr,int low,int high)
{
	 if (low < high)
	 {
        	int pi = partition(arr, low, high);
        	quicksort(arr, low, pi - 1);
        	quicksort(arr, pi + 1, high);
    }
}


void bubblesort(int lim,int *arr)
{
	int i,j;
	for(i=0;i<lim;i++)
	{
		for(int j=0;j<lim-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


void insert(int n,int *arr,int *arr1)
{
	for(int i=0;i<n;i++)
	{
		int entry,n;
		arr[i]=(rand() % 100);
		arr1[i]=arr[i];
	}
}



int main()
{
	clock_t q_start,q_end,b_start,b_end;
	double q_total,b_total;
	int ch,lim;
	
	//Random number insertion
	printf("Enter the limit:");
	scanf("%d",&lim);
	int arr[lim],arr1[lim];
	insert(lim,arr,arr1);
	
	//Bubble sort
	b_start=clock();
	bubblesort(lim,arr);
	
	//Time calculation of BS
	b_end=clock();
	b_total = (double)(b_end - b_start) / CLOCKS_PER_SEC;
	printf("\n\nBubble Sort time taken: %f\n",b_total);
	
	//Quick sort
	q_start=clock();
	quicksort(arr1,0,lim);
	
	//Time calculation of QS
	q_end=clock();
	q_total = (double)(q_end - q_start) / CLOCKS_PER_SEC;
	printf("\n\nQuick Sort time taken: %f\n",q_total);
}
