#include <stdio.h>
#include <stdlib.h>

int main (){
    int   m,n,j,k;
    float v;

    scanf("%d %d",&m,&n);
    do{
        scanf("%d",&j);
        if(!(j == 0)){
            scanf(" %d %f",&k,&v);
            printf("%d %d %f\n",j,k,v);
        }
        else
            return 1;
    }while(1);
    
    return 0;
}