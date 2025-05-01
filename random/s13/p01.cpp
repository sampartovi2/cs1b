#include <iostream>

using namespace std;

class Student{
    private:
    static int objectCount = 0;
    int id;

    public:
    Student(){
        objectCount++;
    }
    ~Student(){
        objectCount--;
    }

    static int getObjCount(){
        return objectCount;
    }
    void displayObjCount(){
        cout << "\nThere are " << objectCount << " objects\n";
    }

    void setID(){
        
    }

    
}



int main(){
 
}