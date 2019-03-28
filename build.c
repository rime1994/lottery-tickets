#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int num_buy;    //声明全局变量num_buy，用于输入的买入数量计数
int choice;     //声明全局变量choice，用于menu的参数，及子函数内返回
int num_choice; //声明全局变量num_choice，用赋值单组彩票生成数个数
int main(void)
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
    void number(void); //声明number函数，主要用于输入购买数量的效验，并为num_buy赋值
    void random(int first, int second);
    void print_arr(void); //声明，powerball算法实现函数
    void number(); //声明number函数，主要用于输入购买数量的效验，并为num_buy赋值
    void random(int first, int second);
    void print_arr(); //声明，powerball算法实现函数
    switch (n)
    {
    case 1:
        num_choice = 4;
        number();
        random(69, 27);
        break;
    case 2:
        num_choice = 5;
        number();
        random(33, 16);
        break;
    case 3:
        exit(0);
    default:
        printf("input error! please try again.\n\n");
        main();
    }
}
void number()
{
    printf("How many do you want to buy?\n");
    scanf("%d", &num_buy);
    printf("\n");
    if (num_buy > 5 || num_buy <= 0) //限制了一次买入的数量，并且如果输入为负数将会报错，返回菜单
    {
        printf("don't buy too much! or input error.\n");
        menu(choice);
    }
}

void random(first, second)
{
    srand(time(0));
    int i, j, k;
    int a[7];
    for (j = 1; j <= num_buy; j++)
    {
        printf("%02d:\n", j);
        for (i = 0; i <= num_choice; i++)
        {
            a[i] = rand() % first + 1;
            for (k = 1; k <= i; k++) //对避免重复数的效验算法进行了重写，使其更具备复用性
            {
                if (a[i] == a[k - 1])
                    i--;
            }
        }
        a[num_choice + 1] = rand() % second + 1;
        a[5] = rand() % second + 1;
        for (i = 0; i <= num_choice; i++)
        {
            printf("%02d ", a[i]);
        }
        printf("   %02d", a[num_choice + 1]);
        printf("\n\n");
    }
}