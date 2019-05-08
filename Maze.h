#include "Arduino.h"

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define FREE 0
#define SEARCHED 1
#define EDGE 2
#define INIT 3
#define GOAL 4

#define MAZE_HEIGHT 5
#define MAZE_WIDTH 5
class Maze
{
private:
    void setup();
    void expand();
    bool found;
    int maze[MAZE_HEIGHT][MAZE_WIDTH],state[MAZE_HEIGHT][MAZE_WIDTH];
    int parent[MAZE_HEIGHT][MAZE_WIDTH][2];
    int initX,initY,goalX,goalY;
    void printState();
    void printParent();
    void registrar(int i, int k,int py,int px);
public:
    void test(int maze[MAZE_HEIGHT][MAZE_WIDTH],int x,int y,int goalX, int goalY);

};
