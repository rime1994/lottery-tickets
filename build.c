#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int z;//声明全局变量z，用于输入的买入数量计数
int choice;
int main()
{
    void menu(n);
    void random_doubleball();
    printf("choice lottery tickets: \n"
           "1.powerball\n"
           "2.double coloer ball\n"
           "3.exit\n");
    scanf("%d", &choice);
    menu(choice);
    system("pause");
}

void menu(n)
{
    void number();
    void random_powerball();
    switch (n)
    {
    case 1:
        number();
        random_powerball();
        break;
    case 2:
        break;
    case 3:
        exit(0);
    default:
        printf("input error! please try again.\n\n");
        main();
    }
    return 0;
}
void number()
{
    printf("How many do you want to buy?\n");
    scanf("%d", &z);
    if (z > 5 || z <= 0)
    {
        printf("don't buy too much!\n");
        menu(choice);
    }
    else
        return (z);
}

void random_powerball()
{
    srand(time(0));
    int i, j, k;
    int a[5];
    for (j = 1; j <= z; j++)
    {
        printf("%d:\n", j);
        for (i = 0; i <= 4; i++)
        {
            printf("%02d  ", rand() % 69 + 1);
        }
        printf("\t");
        printf("%02d\n\n", rand() % 27 + 1);
    }
    return 0;
}