
#include <stdio.h>

/*
commodity 商品结构体
里面定义了商品的编号、名字、价格、剩余数量、货存情况
*/
typedef struct {
    char id;
    char name[20];
    int money;
    int number;
    char lamp;
}commodity;

/* 定义商品结构体数组 */
commodity l[5] ;

/* sum 设置用户的钱数总额 */
int sum ;
/* buy 设置出货的显示灯 */
char buy ;
/* s_sum 设置后台收入的金额 */
int s_sum ;
/* money[] 定义输入钱币的面额 */
int  money[4] ;


// 输入函数
int scanIn();

// Windows() 主界面 
void Windows();

// Mainmenu() 主菜单 
int Mainmenu();

// information() 商品信息界面 
void Information();

// Coin() 插入硬币菜单
int Coin();

// 购买商品菜单 
void Product();

// 退还余额界面 
void Refund();



