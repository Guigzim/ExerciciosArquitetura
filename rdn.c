#include <stdio.h>
#include <stdlib.h>


void main(){

    for(int i = 0; i < 10; i++)
    {
    int random = rand();

    printf("%d mode 4 = %d\n",random, random % 4);

    }
}