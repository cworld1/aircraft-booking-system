#include <unistd.h>
#include "aircraft.h"

int main()
{
    int choose;
    Flights flights;
    Orders orders;
    system("cls");
    printf(" ------------------------\n");
    printf("|  欢迎使用飞机订票系统  |\n");
    printf(" ------------------------\n");
    flights.length = 0;
    orders.length = 0;
    Open_Flights(&flights, READ);
    chdir("D:/Project/C-Project/Course-Design/");
    Open_Orders(&orders, READ);
    do
    {
        printf(" ------------------------\n");
        printf("| 1.查询  2.订票  3.退票 |\n");
        printf("| 4.修改（仅限管理员）   |\n");
        printf("| 5.退出                 |\n");
        printf(" -> 请输入菜单编号：");
        scanf("%d", &choose);
        printf(" ------------------------\n");
        switch (choose)
        {
        case 1:
            Search(&flights, &orders);
            break;
        case 2:
            Reserve(&flights, &orders);
            break;
        case 3:
            Withdraw(&flights, &orders);
            break;
        // case 4:
        //     Adjust(&flights);
        //     break;
        case 5:
            break;
        default:
            printf("\t无此功能，请重新输入!\n");
            break;
        }
        system("pause");
        system("cls");
    } while (choose != 5);
}