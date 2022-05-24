#include <iostream>
using namespace std;

class SortAlgorithm {
private:
    static SortAlgorithm* _algorithm;
    void (*currentAlgorithm)(float[], int);
    SortAlgorithm();
public:
    static SortAlgorithm* getObject(void (*pAlg)(float [], int) = NULL);
    static void SelectionSort(float [], int);
    static void InterchangeSort(float [], int);
    static void InsertionSort(float [], int);
    void Sort(float [], int);
};

SortAlgorithm* SortAlgorithm::_algorithm = NULL;
SortAlgorithm::SortAlgorithm() {
    currentAlgorithm = InsertionSort;
}


SortAlgorithm* SortAlgorithm::getObject(void (*pAlg)(float [], int)) {
    if (_algorithm == NULL) {
        _algorithm = new SortAlgorithm();
    }
    if (pAlg != NULL) {
        _algorithm->currentAlgorithm = pAlg;
    }
    return _algorithm;
}

void SortAlgorithm::Sort(float a[], int n) {
    if (currentAlgorithm != NULL) {
        currentAlgorithm(a, n);
    }
}

void SortAlgorithm::SelectionSort(float a[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (i != min) {
            std::swap(a[i], a[min]);
        }
    }
}


void SortAlgorithm::InterchangeSort(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                std::swap(a[i], a[j]);
            }
        }
    }
}


void SortAlgorithm::InsertionSort(float a[], int n) {
    int j;
    float temp;
    for (int i = 1; i < n; i++) {
        j = i;
        temp = a[i];
        while (j > 0 && a[j - 1] > temp) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = temp;
    }
}



// main program
//
int main() {
    float a[] = { 1.4F, -5.2F, 3.3F, 0 };
    int n = sizeof(a) / sizeof(float);
    SortAlgorithm* alg = SortAlgorithm::getObject(SortAlgorithm::InsertionSort); 
    alg->Sort(a, n);

    cout << "Mang sau khi sap xep: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
    return 0;
}
