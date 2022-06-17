#include <vector>

using namespace std;
#ifndef SNAKE
#define SNAKE
class Snake{
    public:
        //snake vector ((head x, head y),(body x, body y),(body)(body)...)
        vector<vector<int> > body;
        // int size; // size of snake, default = 3
        vector<int> empty_body{15, 30};

        //Constructor
        Snake();

        //size up
        void size_up();

        void size_down();

        //move snake
        void move(int command);
};
#endif
