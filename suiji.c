/* 0到7之间的不重复随机数 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t;
    int a[8] = {0}; 
    srand(time(&t));
    
    for(int i=0;i<7;i++){
        a[i] = rand() % 8;
        for(int j=0;j<i;j++){
            while(a[i]==a[j]){
                i--;
            }
        }
    }
    
    for(int i=0;i<7;i++){
        printf("%3d",a[i]);
    }
    putchar('\n');
    return 0;
}

