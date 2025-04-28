#include "Supplier.h"
#include <iomanip>

using namespace std;

wstring Supplier::getType() const{
    return m_type;
}

wstring Supplier::getSurname() const{
    return m_surname;
}

wstring Supplier::getName() const{
    return m_name;
}

int Supplier::getAge() const{
    return m_age;
}

void Supplier::setRecord() {
    User::setRecord();
    wcout << L"Введите тип поставляемой продукции: ";
    getline(wcin, m_type);
}

void Supplier::getRecord() const {
    User::getRecord();
    wcout << L"Тип поставляемой продукции: " << m_type << endl;
}

wostream& operator<<(wostream& out, const Supplier& record) {
    out << left
        << L"| " << setw(20) << record.getSurname()
        << L"| " << setw(20) << record.getName()
        << L"| " << setw(10) << record.getAge()
        << L"| " << setw(20) << record.getType() << L"|" << endl;
    return out;
}

wistream& operator>>(wistream& in, Supplier& record) {
    record.setRecord();
    return in;
}

bool Supplier::operator>(const Supplier& other) const {
    return m_surname > other.m_surname;
}

bool Supplier::operator<(const Supplier& other) const {
    return m_surname < other.m_surname;
}