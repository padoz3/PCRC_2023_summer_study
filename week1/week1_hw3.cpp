#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    T* arr; // 배열 동적 할당
    int len; // 배열의 길이 선언
    int f; // front index
    int r; // rear index
    int next; // 다음 인덱스 번호를 나타내는 값
public:
    Queue(int a) : len( a + 1 ), f(0), r(0) { arr = new T[len]; } // 생성자
    ~Queue() { delete[] arr; } // 소멸자

    int NextIndex(int index) {
        if (index == len - 1)
            return 0;
        else
            return ++ index;
    }

    void Push(T b) {
        int next = NextIndex(r); // rear의 다음 인덱스값을 저장
        if (next == f) { // 꽉 찬 경우
            cout << "OVF: The queue is FULL" << endl;
        }
        else {
            r = next;
            arr[r] = b;
        }
    }

    T Pop() {
        if (f == r) {
            cout << "UDF : The queue is Empty" << endl;
            return 0;
        }
        else {
            f = NextIndex(f);
            return arr[f];
        }
    }

    void Print() {
        if (f == r) {
            cout << "Queue is Empty" << endl;
        }
        else {
            int curr = f; // f부터 r까지 배열 출력
            while(curr != r) {
                curr = NextIndex(curr);
                cout << arr[curr] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue<int> queue(3);
    queue.Print();

    queue.Push(1);
    queue.Print();
    queue.Push(2);
    queue.Print();
    queue.Push(3);
    queue.Print();
    queue.Push(4);
    queue.Print();

    queue.Pop();
    queue.Print();
    queue.Pop();
    queue.Print();

    queue.Push(5);
    queue.Print();

    queue.Pop();
    queue.Print();
    queue.Pop();
    queue.Print();
    queue.Pop();

    return 0;
}
