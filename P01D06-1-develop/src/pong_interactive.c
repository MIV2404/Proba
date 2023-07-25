#include <ncurses.h>
#include <stdlib.h>

void draw(float ball_x, float ball_y, int r1_y, int r2_y);

int main(void) {
    int player1 = 0, player2 = 0;
    float ball_x = 40, ball_y = 12;
    int r1_y = 12, r2_y = 12;
    int ball_speed_x = -1, ball_speed_y = 1;
    int game = 1, speeder = 0;
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    noecho();
    while (game == 1) {
        clear();
        draw(ball_x, ball_y, r1_y, r2_y);
        mvprintw(3, 36, "%d", player1);
        mvprintw(3, 44, "%d", player2);
        int rand_y = rand() % 3 - 1;
        int c = getch();
        if ((ball_x == 7) &&  //обработка попаданий мяча в ракетки
            (ball_y == r1_y || ball_y == r1_y + 1 || ball_y == r1_y - 1)) {
            ball_speed_x = 1;
            ball_speed_y = rand_y;
            if (speeder < 65) speeder += 5;
        }
        if ((ball_x == 73) && (ball_y == r2_y || ball_y == r2_y + 1 || ball_y == r2_y - 1)) {
            ball_speed_x = -1;
            ball_speed_y = rand_y;
            if (speeder < 65) speeder += 5;
        }
        if (ball_y < 2)  //обработка попаданий мяча в стенки
            ball_speed_y = 1;
        if (ball_y > 22) ball_speed_y = -1;

        if ((r1_y < 22) && (c == 'Z' || c == 'z'))  //обработка движения ракеток
            r1_y += 1;
        else if ((r1_y > 2) && (c == 'A' || c == 'a'))
            r1_y -= 1;
        else if ((r2_y < 22) && (c == 'M' || c == 'm'))
            r2_y += 1;
        else if ((r2_y > 2) && (c == 'K' || c == 'k'))
            r2_y -= 1;

        if (ball_x == 7 && (r1_y - ball_y == 2) && ball_speed_y == 1) {  //краевые ситуации
            ball_speed_x = 1;
            ball_speed_y = -1;
        }
        if (ball_x == 7 && (ball_y - r1_y == 2) && ball_speed_y == -1) {
            ball_speed_x = 1;
            ball_speed_y = 1;
        }
        if (ball_x == 73 && (r2_y - ball_y == 2) && ball_speed_y == 1) {
            ball_speed_x = -1;
            ball_speed_y = -1;
        }
        if (ball_x == 73 && (ball_y - r2_y == 2) && ball_speed_y == -1) {
            ball_speed_x = -1;
            ball_speed_y = 1;
        }

        ball_x += ball_speed_x;  //обновление координат мяча
        ball_y += ball_speed_y;

        if (ball_x < 1) {  //обработка голов
            player2++;
            r1_y = 12, r2_y = 12;
            ball_x = 40;
            ball_y = 12;
            ball_speed_x = 1;
            ball_speed_y = rand_y;
            speeder = 0;
            napms(800);  //пауза между обновлениями экрана
        }
        if (ball_x > 78) {
            player1++;
            r1_y = 12, r2_y = 12;
            ball_y = 12;
            ball_x = 40;
            ball_speed_x = -1;
            ball_speed_y = rand_y;
            speeder = 0;
            napms(800);  //пауза между обновлениями экрана
        }
        if (player1 > 20) {
            game = 0;
            clear();
            draw(ball_x, ball_y, r1_y, r2_y);
            mvprintw(3, 36, "%d", player1);
            mvprintw(3, 44, "%d", player2);
            mvprintw(30, 30, "Player 1 Wins!!!");
            refresh();
            napms(8000);
        }
        if (player2 > 20) {
            game = 0;
            clear();
            draw(ball_x, ball_y, r1_y, r2_y);
            mvprintw(3, 36, "%d", player1);
            mvprintw(3, 44, "%d", player2);
            mvprintw(30, 29, "Player 2 Wins!!!");
            refresh();
            napms(8000);
        }
        napms(75 - speeder);  //постепенное ускорение игры
    }
    endwin();
    return 0;
}

void draw(float ball_x, float ball_y, int r1_y, int r2_y) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == 0 || i == 24)
                mvaddch(i, j, '-');
            else if (j == 0 || j == 79)
                mvaddch(i, j, '|');
            else if (j == 6 && (i == r1_y || i == r1_y - 1 || i == r1_y + 1))
                mvaddch(i, j, '<');
            else if (j == 74 && (i == r2_y || i == r2_y - 1 || i == r2_y + 1))
                mvaddch(i, j, '>');
            else if (j == ball_x && i == ball_y)
                mvaddch(i, j, 'O');
            else if (j == 40)
                mvaddch(i, j, '|');
            else
                mvaddch(i, j, ' ');
        }
    };
}
