#include <iostream>
#include <thread>

using namespace std;

void thread_function(int num) {
    for (int i = 0; i < 10; i++) {
        cout << num << "번 ";

    }
}


int main() {
    thread num1(thread_function, 1);
    thread num2(thread_function, 2);
    thread num3(thread_function, 3);

    num1.join();
    num2.join();
    num3.join();

    return 0;
}
