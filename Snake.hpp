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

class Snake {
    private:
        int x;
        int y;
        int length;
        int velocity;
        char direction;
    
    public:
        Snake(int x, int y, int velocity);
        void change_dir(char dir);
        void move_snake();
        std::tuple<int, int> get_pos();
};

#endif /* Snake_hpp */
