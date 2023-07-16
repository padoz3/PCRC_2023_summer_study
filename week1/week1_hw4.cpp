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
            top_index++;
            arr[top_index] = b; // 값 저장
        } else {
            cout << "OVF: The stack is FULL" << endl;
        } // overflow!
    }

    void Pop() {
        if (top_index >= 0) {
            top_index--;
        } // underflow가 아닌 경우
        else {
            cout << "UDF : The stack is Empty" << endl;
        } // underflow!
    }
/*
스택이 비어있는지 확인하는 함수. 빈 스택의 top_index = -1
따라서 빈 스택의 경우 : true 반환
아닌 경우 : false 반환
*/
    bool IsEmpty() { 
        return top_index == -1;
    }

/*
스택의 가장 위에 있는 값을 반환하는 함수
*/

    T Top() {
        return arr[top_index];
    }
};

template <typename T>
class Queue {
private:
    Stack<T> origin_stack; // 입력된 스택
    Stack<T> shifted_stack; // 입력된 스택을 바꿔서 출력할 스택
public:
    Queue(int size) : origin_stack(size), shifted_stack(size) { } //

    void Push(T value) {
        while (!shifted_stack.IsEmpty()) { // 새 스택이 비지 않은 경우
            origin_stack.Push(shifted_stack.Top()); // 새 스택의 top 값을 입력 스택에 push
            shifted_stack.Pop(); // 출력 스택의 top 값 pop
        }
        origin_stack.Push(value); // 새 스택이 빈 경우엔 입력받은 value 값 push
    }
/*
POP 함수!!
입력스택이 비어있지 않은 경우 : 입력스택의 top 값을 출력스택에 push 후 입력스택의 top 값 pop.
                                즉 입력스택의 값을 출력스택으로 옮김
                                이때 입력스택에 1 2 3 순서로 저장되어있다면 출력스택에 저장되는 순서는 3 2 1
*/
    void Pop() {
        if (!origin_stack.IsEmpty()) { // 입력 스택이 비어있지 않은 경우
            while (!origin_stack.IsEmpty()) {
                shifted_stack.Push(origin_stack.Top()); 
                origin_stack.Pop();
            }
        }
       shifted_stack.Pop();
    }
/*
1. 입력스택이 빌 때까지 출력 스택에 입력스택의 값 옮김
2. 출력스택이 빌 때까지 top값 출력 > 입력스택에 top값 push 해서 원래 스택 복원 > 출력스택은 pop
*/
    void Print() {
        if (!origin_stack.IsEmpty()) { // origin_stack이 빌 때까지
            while (!origin_stack.IsEmpty()) { 
                shifted_stack.Push(origin_stack.Top());//새 스택에 원래 스택의 top_index값을 push
                origin_stack.Pop(); //방금 push한 값 pop
            }
        }

        while (!shifted_stack.IsEmpty()) {
            T value = shifted_stack.Top(); // 새 스택의 top값 반환
            cout << value << " "; // 그 값 출력
            origin_stack.Push(value); // 
            shifted_stack.Pop();
        }
        cout << endl;
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
