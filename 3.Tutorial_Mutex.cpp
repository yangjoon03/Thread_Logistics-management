#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void thread_function(int* num) {
    while (*num < 100) {
        mtx.lock();
        cout << *num << " ";
        (*num)++;
        mtx.unlock();
    }
}

int main() {
    int num = 0;
    thread num1(thread_function, &num);
    thread num2(thread_function, &num);
    thread num3(thread_function, &num);

    num1.join();
    num2.join();
    num3.join();

    return 0;
}
