//change so that reverse starts from 0 not from 199

#include <stdio.h>

int getSeekTime(int a, int b)
{
    if (a > b)
        return a - b;
    return b - a;
}

void copy(int arr[], int temp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }
}

void sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] =temp;
            }
        }
    }
}

int reqIndex(int arr[],int n,int p){
    for(int i=0;i<n;i++){
        if(arr[i]>=p)
           return i;
    }
}

void scan(int arr[],int n,int p,int max){
    int seek=0,temp[n];
    copy(arr,temp,n);
    sort(temp,n);
    int index=reqIndex(temp,n,p);

    seek+=getSeekTime(p,max);   
    printf("%d-->",p);

    for(int i=index;i<n;i++){
        printf("%d-->",temp[i]);
        p=temp[i];
    }
    printf("%d\n%d--> ",max,max);
    p=max;
    for(int i=index-1;i>=0;i--){
        if(i!=0)
            printf("%d -->",temp[i]);
        else
            printf("%d",temp[i]);
        p=temp[i];
    }
    seek+=getSeekTime(max,temp[0]);
    printf("total head movement = %d \n",seek);
    printf("\nAverage seek time ; %d",seek/n);
}

void main(){
    int n,pos,i,max,p;
    printf("Enter the disk max limit");
    scanf("%d",&max);
    printf("Enter the number of request");
    scanf("%d",&n);
    printf("Enter the request \n");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the current head\n");
    scanf("%d",&p);
    scan(arr,n,p,max);
}