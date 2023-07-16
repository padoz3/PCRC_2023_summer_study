#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    T* arr; // 배열 동적 할당
    int len; // 배열의 길이 선언
    int f; // front index
    int r; // rear index
public:
    Queue(int a) : len(a), f(0), r(-1) { arr = new T[len]; } // 생성자
    ~Queue() { delete[] arr; } // 소멸자

    void Push(T b) {
        if (r == len - 1) { // 꽉 찬 경우
            cout << "OVF: The queue is FULL" << endl;
        }
        else {
            r++;
            arr[r] = b;
        }
    }

    T Pop() {
        if (f > r) {
            cout << "UDF : The queue is Empty" << endl;
            return 0;
        }
        else {
            f++;
            return arr[f];
        }
    }

    void Print() {
        if (f > r) {
            cout << "Queue is Empty" << endl;
        }
        else {
            for (int i = f; i <= r; i++) {
                cout << arr[i] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue<int> queue(3);
    queue.Print();

    queue.Push(1); // 1 push
    queue.Print(); // 1 print
    queue.Push(2); // 2 push
    queue.Print(); // 1 2 print
    queue.Push(3);
    queue.Print(); // 1 2 3 print
    queue.Push(4); // overflow
    queue.Print(); // 1 2 3 print

    queue.Pop(); // 1 pop
    queue.Print(); // 2 3 print
    queue.Pop(); // 2 pop
    queue.Print(); // 3 print

    queue.Push(5);
    queue.Print();

    queue.Pop();
    queue.Print();
    queue.Pop();
    queue.Print();
    queue.Pop();

    return 0;
}
