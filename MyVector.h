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
            this->array = array2;
            delete[] ptr;
            this->currSize *= 2;
        }

    public:
        MyVector() {
            this->array = new T[STARTING_SIZE];
            this->currSize = STARTING_SIZE;
            this->currFilled = 0;
        }

        void add(T data) {
            if (currFilled < currSize) {
                T* ptr = this->array + this->currFilled;
                *ptr = data;
                this->currFilled++;
            } else {
                this->increaseArraySize();
                add(data);
            }
        }

        T get(int index) {
            if (this->currFilled  < index) {
                //out of bounds
            }
            T* address = this->array + (index);
            T val = *address;
            return val;
        }
};