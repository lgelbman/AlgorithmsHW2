template <class T> 
class MyVector{

     private:
        T* array;
        static const int INCREASING_FACTOR = 2;
        int currSize;
        int currFilled;
        static const int STARTING_SIZE = 10;

        void increaseArraySize() {
            T* array2 = new T[currSize * INCREASING_FACTOR];
            for (int i = 0; i < currFilled; i++) {
                *(array2 + i) = *(array + i);
            }
            T* ptr = array;
            array = array2;
            delete[] ptr;
            currSize *= 2;
        }

    public:
        MyVector() {
            array = new T[STARTING_SIZE];
            currSize = STARTING_SIZE;
            currFilled = 0;
        }

        void add(T data) {
            if (currFilled < currSize) {
                T* ptr = array + (currFilled );
                *ptr = data;
                currFilled++;
            } else {
                this->increaseArraySize();
                add(data);
            }
        }

        T get(int index) {
            if (currFilled * sizeof(T) < index) {
                //out of bounds
            }
            T* address = array + (index);
            T val = *address;
            return val;
        }
};