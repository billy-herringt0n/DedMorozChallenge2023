#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <limits.h>

typedef struct Deti{
	int podarok[1000];
	struct Deti* next;
}Deti;

typedef struct Ded {
	int deti[1000];
	struct Ded* next;
}Ded;

void readNumbersFromFile(Deti* deti, const char* filename) {
    FILE* file = fopen(filename, "r");

    // Проверяем, удалось ли открыть файл
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return;
    }

    char buffer[1000];
    Deti* currentDeti = deti;  // Текущая структура Deti

    // Считываем строку из файла
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Используем strtok для разделения строки на числа по запятой
        char* token = strtok(buffer, ",");

        // Пропускаем первое значение
        token = strtok(NULL, ",");

        int count = 0;
        // Читаем остальные числа и записываем в массив podarok
        while (token != NULL && count < 1000) {
            currentDeti->podarok[count++] = atoi(token);  // Преобразуем строку в int
            token = strtok(NULL, ",");
        }
        
        // Выводим массив podarok на экран
        /*printf("Числа в массиве podarok:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", currentDeti->podarok[i]);
        }
        printf("\n");*/

        // Создаем новую структуру Deti для следующей строки
        currentDeti->next = (Deti*)malloc(sizeof(Deti));
        currentDeti = currentDeti->next;
    }
   
    // Закрываем файл после окончания работы
    fclose(file);
}


void readNumbersFromFile_2(Ded* dedok, const char* filename) {
    FILE* file = fopen(filename, "r");

    // Проверяем, удалось ли открыть файл
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return;
    }

    char buffer[10000];
    Ded* currentDedok = dedok;  // Текущая структура Deti

    // Считываем строку из файла
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Используем strtok для разделения строки на числа по запятой
        char* token = strtok(buffer, ",");

        // Пропускаем первое значение
        token = strtok(NULL, ",");

        int count = 0;
        // Читаем остальные числа и записываем в массив podarok
        while (token != NULL && count < 10000) {
            currentDedok->deti[count++] = atoi(token);  // Преобразуем строку в int
            token = strtok(NULL, ",");
        }

        // Выводим массив podarok на экран
       /* printf("Числа в массиве podarok:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", currentDedok->deti[i]);
        }
        printf("\n");*/

        // Создаем новую структуру Deti для следующей строки
        currentDedok->next = (Ded*)malloc(sizeof(Ded));
        currentDedok = currentDedok->next;
    }

    // Закрываем файл после окончания работы
    fclose(file);
}



void main() {
    setlocale(LC_ALL, "RUS");

    Deti* head = (Deti*)malloc(sizeof(Deti));
    if (head == NULL) {
        perror("Ошибка при выделении памяти для структуры Deti");
        return; // Возвращаем код ошибки
    }
    Ded* head_2 = (Ded*)malloc(sizeof(Ded));
    if (head_2 == NULL) {
        perror("Ошибка при выделении памяти для структуры Deti");
        return; // Возвращаем код ошибки
    }
    // Заполняем данные детей из файла
    readNumbersFromFile(head, "kids_wish.csv");

    // Заполняем данные подарков из файла
    readNumbersFromFile_2(head_2, "ded_moroz_wish.csv");


    getchar();
}