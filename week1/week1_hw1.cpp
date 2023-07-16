#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr; // 배열 동적 할당
    int len; // 배열의 길이 선언
    int top_index; // top index
public:
    Stack(int a) : len(a), top_index(-1) { arr = new T[len]; } // 생성자
    ~Stack() { delete[] arr; } // 소멸자

    void Push(T b) {
        if (top_index != len - 1) { // overflow가 아닌 경우
            top_index ++;
            arr[top_index] = b;
        } else { cout << "OVF: The stack is FULL" << endl; } // overflow!
    }

    void Pop() {
        if (top_index >= 0) { top_index --; } // underflow가 아닌 경우
        else { cout << "UDF : The stack is Empty"; } // underflow!
    }

    void Print() {
        if (top_index == -1) { cout << "Stack is Empty" << endl; } // 배열이 빈 경우
        else {
            for (int i = 0; i <= top_index; i++) { // 아닌 경우
                cout << arr[i] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack<int> stack(3);
    stack.Print();

    stack.Push(1);
    stack.Print();
    stack.Push(2);
    stack.Print();
    stack.Push(3);
    stack.Print();
    stack.Push(4); // overflow!
    stack.Print(); // "1 2 3" print

    stack.Pop(); // 3 pop
    stack.Print(); // 1 2 print
    stack.Pop(); // 2 pop
    stack.Print(); // 1 print

    stack.Push(5); // 5 push
    stack.Print(); // 1 5 print

    stack.Pop(); // 5 pop
    stack.Print(); // 1 print
    stack.Pop(); // 1 pop
    stack.Print(); // 빈 배열 > "Stack is Empty!"
    stack.Pop(); // 빈 배열 pop > UnderFlow!

    return 0;
}
