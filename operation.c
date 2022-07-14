#include "aircraft.h"

// 读取/写入航班信息
void Open_Flights(Flights *flights_p, int type)
{
    FILE *fp;
    if ((fp = fopen(
             "./src/flights_info.txt",
             (type == READ ? "r" : "w"))) == NULL)
    {
        printf("文件打开失败！\n");
        exit(0);
    }
    if (type == READ)
    {
        printf("-> 正在加载航班信息...\n");
        fscanf(fp, "%d", &(flights_p->length));
        for (int i = 0; i < flights_p->length; i++)
            fscanf(fp, "%d %s %s %s %s %s %s %d %d %s",
                   &(flights_p->flights[i].flight_id),
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
        printf("-> 正在同步航班信息...\n");
        fprintf(fp, "%d\n", flights_p->length);
        for (int i = 0; i < flights_p->length; i++)
            fprintf(fp, "%d %s %s %s %s %s %s %d %d %s\n",
                    flights_p->flights[i].flight_id,
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
    // 检查
    /* for (int i = 0; i < flights_p->length; i++)
        printf("%s %s %s %s %s %s %d %d %s\n",
               flights_p->flights[i].no,
               flights_p->flights[i].dep_city,
               flights_p->flights[i].arr_city,
               flights_p->flights[i].date,
               flights_p->flights[i].dep_time,
               flights_p->flights[i].arr_time,
               flights_p->flights[i].price,
               flights_p->flights[i].remain,
               flights_p->flights[i].carrier); */
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
        printf("-> 正在加载订单信息...\n");
        fscanf(fp, "%d", &(orders_p->length));
        for (int i = 0; i < orders_p->length; i++)
            fscanf(fp, "%s %d %d %s %s %s %s",
                   orders_p->orders[i].date,
                   &(orders_p->orders[i].id),
                   &(orders_p->orders[i].flight_id),
                   orders_p->orders[i].phone,
                   orders_p->orders[i].name,
                   orders_p->orders[i].type,
                   orders_p->orders[i].card_id);
    }
    else
    {
        printf("-> 正在读取订单信息...\n");
        fprintf(fp, "%d\n", orders_p->length);
        if (orders_p->length == 0)
            return;
        for (int i = 0; i < orders_p->length; i++)
            fprintf(fp, "%s %d %d %s %s %s %s\n",
                    orders_p->orders[i].date,
                    orders_p->orders[i].id,
                    orders_p->orders[i].flight_id,
                    orders_p->orders[i].phone,
                    orders_p->orders[i].name,
                    orders_p->orders[i].type,
                    orders_p->orders[i].card_id);
    }
    // 检查
    /* for (int i = 0; i < orders_p->length; i++)
        printf("%s %d %d %s %s %s %s\n",
               orders_p->orders[i].date,
               orders_p->orders[i].id,
               orders_p->orders[i].flight_id,
               orders_p->orders[i].phone,
               orders_p->orders[i].name,
               orders_p->orders[i].type,
               orders_p->orders[i].card_id); */
    fclose(fp);
}

// 读取/写入反馈信息
void Open_Feedbacks(Feedbacks *feedbacks_p, int type)
{
    FILE *fp;
    if ((fp = fopen(
             "./src/feedback_info.txt",
             (type == READ ? "r" : "w"))) == NULL)
    {
        printf("文件打开失败！\n");
        exit(0);
    }
    if (type == READ)
    {
        printf("-> 正在加载反馈信息...\n");
        fscanf(fp, "%d", &(feedbacks_p->length));
        for (int i = 0; i < feedbacks_p->length; i++)
            fscanf(fp, "%s %s %s %s %s",
                   feedbacks_p->feedbacks[i].date,
                   feedbacks_p->feedbacks[i].name,
                   feedbacks_p->feedbacks[i].contact,
                   feedbacks_p->feedbacks[i].no,
                   feedbacks_p->feedbacks[i].content);
    }
    else
    {
        printf("-> 正在同步反馈信息...\n");
        fprintf(fp, "%d\n", feedbacks_p->length);
        for (int i = 0; i < feedbacks_p->length; i++)
            fprintf(fp, "%s %s %s %s %s\n",
                    feedbacks_p->feedbacks[i].date,
                    feedbacks_p->feedbacks[i].name,
                    feedbacks_p->feedbacks[i].contact,
                    feedbacks_p->feedbacks[i].no,
                    feedbacks_p->feedbacks[i].content);
    }
    // 检查
    /* for (int i = 0; i < feedbacks_p->length; i++)
        printf("%s %s %s %s %s\n",
               feedbacks_p->feedbacks[i].date,
               feedbacks_p->feedbacks[i].name,
               feedbacks_p->feedbacks[i].contact,
               feedbacks_p->feedbacks[i].no,
               feedbacks_p->feedbacks[i].content); */
    fclose(fp);
}

// 打印航班信息列表
void Print_Flights(Flights *flights_p, int *list, int length)
{
    printf("|航班ID|航班号|出发城市|到达城市| 出发日期 |出发时间|到达时间|票价|剩余票数| 航空公司    \n");
    printf("|------|------|--------|--------|----------|--------|--------|----|--------|-------------\n");
    for (int i = 0; i < length; i++)
        printf("|  %4d|%6s|%8s|%8s|%10s|%8s|%8s|%4d|%8d|%-14s\n",
               flights_p->flights[list[i]].flight_id,
               flights_p->flights[list[i]].no,
               flights_p->flights[list[i]].dep_city,
               flights_p->flights[list[i]].arr_city,
               flights_p->flights[list[i]].date,
               flights_p->flights[list[i]].dep_time,
               flights_p->flights[list[i]].arr_time,
               flights_p->flights[list[i]].price,
               flights_p->flights[list[i]].remain,
               flights_p->flights[list[i]].carrier);
}

// 打印订单信息列表
void Print_Orders(Orders *orders_p, int *list, int length)
{
    printf("| 订票时间 | 订单号 |航班ID|  联系电话  |乘客姓名|乘客类型|     证件号码\n");
    printf("|----------|--------|------|------------|--------|--------|-------------------\n");
    for (int i = 0; i < length; i++)
        printf("|%10s|%8d|  %4d| %11s|  %6s|    %4s|%s\n",
               orders_p->orders[list[i]].date,
               orders_p->orders[list[i]].id,
               orders_p->orders[list[i]].flight_id,
               orders_p->orders[list[i]].phone,
               orders_p->orders[list[i]].name,
               orders_p->orders[list[i]].type,
               orders_p->orders[list[i]].card_id);
}

void Print_Feedbacks(Feedbacks *feedbacks_p)
{
    printf("| 反馈日期 | 姓名 |     联系方式     |航班ID| 反馈内容\n");
    printf("|----------|------|------------------|------|----------------\n");
    for (int i = 0; i < feedbacks_p->length; i++)
        printf("|%10s|%6s|%18s|%6s|%s\n",
               feedbacks_p->feedbacks[i].date,
               feedbacks_p->feedbacks[i].name,
               feedbacks_p->feedbacks[i].contact,
               feedbacks_p->feedbacks[i].no,
               feedbacks_p->feedbacks[i].content);
}