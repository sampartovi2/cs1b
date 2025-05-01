#include <iostream>
using namespace std;

class BankAccount{
    private:
     int accountNumber;
     string ownerName;
     double balance;

    public:
     BankAccount(int a, string o, double b) : accountNumber(a), ownerName(o), balance(b) {}


     void deposit(double amount){
        if(amount > 0){
         balance += amount;
         cout << "Successfully deposited $" << amount;
        }
        else cout << "Error: Must deposit a positive amount";
     };

     void withdraw(double amount){
      double newBal = balance - amount;
      if(newBal >= 0) {
         balance = newBal;
         cout << "Successfuly withdrew $" << amount;
      }
      else cout << "Not enough in account to withdraw!";
     };

     void displayAcc(){
      cout << "\n---------------\nAccount number: " << accountNumber;
      cout << "\nOwner name: " << ownerName;
      cout << "\nBalance: $" << balance;
     }

     void getBalance(){
        cout << "Balance: $" << balance;
     };
};

int main(){
BankAccount myAcc(1, "Jack", 50.00);
myAcc.getBalance();
cout << endl;
myAcc.deposit(50);
cout << endl;
myAcc.getBalance();
cout << endl;
myAcc.withdraw(50);
cout << endl;
myAcc.displayAcc();
cout << endl;
}
