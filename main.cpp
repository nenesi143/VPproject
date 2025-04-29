#include "models/User/User.h"
#include "models/Employee/Employee.h"
#include "models/Supplier/Supplier.h"
#include "models/Auth/Auth.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){

    setlocale(LC_ALL, "Russian"); // Убрать Russian для Linux

    vector<Supplier> recordsSup;
    vector<Employee> recordsEmp;

    wstring role = authMenu();

    if (role == L"admin"){
        while (true){

            wcout << L"|-------------------------------------------|" << endl;
            wcout << L"| 1 - Инициализировать поля класса Supplier |" << endl;
            wcout << L"|-------------------------------------------|" << endl;
            wcout << L"| 2 - Вывести данные Supplier               |" << endl;
            wcout << L"|-------------------------------------------|" << endl;
            wcout << L"| 3 - Инициализировать поля класса Employee |" << endl;
            wcout << L"|-------------------------------------------|" << endl;
            wcout << L"| 4 - Вывести данные Employee               |" << endl;
            wcout << L"|-------------------------------------------|" << endl;
            wcout << L"| 5 - Отсортировать записи Supplier         |" << endl;
            wcout << L"|-------------------------------------------|" << endl;
            wcout << L"| 6 - Отсортировать записи Employee         |" << endl;
            wcout << L"|-------------------------------------------|" << endl;
            wcout << L"| 7 - Удалить запись Supplier               |" << endl;
            wcout << L"|-------------------------------------------|" << endl;
            wcout << L"| 8 - Удалить запись Employee               |" << endl;
            wcout << L"|-------------------------------------------|" << endl;
            wcout << L"| 0 - Выход из приложения                   |" << endl;
            wcout << L"|-------------------------------------------|" << endl;
    
            int command;
            wcout << L"Номер команды: ";
            wcin >> command;
            wcin.ignore();
    
            switch(command){
                case 1: {
                    Supplier sup;
                    wcin >> sup;
                    recordsSup.push_back(sup);
                    break;
                }
                case 2:{
                    if (recordsSup.empty()){
                        wcout << L"Список поставщиков пуст!" << endl;
                        break;
                    }
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
                    wcout << left
                        << L"| " << setw(4) << L"№"
                        << L"| " << setw(20) << L"Фамилия"
                        << L"| " << setw(20) << L"Имя"
                        << L"| " << setw(10) << L"Возраст"
                        << L"| " << setw(20) << L"Продукция" << L"|" << endl;
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
    
                    int indexSup = 1;
                    for (const auto& sup: recordsSup){
                        wcout << left
                        << L"| " << setw(4) << indexSup++;
                        wcout << sup;
                    }
    
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
                    break;
                }
                case 3: {
                    Employee emp;
                    wcin >> emp;
                    recordsEmp.push_back(emp);
                    break;
                }
                case 4:{
                    if (recordsEmp.empty()){
                        wcout << L"Список сотрудников пуст!" << endl;
                        break;
                    }
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
                    wcout << left
                        << L"| " << setw(4) << L"№"
                        << L"| " << setw(20) << L"Фамилия"
                        << L"| " << setw(20) << L"Имя"
                        << L"| " << setw(10) << L"Возраст"
                        << L"| " << setw(20) << L"Должность" << L"|" << endl;
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
    
                    int indexEmp = 1;
    
                    for (const auto& emp : recordsEmp){
                        wcout << left
                        << L"| " << setw(4) << indexEmp++;
                        wcout << emp;
                    }
                    
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
                    break;
                }
                case 5:
                    if (recordsSup.empty()){
                        wcout << L"Список поставщиков пуст!" << endl;
                        break;
                    }
                    int choiceSup;
                    wcout << L"Как отсортировать поставщиков?" << endl;
                    wcout << L"1 - По возрастания (А-Я)" << endl;
                    wcout << L"2 - По убыванию (Я-А)" << endl;
                    wcout << L"Введите команду: ";
                    wcin >> choiceSup;
                    wcin.ignore();
                    if (choiceSup == 1){
                        sort(recordsSup.begin(), recordsSup.end());
                    }
                    else if (choiceSup == 2){
                        sort(recordsSup.begin(), recordsSup.end(), greater<>());
                    }
                    else{
                        wcout << L"Неправильная команда!" << endl;
                    }
                    break;
                case 6:
                    if (recordsEmp.empty()){
                        wcout << L"Список сотрудников пуст!" << endl;
                        break;
                    }
                    int choiceEmp;
                    wcout << L"Как отсортировать сотрудников?" << endl;
                    wcout << L"1 - По возрастания (А-Я)" << endl;
                    wcout << L"2 - По убыванию (Я-А)" << endl;
                    wcout << L"Введите команду: ";
                    wcin >> choiceEmp;
                    wcin.ignore();
                    if (choiceEmp == 1){
                        sort(recordsEmp.begin(), recordsEmp.end());
                    }
                    else if(choiceEmp == 2){
                        sort(recordsEmp.begin(), recordsEmp.end(), greater<>());
                    }
                    else{
                        wcout << L"Неправильная команда!" << endl;
                    }
                    break;
                case 7:{
                    if (recordsSup.empty()){
                        wcout << L"Список поставщиков пуст!" << endl;
                        break;
                    }
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
                    wcout << left
                        << L"| " << setw(4) << L"№"
                        << L"| " << setw(20) << L"Фамилия"
                        << L"| " << setw(20) << L"Имя"
                        << L"| " << setw(10) << L"Возраст"
                        << L"| " << setw(20) << L"Продукция" << L"|" << endl;
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
    
                    int indexEmp = 1;
                    for (const auto& emp: recordsEmp){
                        wcout << left
                        << L"| " << setw(4) << indexEmp++;
                        wcout << emp;
                    }
    
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
    
                    int delSup;
                    wcout << L"Введите индекс удаляемой записи: ";
                    wcin >> delSup;
                    wcin.ignore();
                    recordsSup.erase(recordsSup.begin() + delSup - 1);
                    wcout << L"Запись удалена!" << endl;
                    break;
                }
                case 8:{
                    if (recordsEmp.empty()){
                        wcout << L"Список сотрудников пуст!" << endl;
                        break;
                    }
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
                    wcout << left
                        << L"| " << setw(4) << L"№"
                        << L"| " << setw(20) << L"Фамилия"
                        << L"| " << setw(20) << L"Имя"
                        << L"| " << setw(10) << L"Возраст"
                        << L"| " << setw(20) << L"Должность" << L"|" << endl;
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
    
                    int indexEmp = 1;
    
                    for (const auto& emp : recordsEmp){
                        wcout << left
                        << L"| " << setw(4) << indexEmp++;
                        wcout << emp;
                    }
                    
                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                    wcout << setfill(L' ');
    
                    int delEmp;
                    wcout << L"Введите индекс удаляемой записи: ";
                    wcin >> delEmp;
                    wcin.ignore();
                    recordsEmp.erase(recordsEmp.begin() + delEmp - 1);
                    wcout << L"Запись удалена!" << endl;
                    break;
                }
                case 0:
                    return 0;
                default:    
                    wcout << L"Неправильная команда, повторите попытку!" << endl;
            }
        }
    }

    else if (role == L"user"){
        wcout << L"ку" << endl;
    }
    else{
        wcout << L"Произошла ошибка авторизации" << endl;
    }
}
