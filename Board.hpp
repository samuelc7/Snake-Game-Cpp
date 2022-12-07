//
//  Board.hpp
//  Snake Game
//
//  Created by Samuel Cummings on 12/5/22.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
#include <ncurses.h>
#include "Snake.hpp"

class Board {
    private:
        const std::string TITLE;
        const int WIDTH;
        const int HEIGHT;
        WINDOW * win;
    public:
        Board(std::string title, int width, int height);
        void display_box();
        void display_snake(Snake* snake);
        void refresh();
};

#endif /* Board_hpp */
