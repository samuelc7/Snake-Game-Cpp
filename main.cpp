//
//  main.cpp
//  Snake Game
//
//  Created by Samuel Cummings on 12/3/22.
//

#include <iostream>
#include <cstdlib>
#include <list>
#include <tuple>
#include <curses.h>
#include "Snake.hpp"
#include "Board.hpp"

#define WIDTH 50
#define HEIGHT 25
#define VELOCITY 1
#define TITLE "Snake Game"

void board();

int main(int argc, const char * argv[]) {
    initscr();
    curs_set(0);
    refresh();
    
    Board board = Board(TITLE, WIDTH, HEIGHT);

    int snake_start_x = WIDTH / 2;
    int snake_start_y = HEIGHT / 2;
    Snake snake = Snake(snake_start_x, snake_start_y, 1);

    while (true) {
        // display box
        board.display_box();
        
        // display snke
        board.display_snake(&snake);
        
        // Get next move
        int ch = getch();
        snake.change_dir(ch);
        snake.move_snake();
    
        // Clear screen and continue
        board.refresh();
        
        
        
        /*
         switch(snake->get_direction()) {
             case 'd':
                 printw("0");
                 break;
             case 's':
                 break;
             case 'a':
                 break;
             case 'w':
                 break;
         }
         */
    }

    endwin();
    return 0;
}
