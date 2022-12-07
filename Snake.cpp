//
//  Snake.cpp
//  Snake Game
//
//  Created by Samuel Cummings on 12/4/22.
//

#include "Snake.hpp"
#include <tuple>

Snake::Snake(int x, int y, int velocity) {
    this->x = x;
    this->y = y;
    this->velocity = velocity;
    length = 1;
    direction = 'r';
}

void Snake::change_dir(char dir) {
    direction = dir;
}

void Snake::move_snake() {
    switch (direction) {
        case 'w':
            y -= velocity;
            break;
        case 's':
            y += velocity;
            break;
        case 'd':
            x += velocity;
            break;
        case 'a':
            x -= velocity;
            break;
    }
}

std::tuple<int, int> Snake::get_pos() {
    std::tuple<int, int> cord = {x, y};
    return cord;
}
