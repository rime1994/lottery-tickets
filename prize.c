#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[5], i;
    int b[5];
    srand(time(0));
    for (i = 0; i <= 4; i++)
    {
        a[i] = rand() % 69 + 1;
    }
    a[5] = rand() % 27 + 1;
    for (i = 0; i <= 5; i++)
    {
        printf("%2d ", a[i]);
    }
    printf("\n\n");
    system("pause");
    int j=1;
    do
    {
        for (i = 0; i <= 4; i++)
        {
            b[i] = rand() % 69 + 1;
        }
        b[5] = rand() % 27 + 1;
        j++;
        printf("j:%d,",j);
    } while (a[i] != b[i]);
    printf("b=a");

    for (i = 0; i <= 5; i++)
    {
        printf("%2d ", b[i]);
    }
    system("pause");
}
