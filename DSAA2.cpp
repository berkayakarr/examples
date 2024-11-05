#include <iostream>
#include <cmath>   // For rand()
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()
#include <chrono>  // For measuring time duration
using namespace std;
using namespace std::chrono;

// Function to perform selection sort
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int n;

    // Kullanıcıdan üretilecek rastgele sayı adedini alma
    cout << "Enter the number of elements to be sorted: "<<endl;
    cout<<"Example: selection sort 1000  :";
    cin >> n;

    if (n <= 0) {
        cout << "Warning: Invalid number of elements!" << endl;
        return 1;
    }

    // Dinamik olarak diziyi tahsis et
    int* arr = new int[n]; 
    
    srand(time(0)); // Rastgele sayı üreticiyi başlat

    // Rastgele sayılar oluşturma
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;  // 0 ile n arasında rastgele sayılar üret
        
    }

    double total_duration = 0.0;

    // Sıralama süresini ölç
    for (int i = 0; i < 5; i++) { // 5 kez sıralama
        auto start = high_resolution_clock::now(); // Başlangıç zamanı

        // Selection sort işlemi
        selectionSort(arr, n);
        
        auto end = high_resolution_clock::now(); // Bitiş zamanı

        // Süreyi hesapla
        duration<double> sorting_duration = end - start;
        total_duration += sorting_duration.count(); // Toplam süreyi ekle
        
    }

    // Ortalamayı hesapla ve yazdır
    cout <<"elapsed time     :"<< total_duration / 5 <<" seconds" <<endl; // Sıralama süresinin ortalamasını yazdır

    // Belleği serbest bırak
    delete[] arr; 

    return 0;
}
