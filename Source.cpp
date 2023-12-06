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

    // ���������, ������� �� ������� ����
    if (file == NULL) {
        perror("������ ��� �������� �����");
        return;
    }

    char buffer[1000];
    Deti* currentDeti = deti;  // ������� ��������� Deti

    // ��������� ������ �� �����
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // ���������� strtok ��� ���������� ������ �� ����� �� �������
        char* token = strtok(buffer, ",");

        // ���������� ������ ��������
        token = strtok(NULL, ",");

        int count = 0;
        // ������ ��������� ����� � ���������� � ������ podarok
        while (token != NULL && count < 1000) {
            currentDeti->podarok[count++] = atoi(token);  // ����������� ������ � int
            token = strtok(NULL, ",");
        }
        
        // ������� ������ podarok �� �����
        /*printf("����� � ������� podarok:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", currentDeti->podarok[i]);
        }
        printf("\n");*/

        // ������� ����� ��������� Deti ��� ��������� ������
        currentDeti->next = (Deti*)malloc(sizeof(Deti));
        currentDeti = currentDeti->next;
    }
   
    // ��������� ���� ����� ��������� ������
    fclose(file);
}


void readNumbersFromFile_2(Ded* dedok, const char* filename) {
    FILE* file = fopen(filename, "r");

    // ���������, ������� �� ������� ����
    if (file == NULL) {
        perror("������ ��� �������� �����");
        return;
    }

    char buffer[10000];
    Ded* currentDedok = dedok;  // ������� ��������� Deti

    // ��������� ������ �� �����
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // ���������� strtok ��� ���������� ������ �� ����� �� �������
        char* token = strtok(buffer, ",");

        // ���������� ������ ��������
        token = strtok(NULL, ",");

        int count = 0;
        // ������ ��������� ����� � ���������� � ������ podarok
        while (token != NULL && count < 10000) {
            currentDedok->deti[count++] = atoi(token);  // ����������� ������ � int
            token = strtok(NULL, ",");
        }

        // ������� ������ podarok �� �����
       /* printf("����� � ������� podarok:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", currentDedok->deti[i]);
        }
        printf("\n");*/

        // ������� ����� ��������� Deti ��� ��������� ������
        currentDedok->next = (Ded*)malloc(sizeof(Ded));
        currentDedok = currentDedok->next;
    }

    // ��������� ���� ����� ��������� ������
    fclose(file);
}



void main() {
    setlocale(LC_ALL, "RUS");

    Deti* head = (Deti*)malloc(sizeof(Deti));
    if (head == NULL) {
        perror("������ ��� ��������� ������ ��� ��������� Deti");
        return; // ���������� ��� ������
    }
    Ded* head_2 = (Ded*)malloc(sizeof(Ded));
    if (head_2 == NULL) {
        perror("������ ��� ��������� ������ ��� ��������� Deti");
        return; // ���������� ��� ������
    }
    // ��������� ������ ����� �� �����
    readNumbersFromFile(head, "kids_wish.csv");

    // ��������� ������ �������� �� �����
    readNumbersFromFile_2(head_2, "ded_moroz_wish.csv");


    getchar();
}