#include <stdio.h>
#include <string.h>

// Данная гениальная программа выводит все символы до первой точки
// из входного потока данных за исключением знака "-" и удваивает "&"


int main() {
    char str[80];
    // Зачем обьявлять здесь?
    int i;
    printf("Enter the string:\n");

    // читаем поток данных в str, макс размер 80
    fgets(str, sizeof(str), stdin);
    //есть ли точка в input
    if (strchr(str, '.')) {
        printf("New line: \n");
        //продолжаем пока не найдем точку в str
        for (i = 0; str[i] != '.'; i++) {
        // выводим все симводы за исключением "-" и заменяем все "&" на "&&"
            if (str[i] != '-') {
                if (str[i] == '&')
                    //удавивание &
                    printf("&&");
                else
                    //вывод всех символов
                    printf("%c", str[i]);
            }
        }
    } else
        // если в str нет точки ввыводи это
        printf("The sequence does not end with a '.'!");
    return 0;
}
