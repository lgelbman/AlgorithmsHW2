#include <iostream>
#include "MyVector.h"
#include "LLIterator.h"

using namespace std;

int main()
{
    
    MyVector<int> vect;
    for (int i = 0; i < 20; i++) {
        vect.add(i * i);
        cout << i * i << endl;
    }

    cout << "_______" << endl;

    for (int i = 0; i < 20; i++) {
        cout << vect.get(i) << endl;
    }

    cout << "----------" << endl;

    LLIterator<int> list;
    for (int i = 0; i < 20; i++) {
        list.add(i * i);
    }

    while (list.hasNext()){
        int num = list.getNext();
        cout << num << endl;
    }

    


    


    return 0;
}



