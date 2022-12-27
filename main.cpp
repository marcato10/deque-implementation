#include <iostream>

using namespace std;

class Node{
private:
    Node *back;
    string name;
    Node *head;

public:
    Node(){
        this->back = nullptr;
        this->head = nullptr;
    }

    Node(string pname){
        this->back = nullptr;
        this->name = pname;
        this->head = nullptr;
    }

    Node* getBack(){
        return this->back;
    }

    void setBack(Node *panterior){
        this->back = panterior;
    }

    string getName(){
        return this->name;
    }

    void setName(string pnome){
        this->name = pnome;
    }

    Node* getHead(){
        return this->head;
    }

    void setHead(Node *phead){
        this->head = phead;
    }
};

class Deque{
private:
    Node *frente;
    Node *cauda;
    int dequeSize;
public:
    Deque(){
        this->frente = nullptr;
        this->cauda = nullptr;
        dequeSize = 0;
    }

    void push_front(string pname){
        Node* aux = new Node;
        if(this->dequeSize <= 0){
            frente = aux;
            cauda = aux;
        }
        aux->setBack(frente);
        frente->setHead(aux);
        frente = aux;
        frente->setName(pname);
        dequeSize++;
    }

    void popFront(){
        if(this->dequeSize <= 0){
            cout << "Empty" << endl;
        }
        else{
            Node* aux = frente;
            frente = aux->getBack();
            delete aux;
            dequeSize--;
        }
    }
    string getTop(){
        if(this->dequeSize <= 0)
            return "Fila vazia";
        return frente->getName();
    }

    void push_back(string pname){
        Node *aux = new Node;
        if(this->dequeSize == 0){
            cauda = aux;
            frente = aux;
        }
        aux->setHead(cauda);
        cauda->setBack(aux);
        cauda = aux;
        cauda->setName(pname);
        dequeSize++;
    }

    void popBack(){
        if(this->dequeSize <= 0)
            cout << "Empty" << endl;
        else{
            Node *aux = cauda;
            cauda = aux->getHead();
            delete aux;
            dequeSize--;
        }
    }

    Node *getCauda(){
        if(this->dequeSize <= 0)
            return nullptr;
        return cauda;
    }
    Node *getFrente(){
        if(this->dequeSize <= 0)
            return nullptr;
        return this->frente;
    }

    int getDequeSize(){
        return this->dequeSize;
    }
    void setDequeSize(int pDequeSize){
        this->dequeSize = pDequeSize;
    }

    ~Deque(){
        while(this->dequeSize != 0){
            popFront();
        }
    };

};
