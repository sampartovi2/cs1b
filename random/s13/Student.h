#ifndef STUDENT_H
#define STUDENT_H

#include <string>

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

    
}


#endif