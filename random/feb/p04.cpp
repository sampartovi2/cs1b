#include <iostream>
using namespace std;

int sum_range(int start, int end){
int sum = 0;

    while(start<end) {
        sum += (start++) + (end--);
    }
    return sum;
}

int main(){
    int start;
    int end;
    cin >> start;
    cin >> end;
   cout << " Sum: " << sum_range(start, end);




}