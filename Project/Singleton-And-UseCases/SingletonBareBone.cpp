#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* _instance;                        // unique instance
    Singleton();                                        // constructor
public:
    static Singleton* getInstance();                    // get method
};

// initiate Singleton::_instance = NULL
Singleton* Singleton::_instance = NULL;

// declare constructor method || always redifined this constructor || do not use the default constructor
Singleton::Singleton() {
    // ... 
}

// implement getInstance function
Singleton* Singleton::getInstance() {
    if (_instance == NULL) {
        _instance = new Singleton();
    }
    return _instance;
}


// main program
int main() {
    Singleton* object = Singleton::getInstance();
    return 0;
}
