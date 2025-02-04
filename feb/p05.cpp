#include <iostream>
using namespace std;

int find_gcf(int num1, int num2){
    int remainder = num2+1;
    int smallest;
    int largest;
  
while(remainder>0) {
    if(num1>remainder) num1 = smallest;
    else remainder = smallest;
 remainder = num2-smallest;
}
 return remainder;

}

int main(){
 int num1;
 int num2;
 cin >> num1;
 cin >> num2;

 cout << find_gcf(num1, num2);
}