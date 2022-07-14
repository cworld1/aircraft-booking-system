#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define FLIGHTS 40
#define ORDERS 100
#define MOVE 1 // 偏移量
enum way_of_open
{
    READ,
    WRITE
};
enum way_of_find
{
    NO = 1,
    CITY
};
enum way_of_modify
{
    EDIT,
    CANCEL
};
enum is_passed
{
    PASSED,
    FAILED
};

// 航班信息结构体
typedef struct
{
    int flight_id;
    char no[11];
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
    Flight_Info flights[FLIGHTS];
    int length;
} Flights;

// 订单信息结构体
typedef struct
{
    char date[11];
    int id;
    int flight_id;
    char phone[12];
    char name[10];
    char type[7];
    char card_id[19];
} Order_Info;

typedef struct
{
    Order_Info orders[ORDERS];
    int length;
} Orders;

// 反馈信息结构体
typedef struct
{
    char date[11];
    char name[10];
    char contact[30];
    char no[11];
    char content[100];
} Feedback_Info;

typedef struct
{
    Feedback_Info feedbacks[ORDERS];
    int length;
} Feedbacks;

// 文件/屏幕打印操作相关（operation.c）
void Open_Flights(Flights *flights_p, int type);
void Open_Orders(Orders *orders_p, int type);
void Open_Feedbacks(Feedbacks *feedbacks_p, int type);
void Print_Flights(Flights *flights_p, int *list, int length);
void Print_Orders(Orders *orders_p, int *list, int length);
void Print_Feedbacks(Feedbacks *feedbacks_p);

// 飞机订单相关（aircraft.c）
void Flights_Search(Flights *flights_p, int type);
void Orders_Search(Orders *orders_p);
void Search(Flights *flights_p, Orders *orders_p);

void Recommend(Flights *flights_p, int i);
void Pay(Flights *flights_p, Orders *orders_p, int i);
void Reserve(Flights *flights_p, Orders *orders_p);
void Withdraw(Flights *flights_p, Orders *orders_p);

void Feedback(Feedbacks *feedbacks_p);

// 数据管理调整（management.c）
void Add_Flight(Flights *flights_p);
void Modify_Flight(Flights *flights_p, int type);
int Admin_Login();
void Adjust(Flights *flights_p, Feedbacks *feedbacks_p);