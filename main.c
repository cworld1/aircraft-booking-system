#include <unistd.h>
#include "aircraft.h"

void main()
{
    int choose;
    Flights flights;
    Orders orders;
    Feedbacks feedbacks;
    chdir("D:/Project/C-Project/Course-Design/");
    // system("cls");
    printf("┌────────────────────────┐\n");
    printf("│  欢迎使用飞机订票系统  │\n");
    printf("└────────────────────────┘\n");
    flights.length = 0;
    orders.length = 0;
    feedbacks.length = 0;
    Open_Flights(&flights, READ);
    Open_Orders(&orders, READ);
    Open_Feedbacks(&feedbacks, READ);
    do
    {
        printf("┌────────────────────────┐\n");
        printf("│ 1.查询       2.订票    │\n");
        printf("│ 3.退票       4.反馈    │\n");
        printf("│ 5.后台管理             │\n");
        printf("│ 6.退出                 │\n");
        printf("├-> 请输入菜单编号：");
        scanf("%d", &choose);
        printf("├────────────────────────┤\n");
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
        case 4:
            Feedback(&feedbacks);
            break;
        case 5:
            Adjust(&flights, &feedbacks);
            break;
        case 6:
            printf("感谢您的使用。如遇到使用问题，请致电：10086\n");
            break;
        default:
            printf("无此功能，请重新输入！\n");
            break;
        }
        system("pause");
        system("cls");
    } while (choose != 6);
}