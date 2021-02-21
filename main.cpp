#include <iostream>
#include "MyVector.h"
#include "LLIterator.h"
#include <string>

#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

using namespace std;

void vectAddAndRemoveIntegers();
void linkedListAddAndRemoveIntegers();
template <typename Func>long
long TimeFunc(Func f);
void vectAddAndRemoveStrings();
void linkedListAddAndRemoveStrings();
string getRandomString();


const int numOfOperations = 10000;

int main()
{
    cout << "test" << endl;
    long vectorTimeForIntegers = TimeFunc(vectAddAndRemoveIntegers);
    long linkedListTimeForIntegers = TimeFunc(linkedListAddAndRemoveIntegers);
    long vectorTimeForStrings = TimeFunc(vectAddAndRemoveStrings);
    long linkedListTimeForStrings = TimeFunc(linkedListAddAndRemoveStrings);
    cout << vectorTimeForIntegers << endl;
    cout << linkedListTimeForIntegers << endl;
    cout << vectorTimeForStrings << endl;
    cout << linkedListTimeForStrings << endl;
    
    return 0;
}

//copied from "Timing Example.txt"
template <typename Func>long
long TimeFunc(Func f){
    auto begin = steady_clock::now();
    f();
    auto end = steady_clock::now();
    return duration_cast<milliseconds>(end - begin).count();
}

void vectAddAndRemoveIntegers() {
    MyVector<int> vector;
    for (int i = 0; i < numOfOperations; i++) {
        vector.add(rand());
    }
    for (int i = 0; i < numOfOperations; i++) {
        vector.get(i);
    }
}

void linkedListAddAndRemoveIntegers() {
    LLIterator<int> linkedList;
    for (int i = 0; i < numOfOperations; i++) {
        linkedList.add(i);
    }
    for (int i = 0; i < numOfOperations; i++) {
        linkedList.getNext();
    }
}

void vectAddAndRemoveStrings() {
    MyVector<string> vector;
    for (int i = 0; i < numOfOperations; i++) {
        string s1 = getRandomString();
        vector.add(s1);
    }
    for (int i = 0; i < numOfOperations; i++) {
        vector.get(i);
    }
}

void linkedListAddAndRemoveStrings() {
    LLIterator<string> linkedList;
    for (int i = 0; i < numOfOperations; i++) {
        string s1 = getRandomString();
        linkedList.add(s1);
    }
    for (int i = 0; i < numOfOperations; i++) {
        linkedList.getNext();
    }
}

string getRandomString() {
    char alphabet[] = {'a', 'b', 'c','d','e','f',
        'g','h','i','j','k','l','m','n','o','p','q',
        's','t','u','v','w','x','y','z'};
    int len = rand() % 200;
    string str1;
    for (int i = 0; i < len; i++) {
        char randomChar = rand() % 26;
        str1 += alphabet[randomChar];
    }
    return str1;
}