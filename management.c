#include "aircraft.h"

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