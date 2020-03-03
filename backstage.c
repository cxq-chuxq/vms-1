#include "backstage.h"
#include "reception.h"

/* password 设置后台初始密码 */
int password = 1110;

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
        l[a-1].number = l[a-1].number + (10 - l[a-1].number);
        printf("You have refilled product %c to full.\n",l[a-1].id);
    }
}

/* 取出计算机所有硬币界面 */
void Withdrawn(){
    puts("(9-2) All money is being withdrawn.");
    printf("$%d is withdrawn.\n",s_sum+sum);
    s_sum = 0;
    sum = 0;
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
