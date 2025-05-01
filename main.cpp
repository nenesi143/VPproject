#include "models/User/User.h"
#include "models/Employee/Employee.h"
#include "models/Supplier/Supplier.h"
#include "models/Auth/Auth.h"
#include "models/Vector/Vector.h"
#include "Utils.cpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){

    setlocale(LC_ALL, "Russian"); // Убрать Russian для Linux

    Vector<Supplier> recordsSup;
    Vector<Employee> recordsEmp;

    while (true){
        wstring role = authMenu(); 

        while (role != L""){

            if (role == L"admin"){
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
                wcout << L"| 9 - Фильтрация записей Supplier           |" << endl;
                wcout << L"|-------------------------------------------|" << endl;
                wcout << L"| 10 - Фильтрация записей Employee          |" << endl;
                wcout << L"|-------------------------------------------|" << endl;
                wcout << L"| 11 - Выйти из профиля                     |" << endl;
                wcout << L"|-------------------------------------------|" << endl;
                wcout << L"| 0 - Выход из приложения                   |" << endl;
                wcout << L"|-------------------------------------------|" << endl;
        
                wcout << L"Номер команды: ";
                int command = GetIntValue<int>();
        
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
                    }
                        break;
                    case 3: {
                        Employee emp;
                        wcin >> emp;
                        recordsEmp.push_back(emp);
                    }
                        break;
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
                    }
                        break;
                    case 5:{
                        if (recordsSup.empty()){
                            wcout << L"Список поставщиков пуст!" << endl;
                            break;
                        }
    
                        wcout << L"Как отсортировать поставщиков?" << endl;
                        wcout << L"1 - По возрастания (А-Я)" << endl;
                        wcout << L"2 - По убыванию (Я-А)" << endl;
                        wcout << L"Введите команду: ";

                        int choiceSup = GetIntValue<int>();
    
                        if (choiceSup == 1){
                            recordsSup.sortAscending();
                        }
                        else if (choiceSup == 2){
                            recordsSup.sortDescending();
                        }
                        else{
                            wcout << L"Неправильная команда!" << endl;
                        }
                    }
                        break;
                    case 6:{
                        if (recordsEmp.empty()){
                            wcout << L"Список сотрудников пуст!" << endl;
                            break;
                        }

                        wcout << L"Как отсортировать сотрудников?" << endl;
                        wcout << L"1 - По возрастания (А-Я)" << endl;
                        wcout << L"2 - По убыванию (Я-А)" << endl;
                        wcout << L"Введите команду: ";

                        int choiceEmp = GetIntValue<int>();
                        if (choiceEmp == 1){
                            recordsEmp.sortAscending();
                        }
                        else if(choiceEmp == 2){
                            recordsEmp.sortDescending();
                        }
                        else{
                            wcout << L"Неправильная команда!" << endl;
                        }
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
        
                        int indexSup = 1;
                        for (const auto& sup: recordsSup){
                            wcout << left
                            << L"| " << setw(4) << indexSup++;
                            wcout << sup;
                        }
        
                        wcout << setfill(L'-') << setw(85) << L"-" << endl;
                        wcout << setfill(L' ');
        
                        
                        wcout << L"Введите индекс удаляемой записи: ";
                        int delSup = GetIntValue<int>();
                        recordsSup.erase(delSup);
                        wcout << L"Запись удалена!" << endl;
                    }
                        break;
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
        
                        wcout << L"Введите индекс удаляемой записи: ";
                        int delEmp = GetIntValue<int>();
                        recordsEmp.erase(delEmp);
                        wcout << L"Запись удалена!" << endl;
                    }
                        break;
                    case 9:
                        recordsSup.filterByAge();
                        break;
                    case 10:
                        recordsEmp.filterByAge();
                        break;
                    case 11:{
                        role = L"";
                        break;
                    }
                    case 0:
                        return 0;
                    default:    
                        wcout << L"Неправильная команда, повторите попытку!" << endl;
                }
        }
        
            else if (role == L"user"){
                    wcout << L"|-------------------------------------------|" << endl;
                    wcout << L"| 1 - Вывести все записи                    |" << endl;
                    wcout << L"|-------------------------------------------|" << endl;
                    wcout << L"| 2 - Выйти из профиля                      |" << endl;
                    wcout << L"|-------------------------------------------|" << endl;
                    wcout << L"| 0 - Выход из приложения                   |" << endl;
                    wcout << L"|-------------------------------------------|" << endl;
        
                    wcout << L"Введите команду: ";
                    int command = GetIntValue<int>();
        
                    switch(command){
                        case 1:{
                            if (!recordsSup.empty() or !recordsEmp.empty()){
                                wcout << setfill(L'-') << setw(85) << L"-" << endl;
                                wcout << setfill(L' ');
                                wcout << left
                                << L"| " << setw(4) << L"№"
                                << L"| " << setw(20) << L"Фамилия"
                                << L"| " << setw(20) << L"Имя"
                                << L"| " << setw(10) << L"Возраст"
                                << L"| " << setw(20) << L"Личная ячейка" << L"|" << endl;
                                wcout << setfill(L'-') << setw(85) << L"-" << endl;
                                wcout << setfill(L' ');
        
                                int index = 1;
                                if (!recordsSup.empty()){
                                    for (const auto& sup : recordsSup){
                                        wcout << left
                                        << L"| " << setw(4) << index++;
                                        wcout << sup;
                                    }
                                }
                                if (!recordsEmp.empty()){
                                    for (const auto& emp : recordsEmp){
                                        wcout << left
                                        << L"| " << setw(4) << index++;
                                        wcout << emp;
                                    }
                                    wcout << setfill(L'-') << setw(85) << L"-" << endl;
                                    wcout << setfill(L' ');
                                }
                            }
                            else{
                                wcout << L"Нет записей для вывода!" << endl;
                            }
                        }
                        break;
                        case 2:
                            role = L"";
                            break;
                        case 0:
                            return 0;
                        default:
                            wcout << L"Неправильная команда, повторите попытку!" << endl;
                }
            }
            else{
                wcout << L"Произошла ошибка авторизации" << endl;
            }
        }   
    }
}
    