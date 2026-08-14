class DynamicArray {
   public:
    int* p;
    int size;
    int capacity;
    DynamicArray(int capacity) {
        this->capacity = capacity;
        p = new int[capacity];
        size = 0;
    }

    int get(int i) { return *(p + i); }

    void set(int i, int n) { *(p + i) = n; }

    void pushback(int n) {
        if (size == capacity) resize();
        *(p + (size++)) = n;
    }

    int popback() { return *(p + size-- -1); }

    void resize() {
        capacity *= 2;
        int* p2 = new int[capacity];
        for (int i = 0; i < size; i++) {
            *(p2 + i) = *(p + i);
        }
        delete[] p;
        p = p2;
    }

    int getSize() { return size; }

    int getCapacity() { return capacity; }
};
