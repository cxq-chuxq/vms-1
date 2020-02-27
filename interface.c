/*
设计最开始显示的大框，产品信息
*/

#include <stdio.h>
// 定义商品选项的数目
#define SHU 5

/*
commodity 商品结构体
里面定义了商品的名字和价格
*/
typedef struct {
    char name[20];
    int money;
}commodity;

commodity l[] = {"Juice",10,"Cola",6,"Tea",5," Water",8,"Coffee",7};

/* xuan[SHU] 商品选项函数 */
char xuan[SHU] = {'A','B','C','D','E'};

// 输入函数
int scanIn(){
    int input ;
    putchar('\n');
    printf("Your choice:");
    scanf("%d",&input);
    return input;
}

/* Mainmenu() 主界面函数 */
void Mainmenu(){
    putchar('\n');
    puts("*-----------------------------*");
    puts("|      Vending   Machine      |"); 
    puts("*-----------------------------*");
    printf("|%5c%5c%5c%5c%5c    |\n",xuan[0],xuan[1],xuan[2],xuan[3],xuan[4]);
    printf("|   $%2d  $%2d  $%2d  $%2d  $%2d   |\n",10,6,5,8,7);
    printf("|   [%c]  [%c]  [%c]  [%c]  [%c]   |\n",' ',' ',' ',' ',' ');
    puts("*-----------------------------*");
    printf("|                     [$%2d]   |\n",0);
    puts("|                             |");
    printf("|            [=%c=]            |\n",'=');
    puts("*-----------------------------*");
    putchar('\n');
    puts(" 1. Read product information");
    puts(" 2. Insert coin");
    puts(" 3. Press product button");
    puts(" 4. Press return button");
    puts(" 9. Open service menu (code required)");
    puts(" 0. Quit");
}
/* information() 商品信息函数 */
void Information(){
    puts("(1) The displayed products are:");
    for(int i=0;i<5;i++){
        printf("%c. %s（$%d）",xuan[i],l[i].name,l[i].money);
        putchar('\n');
    }
    Mainmenu();      
}


int main(){
    /*
    zInput 获取主界面用户输入
    */
    int zInput ;

    Mainmenu();
    zInput = scanIn();
    while(zInput<0||(zInput>4&&zInput!=9)){
        puts("Invalid choice!");
        Mainmenu();
        zInput = scanIn();
    }
    Information();
}