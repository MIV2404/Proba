#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#define ROW 25
#define COL 80

#define LEN_HISTORY 200
// количество записей в журнале
#define FRAME_SPEED 1020  // время задержки в мс
#define STEP_SPEED 100
// для запуска
// gcc -Wall -Werror -Wextra -lcurses game_of_life.c
// ./a.out < file.txt

void draw(int arr[ROW][COL]);  // отрисовка интерфейса
int transfer_hor(int x);  // функция переноса клетки при выходе за границу поля по горизонтали
int transfer_ver(int y);  // функция переноса клетки при выходе за границу поля по вертикали
void change_speed(int *speed, char key);  // функция изменения скорости во время игры
void cells_action(int arr[ROW][COL]);  // функция подсчета действий живых клеток
int count_cells_near(int arr[ROW][COL], int x, int y);  // функция подсчета живых соседей
int end_game(int log[LEN_HISTORY][ROW][COL], int arr[ROW][COL]);  // проверка на условия завершения игры

int main(void) {
    int arr[ROW][COL];
    int log[LEN_HISTORY][ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            scanf("%d", &arr[i][j]);  // ввод поля
        }
    }
    initscr();  // создание поля ncurses
    FILE *f;
    // выводит содержимое файла в stdin, позволяет пользователю вводить данные c терминала
    f = freopen("/dev/tty", "r", stdin);
    int speed;
    char ent;
    printw("Enter the speed (from 1 to 10): ");
    while (scanw("%d%c", &speed, &ent) != 1 || ent == '.' || speed > 10 || speed < 1) {
        ent = ' ';
        printw("Incorrect value, please re-enter: ");
    }
    speed *= STEP_SPEED;
    noecho();     // не выводит вводимые значения в терминал
    curs_set(0);  // курсор не мигает
    timeout(FRAME_SPEED - speed);
    clear();
    while (1) {
        cells_action(arr);
        draw(arr);
        char key;
        key = getch();

        if (key == '-' || key == '+') {
            change_speed(&speed, key);
            timeout(FRAME_SPEED - speed);
        }

        if (key == ' ') {
            key = getch();
            while (key != ' ' && key != 'q' && key != 'Q') {
                key = getch();
            }
        }

        if (key == 'q' || key == 'Q' || end_game(log, arr) == 0) break;
    }

    napms(FRAME_SPEED / 2);  // задержка последнего состояния перед закрытием окна вывода (5.5 сек)
    fclose(f);
    endwin();  // закрытие поля ncurses
    echo();    // выводит вводимые значения в терминал
    return 0;
}

// проверка на условия завершения игры
int end_game(int log[LEN_HISTORY][ROW][COL], int arr[ROW][COL]) {
    int flag = 1;
    for (int k = 0; k < LEN_HISTORY - 1; k++) {
        int check = 0;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (log[k][i][j] != arr[i][j]) check = 1;
            }
        }
        if (!check) {
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        for (int k = 0; k < LEN_HISTORY - 1; k++) {
            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                    log[k][i][j] = log[k + 1][i][j];
                }
            }
        }
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                log[LEN_HISTORY - 1][i][j] = arr[i][j];
            }
        }  // получаем новый массив log
    }
    return flag;
}

// отрисовка интерфейса
void draw(int arr[ROW][COL]) {
    clear();
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (arr[i][j] == 1)
                printw("#");
            else
                printw(".");
        }
        printw("\n");
    }
    printw("\nPress Spacebar to pause/continue. Press \"Q\" to exit.");
    printw("\nPress \"+\" to increase a speed. Press \"-\" to slow down.");
}

// функция переноса клетки при выходе за границу поля по горизонтали
int transfer_hor(int x) {
    if (x < 0) return x += COL;
    if (x >= COL) return x -= COL;
    return x;
}

// функция переноса клетки при выходе за границу поля по вертикали
int transfer_ver(int y) {
    if (y < 0) return y += ROW;
    if (y >= ROW) return y -= ROW;
    return y;
}

// функция изменения скорости во время игры
void change_speed(int *speed, char key) {
    if (key == '+') {
        if (*speed < 10 * STEP_SPEED) {
            *speed += 1 * STEP_SPEED;
        }
    }

    else {
        if (*speed > 1 * STEP_SPEED) {
            *speed -= 1 * STEP_SPEED;
        }
    }
}

// функция просчёта действий живых клеток
void cells_action(int arr[ROW][COL]) {
    int next[ROW][COL];  // создаем массив, в котором будет содержаться новое положение клеток
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int neighbours = count_cells_near(arr, i, j);
            if (arr[i][j] == 0 && neighbours == 3) {
                next[i][j] = 1;
            } else if (arr[i][j] == 1 && (neighbours < 2 || neighbours > 3)) {
                next[i][j] = 0;
            } else if (arr[i][j] == 1 && (neighbours == 2 || neighbours == 3)) {
                next[i][j] = 1;
            } else {
                next[i][j] = arr[i][j];
            }
        }
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            arr[i][j] = next[i][j];
        }
    }
}

// функция подсчета живых соседей
int count_cells_near(int arr[ROW][COL], int x, int y) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            count +=
                arr[transfer_ver(x + j)][transfer_hor(y + i)];  // подсчёт живых клеток в радиусе 1 клетки
        }
    }
    count -= arr[x][y];  // исключаем клетку, от которой считали
    return count;
}