# КМ 3

## 1

```c
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
```

## 2

### Вывод максимального числа каждой строки

```shell
$ gcc 2.c -o 2 -std=c99
$ ./2
Generate and sort row of array with size n*m
Enter n size:
2
Enter m size:
3
Enter 3 values to row 1
12
43
23
Enter 3 values to row 2
123
542
532
introduced array is :
12      43      23
123     542     532
Array of maximum is
43      542

```

## 3

### Запись ФИО из файла в файл в другом формате

При запуске бинарника первым агрументом указываем файл с которого брать данные, вторым в который надо записать

пример файла from.txt

```txt
Guseynov,Yunis,Farrukh ogly
```

ФИО пишем через запятую и латиницей

пример результата

```txt
G.F.Yunis
```

```shell
$  gcc 3.c -o 3 -std=c99
$ ./3 from.txt to.txt
Name is: Guseynov
Surname: Yunis
Patronymic: Farrukh ogly
```