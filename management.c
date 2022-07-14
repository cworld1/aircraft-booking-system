#include "aircraft.h"

// 新增航班
void Add_Flight(Flights *flights_p)
{
    printf("请输入新增航班信息\n");
    printf("航班ID：");
    scanf("%d", &(flights_p->flights[flights_p->length].flight_id));
    printf("航班号：");
    scanf("%s", flights_p->flights[flights_p->length].no);
    printf("出发城市：");
    scanf(" %s", flights_p->flights[flights_p->length].dep_city);
    printf("到达城市：");
    scanf(" %s", flights_p->flights[flights_p->length].arr_city);
    printf("出发日期：");
    scanf(" %s", flights_p->flights[flights_p->length].date);
    printf("出发时间：");
    scanf(" %s", flights_p->flights[flights_p->length].dep_time);
    printf("到达时间：");
    scanf(" %s", flights_p->flights[flights_p->length].arr_time);
    printf("票价：");
    scanf("%d", &(flights_p->flights[flights_p->length].price));
    printf("剩余票数：");
    scanf("%d", &(flights_p->flights[flights_p->length].remain));
    printf("航空公司：");
    scanf(" %s", flights_p->flights[flights_p->length].carrier);
    flights_p->length++;
    Open_Flights(flights_p, WRITE);
}

// 取消航班
void Modify_Flight(Flights *flights_p, int type)
{
    int i, input_id;
    printf("请输入要取消航班的航班ID：");
    scanf("%d", &input_id);
    for (i = 0; i < flights_p->length; i++)
        if (flights_p->flights[i].flight_id == input_id)
            break;
    if (i == flights_p->length)
    {
        printf("不存在该航班！\n");
        return;
    }

    if (type == CANCEL)
    {
        for (; i < flights_p->length - 1; i++)
            flights_p->flights[i] = flights_p->flights[i + 1];
        flights_p->length--;
    }
    else if (type == EDIT)
    {
        printf("出发日期：");
        scanf(" %s", flights_p->flights[i].date);
        printf("出发时间：");
        scanf(" %s", flights_p->flights[i].dep_time);
        printf("到达时间：");
        scanf(" %s", flights_p->flights[i].arr_time);
        printf("票价：");
        scanf("%d", &(flights_p->flights[i].price));
    }
    Open_Flights(flights_p, WRITE);
}

//管理员登录
int Admin_Login()
{
    char password[20], encrypted[20], key;

    // 打开文件
    FILE *fp;
    if ((fp = fopen("./src/admin.txt", "r")) == NULL)
    {
        printf("文件打开失败！\n");
        exit(0);
    }
    fscanf(fp, "%s", encrypted);
    fclose(fp);

    // 接收
    printf("-> 请输入管理员密码：");
    for (int i = 0; (key = getch()) != '\r'; i++)
    {
        if (key >= 'A' && key <= 'Z')
            password[i] = ((key - 'A') + MOVE) % 26 + 'A';
        else if (key >= 'a' && key <= 'z')
            password[i] = ((key - 'a') + MOVE) % 26 + 'a';
        else
            password[i] = key;
        putchar('*');
    }

    // 比对
    if (strcmp(password, encrypted) == 0)
    {
        printf("\n验证成功！\n");
        return PASSED;
    }
    printf("\n验证失败！\n");
    return FAILED;
}

// 【主要】航班菜单
void Adjust(Flights *flights_p, Feedbacks *feedbacks_p)
{
    if (Admin_Login() == FAILED)
        return;
    int choose;
    printf("| 1.增加航班             |\n");
    printf("| 2.取消航班             |\n");
    printf("| 3.改动航班信息         |\n");
    printf("| 4.查看反馈信息         |\n");
    printf("-> 请选择要执行的功能：");
    scanf("%d", &choose);
    printf(" ------------------------\n");
    switch (choose)
    {
    case 1:
        Add_Flight(flights_p);
        break;
    case 2:
        Modify_Flight(flights_p, CANCEL);
        break;
    case 3:
        Modify_Flight(flights_p, EDIT);
        break;
    case 4:
        Print_Feedbacks(feedbacks_p);
        break;
    default:
        printf("操作错误!\n");
        return;
    }
}