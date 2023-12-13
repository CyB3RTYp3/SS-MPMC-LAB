#include <stdio.h>
void main()
{
    int que[20], head, tot, n;
    float seek = 0, avgs;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("\nEnter the inital head position: ");
    scanf("%d", &head);

    que[0] = head;

    printf("\nEnter the requests :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &que[i + 1]);
    }
    que[n + 1] = que[n];

    printf("/n Order of request served:");
    for (int i = 0; i <= n; i++)
    {
        tot = que[i + 1] - que[i];
        if (tot < 0)
        {
            tot = tot * (-1);
        }
        seek += tot;
        printf("%d-->", que[i]);
    }

    avgs = seek / n;

    printf("\nTotal seek time: %2f", seek);
    printf("\nAverage seek time : %2f", avgs);
}