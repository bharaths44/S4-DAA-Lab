//headers and namespaces
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<time.h>

#define intmax __INT_MAX__              // bitmasking + memoization

//global variables
int **m,**memo,*path;
int n;
char s=65;

//int m[5][5]={{0,2,0,12,5},{2,0,4,8,0},{0,4,0,3,3},{12,8,3,0,10},{5,0,3,10,0}}; 
//int m[4][4]={{0,10,15,20},{5,0,9,10},{6,13,0,12},{8,8,9,0}};                             

//functions
int min(int a,int b){   return (a<b)?a:b;}
int max(int a,int b){   return (a>b)?a:b;}

void getMat(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter [%d,%d] ",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
}

void printMat(){
    printf("\n  ");
    for(int i=0;i<n;i++){
        printf(" %c ",s);s++;
    }   printf("\n\n");s=65;
    for(int i=0;i<n;i++){
        printf("%c  ",s);s++;
        for(int j=0;j<n;j++){
            printf("%d  ",m[i][j]);
        }  printf("\n\n");
    }
}

long long tsp(int i, int mask){
    if(mask==(1<<n)-1){return m[i][0];}
    if(memo[i][mask]!=-1){  return memo[i][mask];}
    long long res=intmax,flag=0;
    for(int j=0;j<n;j++){
        if(!(mask&(1<<j))){
        	if(m[i][j]==0){continue;}
            long long cost=m[i][j]+tsp(j,mask | (1<<j));
            if(cost<res){path[mask]=j;  res=cost;}
            //res=min(res,m[i][j]+ tsp(j,mask | (1<<j)));
        }
    }
    memo[i][mask]=res;
    return res;
}

void printPath(){
    printf("\nPath:\tA-->");
    int c=0,mask=1;
    for(int i=1;i<n;i++){
        int next=path[mask];
        printf("%c-->",'A'+next);
        mask|=(1<<next);
    }
    printf("%c\n\n",'A');
}

//main
int main(){
    printf("Enter the no of cities:\t");scanf("%d",&n);
    m=malloc(n * sizeof(int *));  memo=malloc(n * sizeof(int *));   path=malloc((1<<n) * sizeof(int));
    for(int i=0;i<n;i++){
        m[i]=malloc(n * sizeof(int));   memo[i]=malloc((1<<n) * sizeof(int));  memset(memo[i], -1, (1<<n) * sizeof(int));
    }
    getMat();   printMat();
    long mincost=tsp(0,1);
    printf("Minimum cost:\t%ld\n",mincost);
    printPath();
    for(int i=0;i<n;i++){free(m[i]);  free(memo[i]);} free(m);  free(memo); free(path);
    return 0;
}
