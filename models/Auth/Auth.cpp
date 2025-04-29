#include "Auth.h"
#include <iostream>
#include <fstream>

using namespace std;

void registration(){
    wstring login, password, role;

    wcout << L"Введите логин: ";
    getline(wcin, login);
    wcout << L"Введите пароль: ";
    getline(wcin, password);
    wcout << L"Введите роль пользователя (admin/user): ";
    getline(wcin, role);
    wofstream file("users.txt", ios::app);

    if (!file.is_open()){
        wcout << "Произошла ошибка при открытии файла!" << endl;
        return;
    }
    file << login << L" " << password << L" " << role << endl;

    file.close();
    wcout << L"Вы успешно зарегистрировались! " << endl;
}

wstring authorization(){
    wstring login, password;

    wcout << L"Введите логин: ";
    getline(wcin, login);
    wcout << L"Введите пароль: ";
    getline(wcin, password);

    wifstream file("users.txt");

    if (!file.is_open()){
        wcout << L"Произошла ошибка при открытии файла!" << endl;
        return L"";
    }

    wstring tempLogin, tempPassword, tempRole;

    while (file >> tempLogin >> tempPassword >> tempRole){

        if (tempLogin == login and tempPassword == password){
            if (tempRole == L"admin"){
                wcout << L"Вы вошли как админ!" << endl;
            }
            else if (tempRole == L"user"){
                wcout << L"Вы вошли как пользователь!" << endl;
            }
            return tempRole;
        }
    }
    wcout << L"Неверные логин или пароль!" << endl;
    return L"";
}

wstring authMenu(){
    while (true){
        wcout << L"|-------------------------------------------|" << endl;
        wcout << L"| 1 - Зарегистрироваться                    |" << endl;
        wcout << L"|-------------------------------------------|" << endl;
        wcout << L"| 2 - Авторизоваться                        |" << endl;
        wcout << L"|-------------------------------------------|" << endl;

        int command;
        wcout << L"Номер команды: ";
        wcin >> command;
        wcin.ignore();

        switch(command){
            case 1:
                registration();
                break;
            case 2:{
                wstring role = authorization();
                return role;
            }
            default:
                wcout << L"Неправильная команда. Повторите попытку!" << endl;
        }
    }
}