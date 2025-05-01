#include<iostream> 
using namespace std; 

class Address { 
    public: 
    Address() { 
        number = 12345;
        street = "Saddleback Street"; 
        city = "Mission Viejo";
        state = "CA";
        zip = 92692;
    }
    void display() { 
        cout << number << " " << street << endl; 
        cout << city << ", " << state << " " << zip << endl << endl; 
    }
    private: 
    int number;
    string street; 
    string city; 
    string state; 
    int zip; 
};

class Person { 
    public: 
    Person(int a = 12, string n = "", char g = 'n') { 
        age = a; 
        name = n; 
        gender = g; 
    }
    void display() { 
        cout << age << endl; 
        cout << name << endl; 
        cout << gender << endl; 
        address.display(); 
    }
    void compareYourself(Person other) { 
        // cout << this->age << endl; 
        // cout << this->name << endl;  // *this.name
        // cout << this->gender << endl; 

        // cout << other.age << endl; 
        // cout << other.name << endl; 
        // cout << other.gender << endl; 
        if (this->age == other.age and 
            this->name == other.name and
            this->gender == other.gender) // let's ignore the address for now
            {
                cout << this->name <<  ": I am equal to " << other.name << "!\n";
            } else { 
                cout << this->name <<  ": I am NOT equal to " << other.name << "!\n";
            }
    }

    private: 
    int age;        // int built-in type
    string name;    // string type
    char gender;    // char built-in type
    Address address;    // is not a built-in type of c++. It is a user defined type
}; 

int main() { 
    Person j(19, "Jacob", 'm');
    Person h(19, "Jacob", 'm');
    j.display(); 
    h.display();
    j.compareYourself(h); 
    h.compareYourself(j); 
}