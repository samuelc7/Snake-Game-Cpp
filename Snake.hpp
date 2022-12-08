//
//  Snake.hpp
//  Snake Game
//
//  Created by Samuel Cummings on 12/4/22.
//

#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>
#include <tuple>
#include <list>

class Snake {
    private:
        int length;
        std::tuple<int, int> front;
        std::tuple<int, int> back;
        int velocity;
        char direction;
        std::list<std::tuple<int, int>> nodes;
    
    public:
        Snake(int x, int y, int velocity);
        void change_dir(char dir);
        char get_direction();
        void move_snake();
        std::list<std::tuple<int, int>> get_nodes();
        int get_length();
};

#endif /* Snake_hpp */
