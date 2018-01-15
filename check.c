#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
    Программа-пример No1 из главы 19
    Руководства по С для новичков, 3-е издание
    Файл Chapter19ex1.c
    Эта программа запрашивает имя пользователя
    и пароль. Программа проверяет, содержит ли введенный
    пароль символы верхнего, нижнего регистра, а также
    хотя бы одну цифру. Если да, то программа поздравляет
    пользователя с удачным выбором пароля. Если нет —
    программа предлагает придумать пароль, подразумевающий
    больше вариантов с целью повышения уровня
    безопасности.
    файл stdio.h нужен для функций printf() и scanf()
    файл string.h нужен для функции strlen()
    файл ctype.h нужен для функций isdigit, isupper и islower
*/

int main() {
    int i, size = 25;
    int hasUpper, hasLower, hasDigit;
    char user[size], password[size];

    //Инициилизируем все три переменные в 0, то есть ЛОЖЬ
    hasUpper = hasLower = hasDigit = 0;
    printf("Как Вас зовут?: ");
    scanf(" %s", user);
    do{
        printf("Пожалуйста введите пароль, не более 25 символов: ");
        scanf(" %s", password);
        /*
         Данный цикл проходит по всем символам пароля
         и проверяет не является ли символ буквой верхнего,
         нижнего регистра или цифрой
         */
                for(i = 0; i < strlen(password); i++)
                {
                    if(isdigit(password[i]))
                    {
                        hasDigit = 1;
                        continue;
                    }
                    if(isupper(password[i]))
                    {
                        hasUpper = 1;
                        continue;
                    }
                    if(islower(password[i]))
                    {
                        hasLower = 1;
                        continue;
                    }
                }

        if(hasUpper == 0 || hasLower == 0 || hasDigit == 0)
        { printf("%s, неверный пароль, в пароле должна присутствовать"
                         " хоть одна цифра или заглавная буква!!!\n", user); }
        else { printf("Хороший пароль!\n"); }
    }while(hasDigit == 0 || hasLower == 0 || hasUpper == 0);

    return 0;
}