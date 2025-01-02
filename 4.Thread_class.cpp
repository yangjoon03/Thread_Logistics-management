#include <iostream>
#include <thread>


using namespace std;

#define X 10


class Map {
protected:
    static int map[2][X];
};
int Map::map[2][X] = { 0 };

class object :public Map {
public:
    int x;
    int y;
    object(int x, int y) : x(x), y(y) {}
    void thread_move();
};

void object::thread_move() {
    for (int i = 0; i < X; i++) {
        x++;
    }
}

int main() {
    object S1(0, 0);
    object S2(0, 1);
    object S3(0, 0);

    thread To1(&object::thread_move, &S1);   //주소
    thread To2(&object::thread_move, S2);    //값
    S3.thread_move();                        //상속

    To1.join();
    To2.join();

    cout << "&쓰레드 : " << S1.x << endl;
    cout << " 쓰레드 : " << S2.x << endl;
    cout << " 상속   : " << S3.x << endl;

    return 0;
}
