## Thread_Logistics-management(쓰레드를 사용한 물류관리)
 *  기초 쓰레드 ~ 활용까지 코드를 제공함.
 *  C++ 함수,클래스 등을 통한 쓰레드 활용
 *  클래스에 대한 이해도가 부족할시 추가 공부 필요.
<br>

## Thread Tutorial Function (1.함수)
  * 쓰레드 생성 , 파라미터 : thread variable_name(function , parameter); 일반적인 함수호출과는 다름.
  * 쓰레드 종료 : variable_name.join();
```cpp
thread variable_name(function , parameter);
```
<br>

## Thread Tutorial Pointer(2.포인터)
 * 변수 하나를 3개의 쓰레드가 공유
 * 연산이 끝나기전 다른 쓰레드의 참조로 문제 발생.
 * 해결 방법 : 뮤텍스
<br>

## Thread Tutorial Mutex(3.뮤텍스)
 * 쓰레드들간의 동기화
 * 2.포인터 문제를 해결
```cpp
#include <mutex>
mutex mtx;

mtx.lock(); //잠금
mtx.unlock(); //잠금 해제
```
<br>

## Thread Class(4.클래스)
 * 클래스에서 쓰래드 사용법.
```cpp
thread variable_name(&objet::function , parameter);
thread variable_name(&objet::function , &parameter);
```
<br>

## Thread Visualization(5.시각화)
 * 클래스의 static에 대한 이해도 필요.
 * 객체가 이동하는 속도에 대한 차이를 시각화하여 보여줌.
 * Thread를 사용하지 않은 코드는 4-1 코드 참조.
