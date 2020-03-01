/*
运行程序显示初始信息（commodity结构体）
按1，显示产品信息
按2，进行插入硬币操作，在插入硬币满足购买钱数时亮灯（'O'),并显示金额
按3，购买操作在操作货物为空时亮灯（'X'）,并显示余额
按4，退还硬币操作
按9，进入后台操作，输入相应密码，密码错误提示错误信息，正确则显示菜单，去选择查看状态、增加产品数量、更改产品内容等等。
(价格为1~99，小于等于0时默认为1，大于99默认为99；)
按0，退出售货机
*/

#include <stdio.h>
#include "backstage.h"
#include "reception.h"

int main(){
    /**
    * zInput 获取主界面用户输入
    * lock 定义程序的开关
    **/
    int zInput ;
    int lock = 1;

    while(lock){
        if(lock!=0){
            zInput = Mainmenu();
        }
        switch(zInput){
            case 1:
                Information();
                break;
            case 2:
                Coin();
                break;
            case 3:
                Product();
                break;
            case 4:
                Refund();
                break;
            case 9:
                Service();
                break;
            case 0:
                puts("\n\nProcess finished with exit code 0");
                lock = 0;
                break;
            default:
                puts("Invalid choice!");               
                break;
        }
    }
    return 0;
}