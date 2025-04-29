#include "User.h"
#include <iostream>
#include <limits>

using namespace std;

void User::setRecord() {
    wcout << L"Введите фамилию: ";
    getline(wcin, m_surname);
    wcout << L"Введите имя: ";
    getline(wcin, m_name);
    wcout << L"Введите возраст: ";
    wcin >> m_age;
    wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void User::getRecord() const {
    wcout << L"Фамилия: " << m_surname << endl;
    wcout << L"Имя: " << m_name << endl; 
    wcout << L"Возраст: " << m_age << endl;
}