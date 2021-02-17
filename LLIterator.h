#include "Node.h"

template <class T>
class LLIterator {
    private:

        Node<T>* first;
        Node<T>* current;

    public:

        LLIterator() {
            first = 0;
            current = 0;
        }

        void add(T data) {
            Node<T>* node = new Node<T>(data);
            if (first == 0) {
                current = first = node;
                return;
            } 
            Node<T>* ptr = first;
            while (ptr != 0) {
                if ((*ptr).next == 0) {
                    (*ptr).next = node;
                    return;
                }
                ptr = (*ptr).next;
            }
        }


        bool hasNext() {
            return current != 0;
        }
        
        T getNext() {
            T result = (*current).data;
            current = (*current).next;
            return result;
        }

        
};