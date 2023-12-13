#include<stdio.h>
typedef struct file{
    char fname[10];
    int start,size,block[10];
}file;

void main(){
  int n;
  printf("Enter the number of file");
  scanf("%d",&n);
  file f[10];
 
  for (int i = 0; i < n; i++)
  {     printf("Enter the file name");
        scanf("%s",&f[i].fname);
        printf("Enter the stating index");
        scanf("%d",&f[i].start);
        f[i].block[0]=f[i].start;
        printf("Enter the number of blocks");
        scanf("%d",&f[i].size);
        printf("Enter the blocks");
        for (int j = 1; j <= f[i].size; j++)
        {
            scanf("%d",&f[i].block[j]);
        }
  }

        printf("file\tstart\tsize\tblock\n");
        for (int i = 0; i < n; i++)
        {
            printf("%s\t%d\t%d\t",f[i].fname,f[i].start,f[i].size);
            for (int j = 0; j <f[i].size; j++)
            {
                printf("%d-->",f[i].block[j]);
            }
            printf("%d \n",f[i].block[f[i].size]);
            
        }
        
        
  }
  