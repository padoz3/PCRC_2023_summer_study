#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    class Node {
    public:
        T data; // 단어를 저장할 변수
        Node* next; // 다음 노드의 주소를 저장할 포인터
    };
    Node* front; // 첫번째 노드를 가리킬 포인터
    Node* rear; // 마지막 노드를 가리킬 포인터

public:
    Queue(T token); // Token 을 첫 노드로 갖는 연결리스트 생성자
    void Push(T token); // 제일 뒤에 노드 삽입
    void Pop(); // 제일 앞의 노드 삭제
    void Print(); // 제일 앞의 노드부터 순서대로 마지막 노드의 data까지 출력
};

// Token 을 첫 노드로 갖는 연결리스트 생성자
template <typename T>
Queue<T>::Queue(T token) {
    Node* newNode = new Node;
    newNode->data = token;
    newNode->next = nullptr;

    front = newNode;
    rear = newNode;
}

// 제일 뒤에 노드 삽입 
template <typename T>
void Queue<T>::Push(T token) {
    Node* newNode = new Node; // 새 노드 동적할당
    newNode->data = token;
    rear->next = newNode;
    rear = newNode;
} 

// 제일 앞의 노드 삭제
template <typename T>
void Queue<T>::Pop() {
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
    } else {
        Node* tmp = front;
        T data = tmp->data;
        front = front->next;

        delete tmp;
    }
}

// 제일 앞의 노드부터 순서대로 마지막 노드의 data까지 출력
template <typename T>
void Queue<T>::Print() {
    Node* Current = front;

    while(Current != nullptr) {
        cout << Current->data << "\t";
        Current = Current->next;
    }
    cout << endl;
}

int main(void)
{
    Queue<int> queue(3); // 3을 첫 노드로 갖는 연결리스트 생성
    queue.Print(); // print 3

    queue.Push(1); 
    queue.Print(); // print 3 1

    queue.Push(2);
    queue.Print(); // print 3 1 2

    queue.Push(3);
    queue.Print(); // print 3 1 2 3

    queue.Push(4);
    queue.Print(); // print 3 1 2 3 4

    queue.Pop();
    queue.Print(); // print 1 2 3 4

    queue.Pop();
    queue.Print(); // print 2 3 4

    queue.Push(5);
    queue.Print(); // print 2 3 4 5

    queue.Pop();
    queue.Print(); // print 3 4 5

    queue.Pop();
    queue.Print(); // print 4 5

    queue.Pop(); 

    return 0;
}