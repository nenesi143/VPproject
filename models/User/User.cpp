#include "User.h"
#include "../Utils/Utils.h"
#include <iostream>
#include <limits>

using namespace std;

void User::setRecord() {
    wcout << L"Введите фамилию: ";
    getline(wcin, m_surname);
    wcout << L"Введите имя: ";
    getline(wcin, m_name);
    wcout << L"Введите возраст: ";
    m_age = GetIntValue<int>();
    if (m_age < 18){
        wcout << L"Возраст меньше 18, повторите попытку: ";
        m_age = GetIntValue<int>();
    }
}

void User::getRecord() const {
    wcout << L"Фамилия: " << m_surname << endl;
    wcout << L"Имя: " << m_name << endl; 
    wcout << L"Возраст: " << m_age << endl;
}