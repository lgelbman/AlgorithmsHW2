template <class T> 
struct Node {

    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = 0;
    }
};