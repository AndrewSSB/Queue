#include <iostream>
#include <list>
#include <queue>
using namespace std;

template<typename T = int>
class Queue{
private:
    list<T> LinkedList; //List container is a doubly linked list implementation
    int _size;
public:
    Queue(){_size = 0;} // Create an empty stack or

    Queue(T elem) {this->LinkedList.push_back(elem); _size = 1;}

    int GetSize(){return _size;}

    bool isEmpty(){return _size == 0;}

    void Push(T);

    void Pop();

    T Top();

    void Print();
};

template<typename T>
void Queue<T>::Push(T elem){
    _size++;
    this->LinkedList.push_back(elem);
}

template<typename T>
void Queue<T>::Pop(){
    if (isEmpty()){
        cout << "\nList is empty";
        return;
    }
    else{
        T el = LinkedList.front();
        this->LinkedList.pop_front();
        _size--;
        cout << "\nRemoved " << el << " from stack";
    }
}

template<typename T>
T Queue<T>::Top(){
    if (isEmpty())
        throw runtime_error("Queue empty");
    return LinkedList.front();
}

template<typename T>
void Queue<T>::Print(){
    typename list<T>::iterator it;
    for (it = LinkedList.begin(); it != LinkedList.end(); ++it){
        cout << (*it) << " ";
    }
}

int main()
{
    //In c++ it's already an implementation of a stack.
    queue<int> Queuee;
    Queuee.push(10);
    Queuee.front(); //primul element
    Queuee.pop();

    Queue<int> q;
    q.Push(10);
    q.Push(20);
    q.Push(30);
    q.Push(40);
    q.Print();
    cout << "\n" << "Top element: " << q.Top();
    q.Pop();
    cout << "\nTop element after pop: " << q.Top();
    cout << "\n";
    q.Print();
    cout << "\nSize: " << q.GetSize();
    return 0;
}
