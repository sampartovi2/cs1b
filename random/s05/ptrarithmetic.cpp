#include <iostream>
using namespace std;

void printArray(char *ptrstr){
    for(int i = 0; i < 5; i++){
        cout << *(ptrstr+i);
    }
}

int main(){
    char str[] = "hello";

    char* ptrstr = str;

    printArray(ptrstr);

    return 0;

}