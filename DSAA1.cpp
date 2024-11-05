#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    string surname;
    string id;
    string position;

public:
    // Setters
    void setName(string n) {
        name = n;
    }

    void setSurname(string s) {
        surname = s;
    }

    void setId(string i) {
        id = i;
    }

    void setPosition(string p) {
        position = p;
    }

    // Getters
    string getName() {
        return name;
    }

    string getSurname() {
        return surname;
    }

    string getId() {
        return id;
    }

    string getPosition() {
        return position;
    }
};

int main() {
    string name, surname, id, pos;
    Employee* emp = new Employee();

    // Enter employee information:
    cout << "Enter employee information:" << endl;
    cout << "\tname = "; cin >> name;
    emp->setName(name);

    cout << "\tsurname = "; cin >> surname;
    emp->setSurname(surname);

    cout << "\tid = "; cin >> id;
    emp->setId(id);

    cout << "\tposition = "; cin >> pos;
    emp->setPosition(pos);

    // Display the entered information
    cout << "\nEmployee Information: " << endl;
    cout << "Name: " << emp->getName() << endl;
    cout << "Surname: " << emp->getSurname() << endl;
    cout << "ID: " << emp->getId() << endl;
    cout << "Position: " << emp->getPosition() << endl;

    delete emp;
    return 0;
}