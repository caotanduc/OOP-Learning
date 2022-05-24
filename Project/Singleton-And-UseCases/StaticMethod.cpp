#include<iostream>
#include <iterator>
using namespace std;

class SortAlgorithm {
private:
    static void (*currentAlgorithm)(float[], int);
    SortAlgorithm();
public:
    static void setAlgorithm(void (*pAlg)(float[], int));
    /* static void SelectionSort(float[], int); */ 
    static void BubbleSort(float[], int);
    /* static void InsertionSort(float[], int); */
    static void Sort(float [], int);
};

void (*SortAlgorithm::currentAlgorithm)(float[], int) = BubbleSort;


void SortAlgorithm::setAlgorithm(void (*pAlg)(float[], int)) {
    if (pAlg != NULL) {
        currentAlgorithm = pAlg;
    }
}

void SortAlgorithm::Sort(float a[], int n) {
    if (currentAlgorithm != NULL) {
        currentAlgorithm(a, n);
    }
}

void SortAlgorithm::BubbleSort(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

int main() {
    float a[] = { 1, 2, 2, 6, 5, 4, 3, 2, 1 };
    int n = sizeof(a) / sizeof(float);
    SortAlgorithm::setAlgorithm(SortAlgorithm::BubbleSort);
    SortAlgorithm::Sort(a, n);

    cout << "Mang sau khi sap xep: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
    cin.get();
    return 0;
}
