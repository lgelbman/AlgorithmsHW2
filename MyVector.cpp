#include "MyVector.h"

class MyVector {
    
    public:

        
        MyVector::MyVector() {
            array = new type[startingSize];
            currSize = startingSize;
            currFilled = 0;
        }

        void MyVector::pushBack(T data) {
            if (currFilled < currSize) {
                *(array + currFilled) = &data;
                currFilled++;
            } else {
                int* newMemory = sizeof(type) * INCREASING_FACTOR * currSize;

            }
        }

        T MyVector::popBack() {

        }
};