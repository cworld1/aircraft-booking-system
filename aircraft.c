#include "aircraft.h"

// 根据航班查找
void Flights_Search(Flights *flights_p, int type)
{
    int i, list[flights_p->length], pos = 0;
    if (type == NO)
    {
        char input_no[10];
        printf(" -> 请输入要查询的航班号：");
        scanf("%s", &input_no);
        for (i = 0; i < flights_p->length; i++)
            if (strcmp(flights_p->flights[i].no, input_no) == 0)
            {
                list[pos] = i;
                pos++;
            }
    }
    else if (type == CITY)
    {
        char input_dep[10], input_arr[10];
        printf("请输入出发城市：");
        scanf("%s", input_dep);
        printf("请输入到达城市：");
        scanf("%s", input_arr);
        for (int i = 0; i < flights_p->length; i++)
            if (strcmp(flights_p->flights[i].dep_city, input_dep) == 0 &&
                strcmp(flights_p->flights[i].dep_city, input_arr) == 0)
            {
                list[pos] = i;
                pos++;
            }
    }
    else
    {
        printf("输入错误！\n");
        return;
    }
    if (pos == 0)
    {
        printf("不存在相关航班！\n");
    }
    else
        Print_Flights(flights_p, list, pos);
}

// 查找订单&菜单
void Orders_Search(Orders *orders_p)
{
    int i;
    char input_id[20];
    if (orders_p->length == 0)
    {
        printf("当前订票人数为0,无法查询!\n");
        return;
    }
    printf("请输入证件号：");
    scanf("%s", input_id);
    for (i = 0; i < orders_p->length; i++)
        if (strcmp(orders_p->orders[i].card_id, input_id) == 0)
            break;
    if (i == orders_p->length)
        printf("不存在该客户!\n");
    else
        printf("该客户信息如下:\n\
订票时间：%s\n\n\
订单号：%d\n\n\
航班ID：%d\n\n\
联系电话：%d\n\n\
乘客姓名：%s\n\n\
乘客类型：%s\n\n\
证件号码：%s\n\n",
               orders_p->orders[i].date,
               orders_p->orders[i].id,
               orders_p->orders[i].flight_id,
               orders_p->orders[i].phone,
               orders_p->orders[i].name,
               orders_p->orders[i].type,
               orders_p->orders[i].card_id);
}

// 【主要】主搜索菜单
void Search(Flights *flights_p, Orders *orders_p)
{
    int input_key;
    printf("| 1.航班信息             |\n");
    printf("| 2.订票信息             |\n");
    printf(" -> 请选择查询对象：");
    scanf("%d", &input_key);
    switch (input_key)
    {
    case 1:;
        int input_key2;
        printf("| 1.按航班号查询         |\n");
        printf("| 2.按起降城市查询       |\n");
        printf(" -> 请选择查询方式：");
        scanf("%d", &input_key2);
        printf(" ------------------------\n");
        Flights_Search(flights_p, input_key2);
        break;
    case 2:
        Orders_Search(orders_p);
        break;
    default:
        printf("操作错误!\n");
        break;
    }
}

// 推荐航班
void Recommend(Flights *flights_p, int i)
{
    printf("抱歉，该航班已无空余座位\n");
    for (int j = 0; j < flights_p->length; j++)
        if ((strcmp(flights_p->flights[i].dep_city, flights_p->flights[j].dep_city) == 0) &&
            (j != i) &&
            (flights_p->flights[j].remain != 0))
        {
            printf("您可选择该相似航班：\n\
航班号：%s\n\
出发城市：%s\n\
到达城市：%s\n\
出发日期：%s\n\
出发时间：%s\n\
到达时间：%s\n\
票价：%d\n\
剩余票数：%d\n\
航空公司：%s\n",
                   flights_p->flights[i].no,
                   flights_p->flights[i].dep_city,
                   flights_p->flights[i].arr_city,
                   flights_p->flights[i].date,
                   flights_p->flights[i].dep_time,
                   flights_p->flights[i].arr_time,
                   flights_p->flights[i].price,
                   flights_p->flights[i].remain,
                   flights_p->flights[i].carrier);
        }
}

// 填写订单信息&存储
void Pay(Flights *flights_p, Orders *orders_p, int i)
{
    printf("请输入客户信息\n");
    // date
    time_t cur_time = time(NULL);
    strftime(
        orders_p->orders[orders_p->length].date,
        sizeof(orders_p->orders[orders_p->length].date),
        "%Y-%m-%d",
        localtime(&cur_time));
    // id
    srand((unsigned)time(NULL));
    orders_p->orders[orders_p->length].id = rand() * 787;
    // flight_id
    orders_p->orders[orders_p->length].flight_id = flights_p->flights[i].flight_id;
    // phone
    printf("联系电话：");
    scanf("%s", orders_p->orders[orders_p->length].phone);
    // name
    printf("乘客姓名：");
    scanf("%s", orders_p->orders[orders_p->length].name);
    // type
    printf("乘客类型（成年/儿童）；");
    scanf("%s", orders_p->orders[orders_p->length].type);
    // card_id
    printf("证件号码：");
    scanf("%s", orders_p->orders[orders_p->length].card_id);

    printf("您应支付票价%d元\n", flights_p->flights[i].price);
    flights_p->flights[i].remain--;
    orders_p->length++;

    Open_Flights(flights_p, WRITE);
    Open_Orders(orders_p, WRITE);
    printf("订票成功！\n");
}

// 【主要】订票菜单
void Reserve(Flights *flights_p, Orders *orders_p)
{
    int i;
    int input_id;
    printf("请输入要预定班机的航班ID：");
    scanf("%d", &input_id);
    for (i = 0; i < flights_p->length; i++)
        if (flights_p->flights[i].flight_id == input_id)
            break;
    if (i == flights_p->length)
    {
        printf("不存在该航班!\n");
        return;
    }
    if (flights_p->flights[i].remain == 0)
        Recommend(flights_p, i);
    else
        Pay(flights_p, orders_p, i);
}

// 【主要】退票菜单
void Withdraw(Flights *flights_p, Orders *orders_p)
{
    FILE *fp1, *fp2;
    int k, i;
    char temp[20];
    if (orders_p->length == 0)
    {
        printf("操作错误！\n");
        return;
    }
    printf("请输入客户证件号\n");
    scanf("%s", temp);
    for (k = 0; k < orders_p->length; k++)
        if (strcmp(temp, orders_p->orders[k].card_id) == 0)
            break;
    if (k == orders_p->length)
    {
        printf("该客户不存在！\n");
        return;
    }
    for (i = 0; i < flights_p->length; i++)
        if (orders_p->orders[k].flight_id == flights_p->flights[i].flight_id)
            break;
    flights_p->flights[i].remain++;
    for (; k < orders_p->length - 1; k++)
        orders_p->orders[k] = orders_p->orders[k + 1];
    orders_p->length--;

    Open_Flights(flights_p, WRITE);
    Open_Orders(orders_p, WRITE);
    printf("退票成功！\n");
}
