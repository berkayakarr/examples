#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class ArrayList {
private:
    T* arr;         // Dinamik dizi
    int capacity;   // Dizi kapasitesi
    int size;       // Mevcut eleman sayısı

    // Kapasiteyi artırma fonksiyonu
    void resize() {
        if (capacity == 0) {
            capacity = 1; 
        } else {
            capacity *= 2; 
        }

        T* newArr = new T[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

public:
    
    ArrayList(int initialCapacity = 0) {
        capacity = initialCapacity > 0 ? initialCapacity : 1;
        size = 0;
        arr = new T[capacity];
    }

    // Destructor
    ~ArrayList() {
        delete[] arr;
    }

    
    void add(const T& value) {
        if (size == capacity) {
            resize();
        }
        arr[size] = value;
        size++;
    }

    
    void insert(int index, const T& value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }

        if (size == capacity) {
            resize();
        }

        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = value;
        size++;
    }

    
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    
    T get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

   
    int length() const {
        return size;
    }

   
    void clear() {
        delete[] arr;
        arr = new T[capacity];
        size = 0;
    }

    
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    
    ArrayList<string>* list1 = new ArrayList<string>(0);

    // Eleman ekleme
    list1->add("apple");    // 0
    list1->add("orange");   // 1
    list1->add("banana");   // 2
    list1->add("kiwi");     // 3
    list1->add("plum");     // 4
    list1->add("cherry");   // 5
    list1->print();

    
    list1->insert(3, "blueberry");

    
    list1->remove(5);
    list1->print();

    
    try {
        cout << "list1->get(5) = " << list1->get(5) << endl;
        // this should produce exception
        cout << "list1->get(50) = " << list1->get(50) << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    cout << "list1->length() = " << list1->length() << endl;

   
    list1->clear();
    

    delete list1; 
    return 0;
}
