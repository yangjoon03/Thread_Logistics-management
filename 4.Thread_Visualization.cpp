#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class map {
protected:
    static int map[2][10];
};

class object :public map {
private:
    int x;
    int y;
    int color;
public:
    void thread_mode();
};

void object :: thread_move(){
  
}

int main() {
    thread objdect(thread_move, &num);
    thread object(thread_move, &num);
    thread object(thread_move, &num);

    num1.join();
    num2.join();
    num3.join();

    return 0;
}
