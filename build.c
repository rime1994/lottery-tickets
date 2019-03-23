//这是一段价值5.5亿美金的代码
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i, j, k;
    do
    {
        printf("How many lottery tickets do you want to buy?\t");
        scanf("%d", &k);
        printf("\n");
        if (k > 5)
        {
            printf("You don't have that much money, buy up to 5 !!!\n\n");
            continue;
        }
        else
            srand(time(0));
        for (j = 1; j <= k; j++)
        {
            printf("%d:\n", j);
            for (i = 0; i <= 4; i++)
            {
                printf("%2d  ", rand() % 69 + 1);
            }
            printf("\t");
            printf("%2d\n\n", rand() % 27 + 1);
        }
    } while (k > 5);
    system("pause");
}