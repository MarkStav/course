#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define a = 50 //const
#define true = const //замена
void swap_variables ( int *x,int *y){
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

void printArray(int* array, int length){
for ( int i = 0; i < length; i ++)
        printf("%d  ", array[i]);
printf("\n");
}
float average(int* array, int length){
    float result = 0;
    for (int i = 0; i < length; i++){
        result += *(array + i);
    }
    return result  / length;
}
int main(int argc, const char* argv[]) {

    int a = 69;
    printf("%d\n",a); //peremennaya
    printf("%p\n",&a); // adres
    int * pointer;
    pointer = &a;
    printf("%p\n",pointer); //адрес переменной а
    printf("%p\n",&pointer);//фдрес переменной pointer
    printf("%d\n",*pointer); // значение
    *pointer = 70;    // меняем значение а через указатель
    printf("%d\n",a);

    int first = 50, second = 40;
    printf("До %d, %d",first,second);
    swap_variables(&first,&second);
    printf("\nПосле %d, %d",first,second);
    int array1[50]; // объявление массива
    array1[0] = 10;
    array1[1] = 20;
    //....


    int array2[5] = {1, 2, 3, 4, 5};
    srand(time(NULL));
    int frequency[50] = {0};
    int a,i;
    for(i = 0; i < 1000000; i++){
        a = rand()%50;
        frequency[a]++;
    }
    for(i = 0; i < 50; i++){
        printf("Number %d generated %6d (%5.2f%%) times \n", i , frequency[i], ((
        float)frequency[i] / 50 * 100));
    }



    int arr[10];
    int i = 0;
    float result = 0;
    while (i < 10){
        printf("%d  ",i);
        scanf("%d",arr + i);
        i++;
    }
    printf("\n");
    printArray(arr,10);
    printf("%f \n", average(arr, 10));
    return 0;
}