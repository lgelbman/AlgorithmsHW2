template <class T> 
struct Node {

    T& data;
    Node<T>* next;

    Node(T& data) : data(data) {
        this->next = 0;
    }

    Node(T&& data) : data(data) {
        this->next = 0;
    }

};