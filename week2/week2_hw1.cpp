#include <iostream>
using namespace std;

class Dictionary {
private:
    class Node {
    public:
        string data; // 단어를 저장할 변수
        Node* next; // 다음 노드의 주소를 저장할 포인터
    };
    Node* pStart; // 연결리스트가 비어 있다면 nullptr, 그렇지 않으면 첫번째 노드를 가리킴

public:
    Dictionary(string word); // word를 첫 노드로 갖는 연결 리스트 생성자
    void Find(string word); // word가 몇번째 위치에 있는지 출력. 없으면 없다고 출력
    void Insert(string word); // word를 사전식 순서에 따라 적절한 위치에 삽입
    void Delete(string word); // word를 리스트에서 삭제. 없는 경우도 예외처리 해야 함
    void Display(); // 연결리스트에 저장된 word를 보여주는 함수. 없는 경우도 예외처리 해야 함
};

// 생성자
Dictionary::Dictionary(string word) {
    Node* newNode = new Node; // 새 노드 동적할당
    newNode->data = word; // 새 노드의 data 값에 word 저장
    newNode->next = nullptr; // 다음 노드를 가리키는 next에는 nullptr 저장

    pStart = newNode;
}

/*
함수 기능 : 단어가 몇 번째 위치에 있는 지 출력. 없으면 없다고 출력
*/
void Dictionary::Find(string word) {
    int order = 1; // 순서를 저장할 변수 
    Node* current = pStart;

    while (current != nullptr) {
        if (current->data == word) {
            cout << "This is the " << order << "th word." << endl;
            return;
        }
        current = current->next;
        order++;
    }
    cout << word << " not found in the Dictionary" << endl;
}

/*
함수 기능 : word를 사전식 순서에 따라 적절한 위치에 삽입
*/
void Dictionary::Insert(string word) {
    Node* newNode = new Node; // 새 노드 동적할당
    newNode->data = word; // 동적할당된 새 노드에 입력받은 word 저장
    newNode->next = nullptr;

    if (pStart == nullptr) { // 연결리스트가 비어있는 경우
        pStart = newNode;
    } else { // 연결리스트가 비어있지 않은 경우
        Node* current = pStart; // 포인터형 노드 동적할당
        Node* prior = nullptr;

        while (current != nullptr && word > current->data) { // word가 현재 노드보다 큰 경우, 다음 노드로 이동
            prior = current;
            current = current->next;
        }

        if (prior == nullptr) { // 첫 번째 노드보다 작은 경우
            newNode->next = pStart;
            pStart = newNode;
        } else { // 중간에 삽입하는 경우
            prior->next = newNode;
            newNode->next = current;
        }
    }
}

/*
함수 기능 : word를 리스트에서 삭제. 없는 경우도 예외처리 해야 함
*/
void Dictionary::Delete(string word) {
    if (pStart == nullptr) { // 연결리스트가 비어있는 경우
        cout << "The Dictionary Is EMPTY!!" << endl;
        return;
    }

    Node* current = pStart;
    Node* prior = nullptr;

    // 첫 번째 노드를 삭제하는 경우
    if (current->data == word) {
        pStart = current->next;
        delete current;
        cout << word << " deleted." << endl;
        return;
    }

    // 중간이나 마지막 노드를 삭제하는 경우
    while (current != nullptr) {
        if (current->data == word) {
            prior->next = current->next;
            delete current;
            cout << word << " deleted." << endl;
            return;
        }
        prior = current;
        current = current->next;
    }

    // 단어가 사전에 없는 경우
    cout << word << " not found in the dictionary." << endl;
}

/*
함수 기능 : 연결리스트에 저장된 word를 보여주는 함수. 없는 경우도 예외처리 해야 함
*/
void Dictionary::Display() {
    if (pStart == nullptr) {
        cout << "The Dictionary Is EMPTY!!" << endl;
    }

    Node* current = pStart;

    while (current != nullptr) {
        cout << current->data << "\t";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Dictionary Dt("ABC");
    int input = 1;
    string word;

    while (input) {
        cout << "(1)INSERT    (2)DELETE    (3)DISPLAY    (4)FIND    (5)END" << endl;
        cin >> input;

        if (input == 1) {
            cout << "Word to insert: ";
            cin >> word;
            Dt.Insert(word);
        } else if (input == 2) {
            cout << "Word to delete: ";
            cin >> word;
            Dt.Delete(word);
        } else if (input == 3) {
            Dt.Display();
        } else if (input == 4) {
            cout << "Word to find: ";
            cin >> word;
            Dt.Find(word);
        } else if (input == 5) {
            cout << "End The Program";
            return 0;
        }
    }
}
