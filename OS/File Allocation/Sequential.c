#include<stdio.h>
 void main(){
    int n,b[20],sb[20],t,c[20][20],x;
    printf("Enter the number of files ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the number of blocks in file %d :\n",i+1);
        scanf("%d",&b[i]);
        printf("Enter the starting block :\n");
        scanf("%d",&sb[i]);

        t=sb[i];

        for(int j=0;j<b[i];j++){
         c[i][j]=t++;
        }
    }

    printf("Filename\tlenght\tstarting block\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\n",i+1,b[i],sb[i]);
    
    printf("Enter the file name to view\n");
    scanf("%d",&x);

    printf("Filename : %d \n",x);
    printf("FileLenght: %d \n",b[x-1]);
    printf("Blocks Occupied ");
    for (int i = 0; i < b[x-1]; i++)
        printf("%3d",c[x-1][i]);
 }