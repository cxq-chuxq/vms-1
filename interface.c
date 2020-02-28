/*
设计最开始显示的大框，产品信息
*/

#include <stdio.h>

/*
commodity 商品结构体
里面定义了商品的编号、名字、价格、数量、货物情况
*/
typedef struct {
    char id;
    char name[20];
    int money;
    int number;
    char lamp;
}commodity;

commodity l[] = {'A',"Juice",10,6,' ',
                 'B',"Cola",6,4,' ',
                 'C',"Tea",5,6,' ',
                 'D',"Water",8,8,' ',
                 'E',"Coffee",7,6,' '};

// char *money[] = {"1. $1","2. $2","3. $5","4. $10","0. Go back"}; 
/* money[] 定义输入钱币的面额 */
int  money[] = {1,2,5,10};
/* 设置用户的钱数总额 */
int sum = 0;
// /* lamp[] = 灯的数组控制可买货物和缺货提示 */
// char lamp[] = {' ','O','X'};

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
    printf("|            [=%c=]            |\n",'=');
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

/* 插入硬币菜单 */
int coin(){
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
                if(sum>l[i].money){
                    l[i].lamp = 'O';
                }
            }
            Windows();
        }              
    }   
    return sum;
}

/* 购买商品菜单 */
void product(){
    
}


int main(){
    /*
    zInput 获取主界面用户输入
    */
    int zInput ;

    zInput = Mainmenu();
    while(1){
        
        switch(zInput){
            case 1:
                Information();
                zInput = Mainmenu();
                break;
            case 2:
                coin();
                zInput = Mainmenu();
                break;
            case 3:

                break;
            case 4:

                break;
            case 9:

                break;
            case 0:

                break;
            default:
                puts("Invalid choice!");
                zInput = Mainmenu();
                break;
        }
    }
    
}