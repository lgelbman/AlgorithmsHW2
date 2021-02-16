using namespace std;

template <class T> 
class MyVector{
    
    private:
        int* array;
        const int INCREASING_FACTOR = 2;
        int currSize;
        int currFilled;
        const int STARTING_SIZE = 10;
    
    public:
        MyVector();
        template <class T> 
        void pushBack(T data);
        template <class T> 
        T popBack();

};