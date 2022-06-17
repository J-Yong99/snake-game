#include "Snake.h"

//Constructor
Snake::Snake() {
    vector<int> head{2, 30};
    vector<int> head2{2, 29};
    vector<int> head3{2, 28};
    body.push_back(head);
    body.push_back(head2);
    body.push_back(head3);

};

//size up
void Snake::size_up(){
    body.push_back(empty_body);
};

//size down
void Snake::size_down(){
    empty_body = body.back();
    body.pop_back();
};

//move snake
void Snake::move(int command){
    vector<int> tmp_head = body[0];
    vector<int> tmp;

    //head move first
    switch(command)
    {
        case 1: // up
            body[0][0]--;
            body[0][0]=body[0][0]%30;
            break;
        case 2: // right
            body[0][1]++;
            body[0][1]=body[0][1]%60;
            break;
        case 3: // left
            body[0][1]--;
            if(body[0][1]<0){
                body[0][1]=59;
            }
            body[0][1]=body[0][1]%60;
            break;
        case 4: // down
            body[0][0]++;
            body[0][0]=body[0][0]%30;
            break;
        case 5: // backspace
            break;
    }

    //body follow head
    for (vector<vector<int> >::iterator it = body.begin() + 1; it != body.end(); it++)
    {
        tmp = *it;
        *it = tmp_head;
        tmp_head = tmp;
    }
    empty_body[0] = tmp_head[0];
    empty_body[1] = tmp_head[1];
    // cout << empty_body[0] << empty_body[1] << endl;
}