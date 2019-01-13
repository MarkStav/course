#include <stdio.h>
/*
 * многострочный коментарий
 */
int main(int argc, const char* argv[]) {

    printf("Hello, World!\n");
    int a = 50;
    printf("text and%5d%% \n",a);
    printf("Переменная а имеет значение: %d \n",a);
    printf("Переменная а хранится по адресу: %p \n",&a);
    printf("Ведите число: ");
    int input;
    scanf("%d", &input);
    printf("Вы ввели число %d, мы удвоили его для вас: %d\n",input,input*2);
    char answer;
    printf("Do you want me to salute you?(y/n)\n");
    scanf("%c",&answer);
    if (answer == 'y'){
        printf("Hello brooo");
    } else if (answer == 'n') {
        printf("Fuck you, I don't want salute you!!");
    } else {
        printf("What do you mean?");
    }

    int a = 10;
    int b = 15;
    printf(a>b?"t":"f"); // тернарный оператор, альтернатива if
    while (a <= b){
        printf("\n%d",a);
        a++;
    }
    return 0;
}
