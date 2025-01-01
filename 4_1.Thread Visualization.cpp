#include <iostream>
#include <windows.h>

using namespace std;

#define X 10


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy_print(int x, int y) {
    COORD pos = { x * 2,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


class Map {
protected:
    static int map[3][X];
};
int Map::map[3][X] = { 0 };

class object :public Map {
private:
    int x;
    int y;
    int color;
    int speed;
public:
    object(int x, int y, int color,int speed) : x(x), y(y), color(color),speed(speed) {}
    void thread_move();
    void print();
};

void object::thread_move() {
    for (int i = 0; i < X; i++) {
        gotoxy_print(x, y);
        print();
        x++;
        Sleep(speed);
    }
}

void object::print() {
    if (color == 1) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);   //노란색~
    }
    if (color == 2) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);                    //초록색~
    }
    if (color == 3) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);    //보라색~
    }
    cout << "■";
}




int main() {
    object S1(0, 0, 1,1000);
    object S2(0, 1, 2,2000);
    object S3(0, 2, 3,4000);

    S1.thread_move();
    S2.thread_move();
    S3.thread_move();

    return 0;
}
