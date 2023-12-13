// linked file allocation - os

#include <stdio.h>
#include <stdlib.h>

struct Block
{
    int index;
    struct Block *next;
};

struct File
{
    int name;
    int length;
    struct Block *first;
};

int main()
{
    int n, x;

    printf("Enter the number of files : ");
    scanf("%d", &n);

    struct File files[n];

    for (int i = 0; i < n; i++)
    {
        files[i].name = i + 1;
        files[i].first = NULL;

        printf("Enter the number of blocks occupied by file %d : ", i + 1);
        scanf("%d", &files[i].length);
        printf("Enter the blocks occupied by file %d : ", i + 1);
        struct Block *prevBlock = NULL;
        for (int j = 0; j < files[i].length; j++)
        {
            struct Block *newBlock = (struct Block *)malloc(sizeof(struct Block));
            scanf("%d", &newBlock->index);
            newBlock->next = NULL;
            if (prevBlock == NULL)
            {
                files[i].first = newBlock;
            }
            else
            {
                prevBlock->next = newBlock;
            }
            prevBlock = newBlock;
        }
    }
    printf("File name\tstart block\tLength\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", files[i].name, files[i].first->index, files[i].length);
    }

    printf("Enter the file name : ");
    scanf("%d", &x);
    printf("Length is : %d\n", files[x - 1].length);
    printf("Staring index is : %d\n", files[x - 1].first->index);
    printf("Blocks occupied are : ");
    struct Block *currentBlock = files[x - 1].first;
    while (currentBlock->next != NULL)
    {
        printf("%d -> ", currentBlock->index);
        currentBlock = currentBlock->next;
    }
    printf("%d", currentBlock->index);
    printf("\n");
}