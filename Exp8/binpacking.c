//headers and macros
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define intmax __INT_MAX__

//global variables


//functions


//main
int main(){
  int n;
  printf("Enter the number of elements:\t"); scanf("%d",&n);
  int a[n]; printf("Enter the elements:\t");
  for(int i=0;i<n;i++){scanf("%d",&a[i]);}
  int w;
  printf("Enter maximum capacity of bin:\t"); scanf("%d",&w);
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
        if(a[j]>a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
  }printf("Sorted order:\t");                             // two pointers algorithm
  for(int i=0;i<n;i++){printf("%d ",a[i]);}printf("\n");
  int l=0,r=n-1,ans=0,temp=0;
  int s[n];for(int i=0;i<n;i++){s[i]=0;}
  while(l<=r){
    if(l==r && a[l]+temp==w){
        s[ans]=a[l]+temp; ans++; r--;
    }
    else if(l==r && a[l]+temp<w){
        s[ans]=a[l]+temp; ans++; r--;
    }
    else if(l==r && a[l]+temp>w){
        s[ans]=a[r]; s[ans+1]=temp; ans+=2; r--;
    }
    else if(a[l]+a[r]+temp==w){
        s[ans]=w; ans++; l++; r--; temp=0;
    }
    else if(a[l]+a[r]+temp>w){
        s[ans]=a[r]+temp; ans++; r--; temp=0;
    }
    else if(a[l]+a[r]+temp<w){
        temp+=a[l]; l++;
    }
  }
  printf("\nThe minimum number of bins needed is %d\n",ans);
  printf("Solution set:\t{ ");
  for(int i=0;i<n;i++){
    if(s[i]!=0){
      printf("%d ",s[i]);
    }
    else{ break;}
  }
  printf("}\n");
  return 29;
}