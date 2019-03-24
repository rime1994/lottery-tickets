#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int z;      //声明全局变量z，用于输入的买入数量计数
int choice; //声明全局变量choice，用于menu的参数，及子函数内返回
int main()
{
    void menu(n); //声明函数menu，主要功能由menu实现，通选选择不通的选项调用其他子函数
    printf("choice lottery tickets: \n"
           "1.powerball\n"
           "2.double coloer ball\n"
           "3.exit.\n");
    scanf("%d", &choice);
    menu(choice);
    system("pause");
}

void menu(n)
{
    void number();            //声明number函数，主要用于输入购买数量的效验，并为z赋值
    void random_powerball();  //声明，powerball算法实现函数
    void random_doubleball(); //声明，双色球算法实现函数
    switch (n)
    {
    case 1:
        number();
        random_powerball();
        break;
    case 2:
        number();
        random_doubleball();
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
    printf("\n");
    if (z > 5 || z <= 0) //限制了一次买入的数量，并且如果输入为负数将会报错，返回菜单
    {
        printf("don't buy too much! or input error.\n");
        menu(choice);
    }
    else
        return (z);
}

void random_powerball()
{
    srand(time(0));
    int i, j;
    int a[6];
    for (j = 1; j <= z; j++)
    {
        printf("%02d:\n", j);
        for (i = 0; i <= 4; i++)
        {
            a[i] = rand() % 69 + 1;
            if (i > 0) //增加了随机生成数的效验功能，后输出的数不会与之前的数相同
            {
                if (a[i] == a[i - 1] || a[i] == a[i - 2] || a[i] == a[i - 3] || a[i] == a[i - 4])
                    i--;
            }
        }
        a[5] = rand() % 27 + 1;
        for (i = 0; i <= 4; i++)
        {
            printf("%02d ", a[i]);
        }
        printf("   %02d", a[5]);
        printf("\n\n");
    }
    return 0;
}

void random_doubleball()
{
    srand(time(0));
    int i, j;
    int a[7];
    for (j = 1; j <= z; j++)
    {
        printf("%02d:\n", j);
        for (i = 0; i <= 5; i++)
        {
            a[i] = rand() % 33 + 1;
            if (i > 0) //增加了随机生成数的效验功能，后输出的数不会与之前的数相同
            {
                if (a[i] == a[i - 1] || a[i] == a[i - 2] || a[i] == a[i - 3] || a[i] == a[i - 4] || a[i] == a[i - 5])
                    i--;
            }
        }
        a[6] = rand() % 16 + 1;
        for (i = 0; i <= 5; i++)
        {
            printf("%02d ", a[i]);
        }
        printf("   %02d", a[5]);
        printf("\n\n");
    }
    return 0;
}