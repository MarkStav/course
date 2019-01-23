#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/**
    ------------------------------------------------------------------------------
     1 часть
    ------------------------------------------------------------------------------
    */
char* helloFunction(){
    return "Hello!";
}
char* helloFunction2_0(char* name){
    char welcome[256] = "Hello, ";
    return strcat(welcome,name);      //Склеевание строки
}
char*  helloFunction2_1(char* name,char* out){
    char welcome[256] = "Hello, ";
    if(strcmp("Mark",name) == 0)      //Сравнивание строк
        strcpy(name,"Master!");       // Присваивание
    strcat(welcome,name);
    return strcpy(out,welcome);        // Копирует переменную name в out
}
char*  helloFunction2_2(char* name,char* out){
    char welcome[256] = "Hello, ";
    name[0] = (char)tolower(name[0]); //пеоевод в нижний регистер
    if(strcmp("mark",name) == 0)      //Сравнивание строк
        strcpy(name,"Master!");       // Присваивание
    name[0] = (char)toupper(name[0]); //перевод в верхний регистер
    strcat(welcome,name);
    return strcpy(out,welcome);        // Копирует переменную name в out
}
/**
    ------------------------------------------------------------------------------
     2 часть
    ------------------------------------------------------------------------------
    */
struct fraction {
    int integer;     //целая часть
    int divisible;   //делимое
    int divisor;     //делитель
};
typedef struct fraction Fraction;

void printFraction ( Fraction f){
    if (f.divisible != 0)
        if (f.integer == 0)
            printf("%d / %d", f.divisible,f.divisor);
        else
            printf("%d %d/%d", f.integer,f.divisible,f.divisor);
    else
        printf("%d", f.integer);
}
void fractionMultiply(Fraction f1, Fraction f2, Fraction * result){
    result->divisible = f1.divisible * f2.divisible;
    result->divisor = f1.divisor * f2.divisor;
    result->integer = f1.integer * f2.integer;
}


int main(){
    const char* d = "%d ";
    /**
    ------------------------------------------------------------------------------
     1 часть
    ------------------------------------------------------------------------------
    */
     char string1[256] = "This is string";
    char* string2 = "This is also string";

    printf("%s \n",string1);
    printf("%s \n",string2);

    string1[5] = 'x';
    printf("%s \n",string1);

    printf("%s \n",helloFunction());
    puts(helloFunction());            //Альтернатива printf()
    char name[256];
    char result[256];
    gets(name);                       //Альтернатива scanf()
    puts(name);

    puts(helloFunction2_0(name));

    puts(helloFunction2_1(name,result));
    /**
     * isalpha() - возвращает true если символ - буква
     * isdigit() - возвращает true если символ - число
     * isspace() - возвращает true если символ - пробел
     * isupper() - возвращает true если символ - в верхнем регистре
     * islower() - возвращает true если символ - в нижнем регистре
     * toupper() - переводит букву в верхний регистр
     * tolower() - переводит букву в нижний регистр
     * atoi() - преобразование в тип int
     * atof() - преобразование в тип float
    */
    puts(helloFunction2_2(name,result));

    char num[64];
    puts("Enter a number");
    gets(num);
    int number = atoi(num); //преобразование char в тип int
    number +=number;
    printf("%s * 2 = %d", num, number);
    /**
    ------------------------------------------------------------------------------
     2 часть
    ------------------------------------------------------------------------------
    */
    Fraction f1, f2, result;
    f1.integer = -1;
    f2.integer = 1;
    f1.divisible = 1;   // -1 | 1 / 5
    f1.divisor = 5;
    f2.divisible = 1;   //1 | 1 / 5
    f2.divisor = 5;
    printFraction(f1);
    puts(" ");
    printFraction(f2);
    puts(" ");
    fractionMultiply(f1,f2,&result);
    printFraction(result);
    /**
    ------------------------------------------------------------------------------
     3 часть
    ------------------------------------------------------------------------------
    */
    FILE *f;
    f = fopen("Hello_World.txt","w");   //r = read ; w = write; a = append; rb,wb,ab
    if (f == NULL) return 1;
    fprintf(f,"Hello World!");          //запись в файл
    fclose(f);                          //закрытие

    char word[256];

    f = fopen("Hello_World.txt","r");
    ///Чтение слова до пробела:
    fscanf(f,"%s", &word);
    printf("%s", word);
    puts(" ");
    ///Чтение всего текста:
    while (!feof(f)) {
        fscanf(f, "%s ", &word);
        printf("%s ", word);
    }
    puts(" ");
    close(f);                          //закрытие
    /**
    ------------------------------------------------------------------------------
     4 часть
    ------------------------------------------------------------------------------
    */
    const int SIZE = 10;
    // void* mallok(<memory size>);
    int *area = (int*)malloc(sizeof(int) * SIZE); ///выделения памяти для 10 чисел типа int
    //int *area = (int*)calloc(SIZE, sizeof(int));    //так же выделяет память но чуть медленее
    //тоже самое что и:
    int array[SIZE];
    int variable;
    int i;
    for (i = 0; i<SIZE; i++)array[i] = i * 10;
    for (i = 0; i<SIZE; i++)printf(d,array[i]);
    puts(" ");
    for (i = 0; i<SIZE; i++) *(area + i) = i *10;
    for (i = 0; i<SIZE; i++) printf(d,*(area + i));
    //free(area);                  //освобождение памяти
    puts(" ");


    int newsize = 10 + SIZE;
    area = realloc(area, sizeof(int)*(SIZE + 10));//изменение выделенной памяти
    for (i = 0; i<newsize; i++) *(area + i) = i *10;
    for (i = 0; i<newsize; i++) printf(d,*(area + i));
    free(area);

    return 0;
}