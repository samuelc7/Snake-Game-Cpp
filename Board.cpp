//
//  Board.cpp
//  Snake Game
//
//  Created by Samuel Cummings on 12/5/22.
//

#include "Board.hpp"
#include "Snake.hpp"

Board::Board(std::string title, int width, int height):TITLE{title}, WIDTH{width}, HEIGHT{height} {
    win = newwin(HEIGHT, WIDTH, 10, 10);
}

void Board::display_box() {
    box(win, '#', '#');
    wrefresh(win);
    move(8, ((WIDTH/2) + (int) TITLE.length()) - 5);
    printw(TITLE.data());
    wrefresh(win);
}

void Board::display_snake(Snake* snake) {
    for (std::tuple<int, int> node : snake->get_nodes()) {
        move(get<1>(node), get<0>(node));
        printw("0");
    }
}

void Board::refresh() {
    wclear(win);
    wrefresh(win);
}
