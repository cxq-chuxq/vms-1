#include "reception.h"

commodity l[] = {'A',"Juice",10,5,' ',
                 'B',"Cola",6,1,' ',
                 'C',"Tea",5,2,' ',
                 'D',"Water",8,1,' ',
                 'E',"Coffee",7,9,' '
                };

/* sum 设置用户的钱数总额 */
int sum = 0;
/* buy 设置出货的显示灯 */
char buy = '=';
/* s_sum 设置后台收入的金额 */
int s_sum = 0;
/* money[] 定义输入钱币的面额 */
int  money[] = {1,2,5,10};

// 输入函数
int scanIn(){
    int input ;
    putchar('\n');
    printf("Your choice:");
    scanf("%d",&input);
    return input;
}

/* Windows() 主界面 */
void Windows(){
    putchar('\n');
    puts("*-----------------------------*");
    puts("|      Vending   Machine      |"); 
    puts("*-----------------------------*");
    printf("|%5c%5c%5c%5c%5c    |\n",l[0].id,l[1].id,l[2].id,l[3].id,l[4].id);
    printf("|   $%2d  $%2d  $%2d  $%2d  $%2d   |\n",l[0].money,l[1].money,l[2].money,l[3].money,l[4].money);
    printf("|   [%c]  [%c]  [%c]  [%c]  [%c]   |\n",l[0].lamp,l[1].lamp,l[2].lamp,l[3].lamp,l[4].lamp);
    puts("*-----------------------------*");
    printf("|                     [$%2d]   |\n",sum);
    puts("|                             |");
    printf("|            [=%c=]            |\n",buy);
    puts("*-----------------------------*");
}

/* Mainmenu() 主菜单 */
int Mainmenu(){
    Windows();
    int a;
    putchar('\n');
    puts(" 1. Read product information");
    puts(" 2. Insert coin");
    puts(" 3. Press product button");
    puts(" 4. Press return button");
    puts(" 9. Open service menu (code required)");
    puts(" 0. Quit");
    a = scanIn();
    return a;
}

/* information() 商品信息界面 */
void Information(){
    putchar('\n');
    puts("(1) The displayed products are:");
    for(int i=0;i<5;i++){
        printf("%c. %-s（$%d）",l[i].id,l[i].name,l[i].money);
        putchar('\n');
    }      
}

/* Coin() 插入硬币菜单 */
int Coin(){
    int a = 1;
    while(a!=0){
        do{
            if(a>4||a<0){
                puts("Invalid choice!");
            }
            putchar('\n');
            puts("(2) Which coin would you like to insert?");
            for(int i=0;i<4;i++){
                printf("%d. $%d\n",i+1,money[i]); 
            }
            puts("0. Go back");
            a=scanIn();
        }while(a>4||a<0);
        if(a!=0){
            sum += money[a-1];
            printf("You have inserted $%d\n",money[a-1]);
            for(int i=0;i<5;i++){
                if(sum>=l[i].money){
                    l[i].lamp = 'O';
                }
                if(l[i].number==0){
                    l[i].lamp = 'X';
                }
            }
            Windows();
        }              
    }   
    return sum;
}

/* 购买商品菜单 */
void Product(){
    int a = 1;
    while(a!=0){
        do{
            if(a>4||a<0){
                puts("Invalid choice!");
            }
            putchar('\n');
            puts("(3) Which product button would you like to press?");
            for(int i=0;i<5;i++){
                printf("%d. $%c %s ($%d)\n",i+1,l[i].id,l[i].name,l[i].money); 
            }
            puts("0. Go back");
            a=scanIn();
        }while(a>5||a<0);      
        if(a!=0){
            printf("You have pressed button %c.\n",l[a-1].id);
            sum = sum - l[a-1].money;
            if(sum < 0||l[a-1].number==0){
                sum = sum + l[a-1].money;
                a = 5;
            }else{
                s_sum += l[a-1].money;
                l[a-1].number -= 1;
                for(int i=0;i<5;i++){
                    if(l[i].money>sum){
                        l[i].lamp = ' ';
                    }
                }
                if(l[a-1].number==0){
                    l[a-1].lamp = 'X';
                }
                buy = l[a-1].id;
                Windows();
            }            
        }     
    }
    buy = '=';     
}

/* 退还余额界面 */
void Refund(){
    puts("(4) Return button is pressed.");
    printf("$%d has been returned.\n",sum);
    sum = 0;
}


