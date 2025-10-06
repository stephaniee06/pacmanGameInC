#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 10

char map[HEIGHT][WIDTH+1] = {
    "###################",
    "#.................#",
    "#.#####.#####.###.#",
    "#.................#",
    "#.###.#.###.#.###.#",
    "#.................#",
    "#.###.#####.###.###",
    "#.................#",
    "#.................#",
    "###################"
};

int pacX = 1, pacY = 1;
int ghostX = WIDTH-3, ghostY = HEIGHT-3;
int score = 0;

void gotoxy(int x, int y){
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void hideCursor(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void draw(){
    gotoxy(0,0);
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(i==pacY && j==pacX)
                printf("P");
            else if(i==ghostY && j==ghostX)
                printf("G");
            else
                printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void input(){
    if(_kbhit()){
        char ch = _getch();
        int newX = pacX, newY = pacY;

        if(ch=='a') newX--;
        if(ch=='d') newX++;
        if(ch=='w') newY--;
        if(ch=='s') newY++;

        if(map[newY][newX]!='#'){
            if(map[newY][newX]=='.'){
                score+=10;
                map[newY][newX]=' ';
            }
            pacX=newX;
            pacY=newY;
        }
    }
}

int allFoodEaten(){
    for(int i=0;i<HEIGHT;i++)
        for(int j=0;j<WIDTH;j++)
            if(map[i][j]=='.') return 0;
    return 1;
}

void moveGhost(){
    int dx=0, dy=0;

    if(ghostX < pacX) dx = 1;
    else if(ghostX > pacX) dx = -1;
    if(map[ghostY][ghostX+dx]!='#') ghostX+=dx;

    if(ghostY < pacY) dy = 1;
    else if(ghostY > pacY) dy = -1;
    if(map[ghostY+dy][ghostX]!='#') ghostY+=dy;
}

int main(){
    hideCursor();
    draw();

    int ghostCounter = 0;  // untuk lambatin ghost

    while(1){
        input();
		          // update Pac-Man tiap loop
        ghostCounter++;
        if(ghostCounter % 3 == 0){ // ghost hanya bergerak setiap 3 loop ? lebih lambat
            moveGhost();
        }

        draw();

        if(pacX==ghostX && pacY==ghostY){
            gotoxy(0, HEIGHT+2);
            printf("Game Over! Ghost caught you.\n");
            break;
        }

        if(allFoodEaten()){
            gotoxy(0, HEIGHT+2);
            printf("You Win! Final Score: %d\n", score);
            break;
        }

        Sleep(80); // Pac-Man lebih cepat dari sebelumnya
    }
    return 0;
}

