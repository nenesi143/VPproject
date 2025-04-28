#include "Employee.h"
#include <iomanip>

using namespace std;

wstring Employee::getPosition() const{
    return m_position;
}

wstring Employee::getSurname() const{
    return m_surname;
}

wstring Employee::getName() const{
    return m_name;
}

int Employee::getAge() const{
    return m_age;
}

void Employee::setRecord() {
    User::setRecord();
    wcout << L"Введите должность сотрудника: ";
    getline(wcin, m_position);
}

void Employee::getRecord() const {
    User::getRecord();
    wcout << L"Должность: " << m_position << endl; 
}

wostream& operator<<(wostream& out, const Employee& record) {
    out << left
        << L"| " << setw(20) << record.getSurname()
        << L"| " << setw(20) << record.getName()
        << L"| " << setw(10) << record.getAge()
        << L"| " << setw(20) << record.getPosition() << L"|" << endl;
    return out;
}

wistream& operator>>(wistream& in, Employee& record){
    record.setRecord();
    return in;
}

bool Employee::operator>(const Employee& other) const{
    return m_surname > other.m_surname;
}
bool Employee::operator<(const Employee& other) const{
    return m_surname < other.m_surname;
}