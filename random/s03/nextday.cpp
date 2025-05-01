#include <iostream>
using namespace std;

enum class DayOfWeek
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

DayOfWeek getNextDay(DayOfWeek today)
{
    return (today == DayOfWeek::Sunday) ? DayOfWeek::Monday : static_cast<DayOfWeek>(static_cast<int>(today) + 1);
}

string dayToString(DayOfWeek day)
{
    switch (day)
    {
    case DayOfWeek::Monday:
        return "Monday";
    case DayOfWeek::Tuesday:
        return "Tuesday";
    case DayOfWeek::Wednesday:
        return "Wednesday";
    case DayOfWeek::Thursday:
        return "Thursday";
    case DayOfWeek::Friday:
        return "Friday";
    case DayOfWeek::Saturday:
        return "Saturday";
    case DayOfWeek::Sunday:
        return "Sunday";
    default:
        return "Invalid";
    }
}

int main()
{
    int dayInput;
    cout << "Enter the current day (1=monday, 2=sunday, etc.): ";
    cin >> dayInput;

    if (dayInput < 1 || dayInput > 7)
    {
        cout << "Invalid input! Please enter a number between 1 and 7.\n";
        return 1;
    }

    DayOfWeek today = static_cast<DayOfWeek>(dayInput);
    DayOfWeek nextDay = getNextDay(today);

    cout << "The next day is " << dayToString(nextDay) << endl;

    return 0;
}
