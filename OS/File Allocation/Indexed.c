#include<stdio.h>
void main(){
int sb[10],b[10],n,f[20][20],bo[20],x;

 printf("Enter the number of files: \n");
 scanf("%d",&n);

 for(int i=0;i<n;i++){
    printf("Enter the block and starting block of file %d :",i+1);
    scanf("%d %d",&b[i],&sb[i]);
    
    printf("\nEnter the block occuiped by file %d :",i+1);
    for(int j=0;j<b[i];j++)
        scanf("%d",&f[i][j]);
 }

printf("Filename\tlenght\tstarting index\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\n",i+1,b[i],f[i][0]);

printf("Enter the file name to view\n");
    scanf("%d",&x);
    
printf("Filename : %d \n",x);
    printf("FileLenght: %d \n",b[x-1]);
    printf("Blocks Occupied ");
    for (int i = 0; i < b[x-1]; i++)
        printf("%3d",f[x-1][i]);


}