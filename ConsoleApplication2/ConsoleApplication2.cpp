#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

#define MIN -500
#define MAX 500
#define RANGE (MAX - MIN + 1)  // Формула диапазона значений

//SPROSIT POCHEMU N-I-1 FAIL?????????????????????????
//Размеры массивов
const int N = 1000;
const int N2 = 15;
const int N3 = 10;
const int size = 5;

//Обьявление функций
void find_min_max(int *massive1, char choice);
void my_sort(int *massive2, char choice);
void reverse(int *massive3);
int decTobin(int num);
void printOctal(int n);

int main()
{
    setlocale(LC_ALL, "Russian");
    int massive1[N];
    int massive2[N2] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int massive3[N3] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    char choice;

    srand(time(NULL));

    reverse(massive3);
    printf("Перевёрнутый массив 3: ");
    for (int i = 0; i < N3; i++)
    {
        printf("%d ", massive3[i]);
    }
    /*
    for (int i = 0; i < N; i++)
    {
        massive1[i] = rand() % RANGE + MIN;
        printf("%d\n", massive1[i]);
    }
    */
    printf("\n");
    printf("m - min, x - max, p - po vozrast, k - po ubav\n");
    printf("Enter a script: ");
    scanf_s("%c", &choice, 1);

    //printf("%u", find_min_max(massive1, N, choice));
    my_sort(massive2, choice);

    //Для систем счисления
    int num2;
    printf("Enter dec. number: ");
    scanf_s("%d", &num2);
    int binNum = decTobin(num2);
    printf("number in 2 s.s. = %d", binNum);
    printf("\n");

    int num8;
    printf("Enter dec. number: ");
    scanf_s("%d", &num8);
    printf("Number in 8 s.s. = ");
    printOctal(num8);
    printf("n");

    return 0;
}

int find_min_max(int* massive1, int N, char choice)
{
    int min = massive1[0];
    int max = massive1[0];

    for (int i = 0; i < N; i++) {
        if (massive1[i] < min) {
            return min;
        }
        if (massive1[i] > max) {
            return max;
        }
    }
    
    if (choice == 'm') {
        printf("Min: %d\n", min);
    } else if (choice == 'x') {
        printf("Max: %d\n", max);
    }

}

void my_sort(int* massive2, char choice) // Функция, которая делает сортировку пузырьком
{
    for (int i = 0; i < N2 - 1; i++)
    {
        for (int j = 0; j < N2 - i - 1; j++)
        {
            if (choice == 'p') // убрать из фора
            {
                if (massive2[j] > massive2[j + 1])
                {
                    int obmen = massive2[j];
                    massive2[j] = massive2[j + 1];
                    massive2[j + 1] = obmen;
                    //printf("%d", massive2[i]);
                }
            }
            if (choice == 'k')
            {
                if (massive2[j] < massive2[j + 1])
                {
                    int obmen = massive2[j];
                    massive2[j] = massive2[j + 1];
                    massive2[j + 1] = obmen;
                    //printf("%d", massive2[i]);
                }
            }

        }
    }
    printf("Final massive2: ");
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", massive2[i]);
    }
    printf("\n");
}

void reverse(int* massive3) // Функция, которая разворачивает массив
{
    for (int i = 0; i < N3 / 2; i++) {
        int TMP = massive3[i];
        massive3[i] = massive3[N3 - i - 1];
        massive3[N3 - i - 1] = TMP;
    }

}

int decTobin(int num) // Перевод из 10 в 2 с.с.
{
    int bin = 0, pos = 1;

    while (num)
    {
        bin += (num % 2) * pos;
        pos *= 10;
        num /= 2;
    }

    return bin;
    //printf("bin = %d", bin);
}

void printOctal(int num) // Перевод из 10 в 8 с.с.
{
    if (num < 8) {
        printf("%d", num);
    }
    else {
        printOctal(num / 8);
        printf("%d", num % 8);
    }
}


