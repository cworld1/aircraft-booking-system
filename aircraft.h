#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define m 40
#define n 100
enum way_of_open
{
    READ,
    WRITE
};

// 航班信息结构体
typedef struct
{
    char no[10];
    char dep_city[10];
    char arr_city[10];
    char date[11];
    char dep_time[6];
    char arr_time[6];
    int price;
    int remain;
    char carrier[18];
} Flight_Info;

typedef struct
{
    Flight_Info flights[m];
    int length;
} Flights;

// 订单信息结构体
typedef struct
{
    char date[10];
    int id;
    char no[10];
    int phone[11];
    char name[9];
    char type[6];
    char card_id[18];
} Order;

typedef struct
{
    Order orders[n];
    int length;
} Orders;

// 打印欢迎语句
void Welcome()
{
    printf("**********************\n");
    printf("* 欢迎使用飞机订票系统 *\n");
    printf("**********************\n");
}

// 读取/写入航班信息
void Open_Flights(Flights *flights_p, int type)
{
    FILE *fp;
    if ((fp = fopen(
             "./src/flights_info.txt",
             (type == READ ? "r" : "w"))) == NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    if (type == READ)
    {
        printf("正在加载航班信息...\n");
        fscanf(fp, "%d", &(flights_p->length));
        for (int i = 0; i < flights_p->length; i++)
            fscanf(fp, "%s %s %s %s %s %s %d %d %s",
                   flights_p->flights[i].no,
                   flights_p->flights[i].dep_city,
                   flights_p->flights[i].arr_city,
                   flights_p->flights[i].date,
                   flights_p->flights[i].dep_time,
                   flights_p->flights[i].arr_time,
                   &(flights_p->flights[i].price),
                   &(flights_p->flights[i].remain),
                   flights_p->flights[i].carrier);
    }
    else
    {
        printf("正在同步航班信息...\n");
        fprintf(fp, "%d\n", flights_p->length);
        for (int i = 0; i < flights_p->length; i++)
            fprintf(fp, "%s %s %s %s %s %s %d %d %s\n",
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
    fclose(fp);
}

// 读取/写入订单信息
void Open_Orders(Orders *orders_p, int type)
{
    FILE *fp;
    if ((fp = fopen(
             "./src/orders_info.txt",
             (type == READ ? "r" : "w"))) == NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    if (type == READ)
    {

        fscanf(fp, "%d", &(orders_p->length));
        for (int i = 0; i < orders_p->length; i++)
            fscanf(fp, "%s %d %s %d %s %s %s",
                   orders_p->orders[i].date,
                   &(orders_p->orders[i].id),
                   orders_p->orders[i].no,
                   &(orders_p->orders[i].phone),
                   orders_p->orders[i].name,
                   orders_p->orders[i].type,
                   orders_p->orders[i].card_id);
    }
    else
    {
        fprintf(fp, "%d\n", &(orders_p->length));
        if (orders_p->length == 0)
            return;
        for (int i = 0; i < orders_p->length; i++)
            fprintf(fp, "%s %d %s %d %s %s %s\n",
                    orders_p->orders[i].date,
                    orders_p->orders[i].id,
                    orders_p->orders[i].no,
                    orders_p->orders[i].phone,
                    orders_p->orders[i].name,
                    orders_p->orders[i].type,
                    orders_p->orders[i].card_id);
    }
    fclose(fp);
}

// 根据航班查找
void Flight_Search(Flights *flights_p)
{
    int i;
    char input_no[10];
    printf("请输入要查询的航班号：");
    scanf("%s", &input_no);
    for (i = 0; i < flights_p->length; i++)
        if (strcmp(flights_p->flights[i].no, input_no) == 0)
            break;
    if (i == flights_p->length)
        printf("不存在该航班!\n");
    else
        printf("该航班信息如下:\n\
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

// 根据时间查找
void Time_Search(Flights *flights_p)
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
            printf("符合条件的航班信息如下:\n\
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

// 查找航班菜单
void Flights_Search_Menu(Flights *flights_p)
{
    int input_key;
    printf("请选择查询方式\n");
    printf("* 1-------------按航班号查询 *\n");
    printf("* 2-------------按起降城市查询 *\n");
    scanf("%d", &input_key);
    switch (input_key)
    {
    case 1:
        Flight_Search(flights_p);
        break;
    case 2:
        Time_Search(flights_p);
        break;
    default:
        printf("操作错误!\n");
        break;
    }
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
航班号：%s\n\n\
联系电话：%d\n\n\
乘客姓名：%s\n\n\
乘客类型：%s\n\n\
证件号码：%s\n\n",
               orders_p->orders[i].date,
               orders_p->orders[i].id,
               orders_p->orders[i].no,
               orders_p->orders[i].phone,
               orders_p->orders[i].name,
               orders_p->orders[i].type,
               orders_p->orders[i].card_id);
}

// 【主要】主搜索菜单
void Search(Flights *flights_p, Orders *orders_p)
{
    int input_key;
    printf("请选择查询对象\n");
    printf("* 1-------------航班信息 *\n");
    printf("* 2-------------订票信息 *\n");
    scanf("%d", &input_key);
    switch (input_key)
    {
    case 1:
        Flights_Search_Menu(flights_p);
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
        if ((strcmp(flights_p->flights[i].dep_city, flights_p->flights[j].dep_city) == 0) && (j != i) && (flights_p->flights[j].remain != 0))
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
    time_t cur_time = time(NULL);
    strftime(
        orders_p->orders[orders_p->length].date,
        sizeof(orders_p->orders[orders_p->length].date) - 1,
        "%Y-%m-%d",
        localtime(&cur_time));
    printf("联系电话：");
    scanf("%s", orders_p->orders[orders_p->length].phone);
    printf("乘客姓名：");
    scanf(" %s", orders_p->orders[orders_p->length].name);
    printf("乘客类型（成年/儿童）；");
    scanf(" %s", orders_p->orders[orders_p->length].type);
    printf("证件号码：");
    scanf(" %s", orders_p->orders[orders_p->length].card_id);
    strcpy(flights_p->flights[i].no, orders_p->orders[orders_p->length].no);

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
    char input_no[10];
    printf("请输入要预定班机的航班号\n");
    scanf("%s", &input_no);
    for (i = 0; i < flights_p->length; i++)
        if (strcmp(flights_p->flights[i].no, input_no) == 0)
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

// 退票菜单
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
        if (orders_p->orders[k].no == flights_p->flights[i].no)
            break;
    flights_p->flights[i].remain++;
    for (; k < orders_p->length - 1; k++)
        orders_p->orders[k] = orders_p->orders[k + 1];
    orders_p->length--;

    Open_Flights(flights_p, WRITE);
    Open_Orders(orders_p, WRITE);
    printf("退票成功！\n");
}
/*
void Fadd(Flights *flights_p)
{
    FILE *fp1;
    int i;
    printf("请输入新增航班信息\n");
    printf("航班号\n");
    scanf("%d", &(flights_p->flight[flights_p->length].no));
    printf("起降时间\n");
    scanf(" %s", flights_p->flight[flights_p->length].date);
    printf("起降城市\n");
    scanf(" %s", flights_p->flight[flights_p->length].dep_city);
    printf("票价\n");
    scanf("%d", &(flights_p->flight[flights_p->length].price));
    printf("票价折扣\n");
    scanf("%d", &(flights_p->flight[flights_p->length].discount));
    printf("空余座位数\n");
    scanf("%d", &(flights_p->flight[flights_p->length].remain));
    flights_p->length++;
    if ((fp1 = fopen("./src/flights_info.txt", "w")) == NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    fprintf(fp1, "%d\n", flights_p->length);
    for (i = 0; i < flights_p->length; i++)
        fprintf(fp1, "%d %s %s %d %d %d\n", flights_p->flights[i].no, flights_p->flights[i].date, flights_p->flights[i].dep_city, flights_p->flights[i].price, flights_p->flights[i].discount, flights_p->flights[i].remain);
    fclose(fp1);
}
void Fcan(Flights *flights_p)
{
    FILE *fp1;
    int i, t;
    printf("请输入要取消航班的航班号\n");
    scanf("%d", &t);
    for (i = 0; i < flights_p->length; i++)
        if (flights_p->flights[i].no == t)
            break;
    if (i == flights_p->length)
    {
        printf("不存在该航班!\n");
        return;
    }
    for (; i < flights_p->length - 1; i++)
        flights_p->flights[i] = flights_p->flight[i + 1];
    flights_p->length--;
    if ((fp1 = fopen("./src/flights_info.txt", "w")) == NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    fprintf(fp1, "%d\n", flights_p->length);
    for (i = 0; i < flights_p->length; i++)
        fprintf(fp1, "%d %s %s %d %d %d\n", flights_p->flights[i].no, flights_p->flights[i].date, flights_p->flights[i].dep_city, flights_p->flights[i].price, flights_p->flights[i].discount, flights_p->flights[i].remain);
    fclose(fp1);
}
void Fchg(Flights *flights_p)
{
    FILE *fp1;
    int i, t;
    printf("请输入要修改航班的航班号\n");
    scanf("%d", &t);
    for (i = 0; i < flights_p->length; i++)
        if (flights_p->flights[i].no == t)
            break;
    if (i == flights_p->length)
    {
        printf("不存在该航班!\n");
        return;
    }
    printf("请输入新的起降时间\n");
    scanf("%s", flights_p->flights[i].date);
    printf("请输入新的票价\n");
    scanf("%d", &(flights_p->flights[i].price));
    printf("请输入新的票价折扣\n");
    scanf("%d", &(flights_p->flights[i].discount));
    if ((fp1 = fopen("./src/flights_info.txt", "w")) == NULL)
    {
        printf("文件打开失败!\n");
        exit(0);
    }
    fprintf(fp1, "%d\n", flights_p->length);
    for (i = 0; i < flights_p->length; i++)
        fprintf(fp1, "%d %s %s %d %d %d\n", flights_p->flights[i].no, flights_p->flights[i].date, flights_p->flights[i].dep_city, flights_p->flights[i].price, flights_p->flights[i].discount, flights_p->flights[i].remain);
    fclose(fp1);
}
void Adjust(Flights *flights_p)
{
    int k;
    printf("请选择要执行的功能\n");
    printf("1---------增加航班\n");
    printf("2---------取消航班\n");
    printf("3---------改动信息\n");
    scanf("%d", &k);
    switch (k)
    {
    case 1:
        Fadd(flights_p);
        break;
    case 2:
        Fcan(flights_p);
        break;
    case 3:
        Fchg(flights_p);
        break;
    }
} */