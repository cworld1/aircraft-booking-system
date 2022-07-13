#include "aircraft.h"

int main()
{
    int choose;
    Flights flights;
    Orders orders;
    flights.length = 0;
    orders.length = 0;
    Welcome();
    Open_Flights(&flights, READ);
    Open_Orders(&orders, READ);
    do
    {
        printf("**********************\n");
        printf("*  请根据提示完成操作  *\n");
        printf("* 1-------------查询 *\n");
        printf("* 2-------------订票 *\n");
        printf("* 3-------------退票 *\n");
        printf("* 4-------------修改 *\n");
        printf("* 5-------------退出 *\n");
        printf("**********************\n");
        scanf("%d", &choose);
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
    } while (choose != 5);
}