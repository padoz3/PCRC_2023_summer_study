#include <iostream>
using namespace std;

class Polynomial { // polynomial = 다항식
private:
    class Node {
    public:
        float coef; // 계수
        int exp; // 차수
        Node* next; // 다음 노드를 가리킬 포인터
        Node (float c = 0, int e = 0) {coef = c; exp = e; } // Node 생성자
    };
    Node* first; // 첫번째 노드를 가리킬 포인터
    Node* last; // 마지막 노드를 가리킬 포인터
public:
    Polynomial() { first = nullptr; last = nullptr; } // Polynomial 생성자
    void Get_Polynomial(); // 다항식을 입력받을 함수
    void Insert(float c, int e); // 계수 c와 차수 e를 갖는 항을 다항식에 추가
    Polynomial operator +(const Polynomial& b); // 다항식 덧셈 결과 반환
    void Print(); // 다항식을 내림차순으로 출력
};

// 다항식을 입력받을 함수
void Polynomial::Get_Polynomial() {
    float c; // 계수를 입력받을 변수
    int e; // 차수를 입력받을 변수

    cout << "다항식 생성 시작 (계수에 0을 입력하면 생성을 중단합니다)" << endl;

    while(1) // 아래 조건문에 의해 중단되기 전까지 무한반복
    {
        cout << "추가할 항의 계수(실수)와 차수(정수)를 입력하세요 : " ;
        cin >> c >> e; // 계수와 차수 입력받음

        if( c == 0 ) // 계수로 0을 입력받으면
            break; // 함수 종료 (다항식 생성 중단)
        
        Insert(c, e); // 계수 c와 차수 e를 갖는 항을 추가
    }
}

// 계수 c와 차수 e를 갖는 항을 다항식에 추가 (맨 뒤에 추가함)
void Polynomial::Insert(float c, int e) {
    Node* newNode = new Node;
    newNode->coef = c;
    newNode->exp = e;
    newNode->next = nullptr;

    if (first == nullptr) { // 다항식이 비어있는 경우
        first = newNode;
        last = newNode;
    } else { // 그렇지 않은 경우
        last->next = newNode;
        last = newNode;
    }
}


// 다항식 덧셈 결과 반환
Polynomial Polynomial::operator +(const Polynomial& b) {
    Polynomial result; //두 다항식의 합을 저장할 다항식
    Node* ai = this->first; // 첫번째 다항식의 노드를 가리킬 포인터
    Node* bi = b.first; // 두번째 다항식의 노드를 가리킬 포인터

    while(1) // 아래 조건문에 의해 중단되기 전까지 무한반복
    {
        if ( ai == nullptr ) { // ai가 NULL인 경우 (다항식 a에 더이상 계산할 항이 없는 경우)
            while ( bi != nullptr ) { // bi가 NULL에 도달하면 반복 종료 (다항식 b에도 더 이상 계산할 항이 없을 때)
                result.Insert(bi->coef, bi->exp); //bi가 가리키는 항을 result에 추가
                bi = bi->next; // 다음 항을 가리킴
            }
            break; // 반복 종료
        } 
        else if ( bi == nullptr ) {// bi == NULL 인 경우 (다항식 b에 더이상 계산할 항이 없는 경우)
            while ( ai != nullptr ) {
                result.Insert(ai->coef, ai->exp);
                ai = ai->next;
            }
            break;
        }

        // 항상 차수가 더 큰 항을 result에 삽입하고 다음 항으로 넘어감.
        if(ai->exp > bi->exp) { // ai가 가리키는 항의 차수가 더 큰 경우
            result.Insert(ai->coef, ai->exp);
            ai = ai->next;
        }
        else if (ai->exp < bi->exp) { // ai가 가리키는 항의 차수가 더 작은 경우
            result.Insert(bi->coef, bi->exp);
            bi = bi->next;
        } 
        else { // ai와 bi가 가리키는 두 항의 차수가 같은 경우
            if(ai->coef + bi->coef == 0) {
                ai = ai->next;
                bi = bi->next;
            }
            else {
                result.Insert((ai->coef + bi->coef), ai->exp);
                ai = ai->next;
                bi = bi->next;
            }
        }
    }
    return result; // 덧셈이 완료된 다항식을 return
}

// 다항식을 내림차순으로 출력
void Polynomial::Print()
{
    Node* newNode = this->first;
    while(newNode != NULL) {
        if (newNode->next == NULL) {
            cout << newNode->coef << " * x^" << newNode->exp << endl;
            break;
        } else {
            cout << newNode->coef << " * x^" << newNode->exp << " + " ;
            newNode = newNode->next;
        }
    }
    cout << endl;
} 

int main ()
{
    Polynomial A, B;

    cout << "[A] ";
    A.Get_Polynomial();
    cout << "[B] ";
    B.Get_Polynomial();

    cout << "[A] = ";
    A.Print();
    cout << "[B] = ";
    B.Print();

    Polynomial C = A + B;

    cout << "[A] + [B] = ";
    C.Print();

    return 0;
}