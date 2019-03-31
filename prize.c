#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
int arr_count, arr_check, choice, win_count;
int arr_target[];
int arr_build[];
int main(void)
{
    void menu();
    printf("When will you win the lottery?\n"
           "please choice lottery!\n"
           "1.powerball\n"
           "2.double coloer ball\n"
           "3.exit\n");
    scanf("%d", &choice);
    menu();
    system("pause");
}
void menu()
{
    void random(first, second);
    void print_arr();
    void win_check();
    switch (choice)
    {
    case 1:
        printf("target tickets is :\n");
        random(69, 27);
        print_arr();
        break;
    case 2:
        printf("target tickets is: \n");
        random(33, 16);
        print_arr();
        win_check();
    default:
        printf("input error");
        break;
    }
}

void random(first, second)
{
    srand(time(0));
    for (arr_count = 0; arr_count <= 5; arr_count++)
    {
        arr_target[arr_count] = rand() % first + 1;
        for (arr_check = 1; arr_check <= arr_count; arr_check++) //对避免重复数的效验算法进行了重写，使其更具备复用性。
        {
            if (arr_target[arr_count] == arr_target[arr_check - 1])
                arr_count--;
        }
    }
    arr_target[6] = rand() % second + 1;
}
void print_arr()
{
    printf("***************************\n");
    for (arr_count = 0; arr_count <= 5; arr_count++)
    {
        printf("%02d ", arr_target[arr_count]);
    }
    printf("  %02d\n", arr_target[6]);
    printf("***************************\n");
}
void win_check()
{
    int win_check;
    void random_build(first, second);
    for(win_count=1;win_check != 1;win_count++){
        int i=0;
        random_build(33,16);
        for(arr_count=0;arr_count<=6;arr_count++){
            if (arr_target[arr_count==arr_build[arr_count]]){
                i++;
            }
        }
        if (i!=7){
            win_check = 0;
        }
        else{
            win_check =1;
        }
        system("cls");
        printf("conut done %d",win_count);
    }
    
}
void random_build(first, second)
{
    srand(time(0));
    for (arr_count = 0; arr_count <= 5; arr_count++)
    {
        arr_build[arr_count] = rand() % first + 1;
        for (arr_check = 1; arr_check <= arr_count; arr_check++) //对避免重复数的效验算法进行了重写，使其更具备复用性。
        {
            if (arr_build[arr_count] == arr_build[arr_check - 1])
                arr_count--;
        }
    }
    arr_build[6] = rand() % second + 1;
}