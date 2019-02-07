#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *str="Soham Marik";
    str++;
    printf("%s\n",str);

    int a[5]={1,2,3,4,5};
    int *ptr=a;         //pointer to first element of array
    int (*ptr2)[5];     //pointer to entire array
    ptr2=&a;
    printf("ptr: %d\n",ptr[0]);
    printf("ptr2: %d\n",*ptr2[0]);
    ptr++;
    printf("New ptr: %d\n",ptr[0]);

    int *ptr3[5];      //array of pointers
    for(int i=0;i<5;i++)
    {
        ptr3[i]=&a[i];
    }
    printf("%d\n",*ptr3[0]);
    return 0;
}