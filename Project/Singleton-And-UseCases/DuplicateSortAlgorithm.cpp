#include <iostream>
using namespace std;

class SortAlgorithm {
private:
    static SortAlgorithm* _algorithm;
    void (*currentAlgorithm)(float[], int);
    SortAlgorithm();
public:
    static SortAlgorithm* getAlgorithm(void (*alg)(float [], int) = NULL);
    static void BubbleSort(float [], int);
    static void InsertionSort(float [], int);
    static void SelectionSort(float [], int);
    void Sort(float [], int);
};


SortAlgorithm* SortAlgorithm::_algorithm = NULL;
SortAlgorithm::SortAlgorithm() {
    currentAlgorithm = BubbleSort;
}

SortAlgorithm* SortAlgorithm::getAlgorithm(void (*alg)(float [], int)) {
    if (_algorithm == NULL) {
        _algorithm = new SortAlgorithm();
    }
    if (alg != NULL) {
        _algorithm->currentAlgorithm = alg;
    }
    return _algorithm;
}

void SortAlgorithm::BubbleSort(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            if (a[j] > a[j + 1])
                std::swap(a[j], a[j + 1]);
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

void SortAlgorithm::SelectionSort(float a[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (i != min) {
            std::swap(a[i], a[min]);
        }
    }
}

void SortAlgorithm::Sort(float a[], int n) {
    if (currentAlgorithm != NULL) {
        currentAlgorithm(a, n);
    }
}

int main() {
    float a[] = { 1, 2, 3, 4, 7, 5, 4, 2, 1 };
    int n = sizeof(a) / sizeof(float);
    SortAlgorithm* alg = SortAlgorithm::getAlgorithm(SortAlgorithm::SelectionSort);
    alg->Sort(a, n);
    cout << "Mang sau khi sort" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
    return 0;
}
