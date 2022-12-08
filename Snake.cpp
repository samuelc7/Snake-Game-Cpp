//
//  Snake.cpp
//  Snake Game
//
//  Created by Samuel Cummings on 12/4/22.
//

#include "Snake.hpp"
#include <tuple>
#include <ncurses.h>

Snake::Snake(int x, int y, int velocity) {
    length = 3;
    front = {x,y};
    back = {x-6, y};
    this->velocity = velocity;
    direction = 'r';
    
    // initialize the nodes list
    nodes.push_front(front);
    nodes.push_front({x-1, y});
    nodes.push_front({x-2, y});
    nodes.push_front({x-3, y});
    nodes.push_front({x-4, y});
    nodes.push_front({x-5, y});
    nodes.push_front(back);
}

void Snake::change_dir(char dir) {
    direction = dir;
}

void Snake::move_snake() {
    switch (direction) {
        case 'w': {
            // move head to new place
            int new_y = get<1>(front) - velocity;
            front = {get<0>(front), new_y};
            nodes.push_back(front);
            
            // remove tail
            nodes.pop_front();
            break;
        }
        case 's': {
            // move head to new place
            int new_y = get<1>(front) + velocity;
            front = {get<0>(front), new_y};
            nodes.push_back(front);
            
            // remove tail
            nodes.pop_front();
            break;
        }
        case 'd': {
            // move head to new place
            int new_x = get<0>(front) + velocity;
            nodes.push_back({new_x, get<1>(front)});
            front = {new_x, get<1>(front)};
            
            // remove tail
            nodes.pop_front();
            break;
        }
        case 'a':
            // move head to new place
            int new_x = get<0>(front) - velocity;
            nodes.push_back({new_x, get<1>(front)});
            front = {new_x, get<1>(front)};
            
            // remove tail
            nodes.pop_front();
            break;
        }
}

std::list<std::tuple<int, int>> Snake::get_nodes() { return nodes; }

int Snake::get_length() { return length; }

char Snake::get_direction() { return direction; }
