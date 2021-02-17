#include <iostream>
#include "MyVector.h"

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
    


    


    return 0;
}



