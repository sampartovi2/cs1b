#include <iostream>
#include <fstream>

using namespace std;

struct Address  //struct to hold address info
{
    string city;
    string state;
};

struct Employee //struct to hold employee info
{
    int id;
    string name;
    double salary;
    Address address;
};

const int MAX_EMPLOYEES = 100;
Employee employees[MAX_EMPLOYEES];
int employeeCount = 0; //initially 0 before reading from file

void loadEmployeesFromFile(const string &filename) //function to get employees stored in file
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }
    employeeCount = 0;
    while (file >> employees[employeeCount].id)
    {
        file.ignore();
        getline(file, employees[employeeCount].name);
        file >> employees[employeeCount].salary;
        file.ignore();
        getline(file, employees[employeeCount].address.city);
        getline(file, employees[employeeCount].address.state);
        employeeCount++;
    }
    file.close();
}

void storeEmployeesToFile(const string &filename) //function to save employees to txt file
{
    ofstream file(filename);
    for (int i = 0; i < employeeCount; i++)
    {
        file << employees[i].id << "\n";
        file << employees[i].name << "\n";
        file << employees[i].salary << "\n";
        file << employees[i].address.city << "\n";
        file << employees[i].address.state << "\n";
    }
    file.close();
}

void printAllEmployees() //function to display all employees on the screen
{
    for (int i = 0; i < employeeCount; i++)
    {
        cout << "ID: " << employees[i].id << ", Name: " << employees[i].name
             << ", Salary: " << employees[i].salary << ", City: "
             << employees[i].address.city << ", State: " << employees[i].address.state << "\n";
    }
}

void addEmployee() //function to add a new employee to the list
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        cout << "Cannot add more employees\n";
        return;
    }
    cout << "Enter ID: ";
    cin >> employees[employeeCount].id;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, employees[employeeCount].name);
    cout << "Enter salary: ";
    cin >> employees[employeeCount].salary;
    cin.ignore();
    cout << "Enter city: ";
    getline(cin, employees[employeeCount].address.city);
    cout << "Enter state: ";
    getline(cin, employees[employeeCount].address.state);
    employeeCount++;
}

void updateEmployee(int id) //function to update employee info
{
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, employees[i].name);
            cout << "Enter New Salary: ";
            cin >> employees[i].salary;
            cin.ignore();
            cout << "Enter New City: ";
            getline(cin, employees[i].address.city);
            cout << "Enter New State: ";
            getline(cin, employees[i].address.state);
            return;
        }
    }
    cout << "Employee not found!\n";
}

void removeEmployee(int id) //function to remove an employee
{
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            for (int j = i; j < employeeCount - 1; j++)
            {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            cout << "Employee removed successfully.\n";
            return;
        }
    }
    cout << "Employee not found!\n";
}

void searchEmployeeByName(const string &name) //function to search for employee
{
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].name == name)
        {
            cout << "ID: " << employees[i].id << ", Salary: " << employees[i].salary
                 << ", City: " << employees[i].address.city << ", State: " << employees[i].address.state << "\n";
            return;
        }
    }
    cout << "Employee not found!\n";
}

void printHighestSalaryEmployee() //function to display employee with highest salary
{
    if (employeeCount == 0)
    {
        cout << "No employees available!\n";
        return;
    }
    int maxIndex = 0;
    for (int i = 1; i < employeeCount; i++)
    {
        if (employees[i].salary > employees[maxIndex].salary)
        {
            maxIndex = i;
        }
    }
    cout << "Highest Salary Employee: ID: " << employees[maxIndex].id
         << ", Name: " << employees[maxIndex].name
         << ", Salary: " << employees[maxIndex].salary
         << ", City: " << employees[maxIndex].address.city
         << ", State: " << employees[maxIndex].address.state << "\n";
}

void menu()
{
    int choice, id;
    string name;
    do
    {
        cout << "\nEmployee Management System\n";
        cout << "1. Print all employees\n";
        cout << "2. Update an employee\n";
        cout << "3. Remove an employee\n";
        cout << "4. Add a new employee\n";
        cout << "5. Store employees to file\n";
        cout << "6. Load employees from file\n";
        cout << "7. Search employee by name\n";
        cout << "8. Print employee with highest salary\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) //cases for each possible choice
        {
        case 1:
            printAllEmployees();
            break;
        case 2:
            cout << "Enter ID to update: ";
            cin >> id;
            updateEmployee(id);
            break;
        case 3:
            cout << "Enter ID to remove: ";
            cin >> id;
            removeEmployee(id);
            break;
        case 4:
            addEmployee();
            break;
        case 5:
            storeEmployeesToFile("employees.txt");
            break;
        case 6:
            loadEmployeesFromFile("employees.txt");
            break;
        case 7:
            cout << "Enter Name to search: ";
            cin.ignore();
            getline(cin, name);
            searchEmployeeByName(name);
            break;
        case 8:
            printHighestSalaryEmployee();
            break;
        case 9:
            cout << "Exiting program\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 9);
}

int main()
{
    loadEmployeesFromFile("employees.txt");
    menu();
    return 0;
}
