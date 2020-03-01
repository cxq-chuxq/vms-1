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

commodity l[] = {'A',"Juice",10,5,' ',
                 'B',"Cola",6,1,' ',
                 'C',"Tea",5,2,' ',
                 'D',"Water",8,1,' ',
                 'E',"Coffee",7,9,' '};

/* money[] 定义输入钱币的面额 */
int  money[] = {1,2,5,10};
/* sum 设置用户的钱数总额 */
int sum = 0;
/* buy 设置出货的显示灯 */
char buy = '=';
/* password 设置后台初始密码 */
int password = 1110;
/* s_sum 设置后台收入的金额 */
int s_sum = 0;


void Machine();
int Nextmenu();
void Withdrawn();

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
                printf("%d. $%c ($%d)\n",i+1,l[i].id,l[i].money); 
            }
            puts("0. Go back");
            a=scanIn();
        }while(a>5||a<0);      
        if(a!=0){
            printf("You have pressed button %c.\n",l[a-1].id);
            sum = sum - l[a-1].money;
            if(sum < 0){
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

/* 补充产品界面 (设每个产品最多能装10个) */
void Refill(){
    int a=1;
    do{
        if(a<0||a>5){
            puts("Invalid choice!");
        }
        for(int i=0;i<5;i++){
            printf("%d. %c\n",i+1,l[i].id);       
        }
        puts("0. Go back");
        a = scanIn();
    }while(a<0||a>5);
    if(a!=0){
        l[a-1].number = 10 - l[a-1].number;
        printf("You have refilled product %c to full.\n",l[a-1].id);
    }
}

/* 更改商品信息页面 */
void Change(){
    int a=1;
    do{
        if(a<0||a>5){
            puts("Invalid choice!");
        }
        puts("(9-4) Which product would you like to change?");
        for(int i=0;i<5;i++){
            printf("%d. %c\n",i+1,l[i].id);
        }
        puts("0. Go back");
        a = scanIn();
    }while(a<0||a>5);
    if(a!=0){
        printf("You are changing product %c.\n",l[a-1].id);
        printf("Enter new product name: ");
        scanf("%s",l[a-1].name);
        printf("Enter new product price:");
        scanf("%d",&l[a-1].money);
        if((l[a-1].money)>99){
            puts("Product not is greater than 99 ");
            l[a-1].money = 99;
        }else if((l[a-1].money)<=0){
            puts("Product not is less than 0 ");
            l[a-1].money = 1;
        }
        l[a-1].number = 10;
        printf("You have refilled product %c to full.\n",l[a-1].id); 
    }
}


/* 后台权限访问界面 */
void Service(){
    int a,lock=1;
    puts("(9) Opening service menu. Access code is required.");
    printf("Enter access code: ");
    scanf("%d",&a);
    if(a!=password){
        puts("Incorrect code!\n");
    }else{
        puts("Correct code!\n");
        a = Nextmenu();
        while(lock){
            switch(a){
                case 1:
                    Machine();
                    break;
                case 2:
                    Withdrawn();
                    break;
                case 3:
                    Refill();
                    break;
                case 4:
                    Change();
                    break;
                case 0:
                    lock = 0;
                    break;
                default:
                    puts("Invalid choice!");
                    break;
            }
            if(a!=0){
                a = Nextmenu();
            }
        }
    } 
}

/* 取出计算机所有硬币界面 */
void Withdrawn(){
    puts("(9-2) All money is being withdrawn.");
    printf("$%d is withdrawn.\n",s_sum+sum);
    s_sum = 0;
    sum = 0;
}

/* 后台选项菜单 */
int Nextmenu(){
    int a;
    putchar('\n');
    puts("(9) What would you like to do?");
    puts("1. Inspect machine status");
    puts("2. Withdraw all money");
    puts("3. Refill product");
    puts("4. Change product");
    puts("0. Go back");
    a = scanIn();
    return a;
}

/* 查看商品售卖信息界面 */
void Machine(){
    printf("Amount of revenue: $%d\n",s_sum);
    printf("Amount of inserted coins: $%d\n",sum);
    for(int i=0;i<5;i++){
        if(l[i].number==0){
            printf("%c. %s ($%d) (sold out)\n",l[i].id,l[i].name,l[i].money);
        }else{
            printf("%c. %s ($%d) (%d left)\n",l[i].id,l[i].name,l[i].money,l[i].number);
        }
    }
}



int main(){
    /**
    * zInput 获取主界面用户输入
    * lock 定义的开关
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
}