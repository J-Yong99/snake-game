#include <ncurses.h>
#include "Map.h"
#include "Snake.h"
#include "BoardController.h"
#include "GateController.h"
#include "Item.h"
#include "util.h"
#include <signal.h>
#ifndef GAME
#define GAME
bool _signal = true;

// when receive alarm, set _siganl true
void sig_alrm(int signum){
  _signal = false;
}


// int goal_snakeSize=5;
// int goal_growthPoint=3;
// int goal_positionPoint=2;
// int goal_gateCount=2;


int goal_snakeSize=rand()%5+5;
int goal_growthPoint=rand()%5+5;
int goal_positionPoint=rand()%3+5;
int goal_gateCount=rand()%5+5;
class GameController{
    public:
        friend class Item;
        vector<Item> itemContainer;
        Map map;
        int count=0;
        Snake snake;
        BoardController board;
        Gate gate;
        int speed=100000;
        int snakeColor=4;
        int keyIn, command = 2, gateCount = 0, itemCount = 0;
        pair<int,int> gate1=make_pair(0,0);
        pair<int,int> gate2=make_pair(0,0);
        int GrowthItemsCount=0 , PositionItemCount=0 , usedGateCount=0;
        string score_snakeSize = "B:" + to_string(snake.body.size());
        string score_growthPoint = "+:"+to_string(GrowthItemsCount);
        string score_positionPoint= "-:"+to_string(PositionItemCount);
        string score_gateCount = "G:"+to_string(usedGateCount);
        string mission_snakeSize = "B:" + to_string(goal_snakeSize)+" ( )";
        string mission_growthPoint = "+:"+to_string(goal_growthPoint)+" ( )";
        string mission_positionPoint= "-:"+to_string(goal_positionPoint)+" ( )";
        string mission_gateCount = "G:"+to_string(goal_gateCount)+" ( )";
        //Constructor
        GameController() : board(), snake(), gate(map, snake, command,usedGateCount,board,gate1,gate2,goal_gateCount) {}

        void game_control(int arr[][60],int& i);

        void game_run(int m4[][60],int& i);

        void check_snake_eat();

    void item_setter();

    //refresh map array every 1sec to rendering map
    void render_map();

    void clear_map();

    //set snake in the map array
    void set_snake();

    // return keyboard input
    int keyboard_input();

    void set_item(Item item);

    void expired_item(Item item);

    void check_item(vector<Item> &v);

    bool is_empty(int x, int y);
};
#endif
