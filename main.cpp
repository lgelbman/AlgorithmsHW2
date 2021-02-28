#include <iostream>
#include "MyVector.h"
#include "LLIterator.h"
#include <string>
#include <utility>

#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

using namespace std;

void vectAddAndGetIntegers();
void linkedListAddAndGetIntegers();
template <typename Func>long
long TimeFunc(Func f);
void vectAddAndGetStrings();
void linkedListAddAndGetStrings();
string getRandomString();
void linkedListAddAndGetStringsUsingRRefs();
void vectorAddAndGetStringsUsingRRefs();
void test();


const int numOfOperations = 100000;

int main()
{
    cout << "test" << endl;
    long vectorTimeForIntegers = TimeFunc(vectAddAndGetIntegers);
    long linkedListTimeForIntegers = TimeFunc(linkedListAddAndGetIntegers);
    long vectorTimeForStrings = TimeFunc(vectAddAndGetStrings);
    long linkedListTimeForStrings = TimeFunc(linkedListAddAndGetStrings);
    long linkedListTimeForStringsUsingMoveSemantics =
        TimeFunc(linkedListAddAndGetStringsUsingRRefs);
    long vectorTimeForStingsUsingMoveSemantics =
        TimeFunc(vectorAddAndGetStringsUsingRRefs);
    cout << "Time for vector of integers: " << vectorTimeForIntegers << endl;
    cout << "Time for linked list of integers: " << linkedListTimeForIntegers << endl;
    cout << "Time for vector of strings: " << vectorTimeForStrings << endl;
    cout << "Time for linked list of strings: " << linkedListTimeForStrings << endl;
    cout << "Time for vector of strings using move semantics: "
        << vectorTimeForStingsUsingMoveSemantics << endl;
    cout << "Time for linked list of strings using move semantics: "
        << linkedListTimeForStringsUsingMoveSemantics << endl;


    long test1 = TimeFunc(test);
    cout << "test" << test1 << endl;

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

void vectAddAndGetIntegers() {
    MyVector<int> vector;
    for (int i = 0; i < numOfOperations; i++) {
        vector.add(rand());
    }
    for (int i = 0; i < numOfOperations; i++) {
        vector.get(i);
    }
}

void linkedListAddAndGetIntegers() {
    LLIterator<int> linkedList;
    for (int i = 0; i < numOfOperations; i++) {
        linkedList.add(rand());
    }
    for (int i = 0; i < numOfOperations; i++) {
        linkedList.getNext();
    }
}

void vectAddAndGetStrings() {
    MyVector<string> vector;
    for (int i = 0; i < numOfOperations; i++) {
        string s1 = getRandomString();
        vector.add(s1);
    }
    for (int i = 0; i < numOfOperations; i++) {
        vector.get(i);
    }
}

void linkedListAddAndGetStrings() {
    LLIterator<string> linkedList;
    for (int i = 0; i < numOfOperations; i++) {
        string s1 = getRandomString();
        linkedList.add(s1);
    }
    for (int i = 0; i < numOfOperations; i++) {
        linkedList.getNext();
    }
}

std::string getRandomString() {
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

void linkedListAddAndGetStringsUsingRRefs() {
    LLIterator<string> linkedList;
    for (int i = 0; i < numOfOperations; i++) {
        linkedList.add(std::move(getRandomString()));
    }
    for (int i = 0; i < numOfOperations; i++) {
        linkedList.getNext();
    }
}

void vectorAddAndGetStringsUsingRRefs() {
    MyVector<string> vect;
    for (int i = 0; i < numOfOperations; i++) {
        vect.add(std::move(getRandomString()));
    }
    for (int i = 0; i < numOfOperations; i++) {
        vect.get(i);
    }
}

void test() {
    LLIterator<int> linkedList;
    for (int i = 0; i < numOfOperations; i++) {
        getRandomString();
    }
}

