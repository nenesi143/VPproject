#include "Utils.h"
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

template <typename T>

T GetIntValue(){
    T n;
    wcin.exceptions(wios::failbit | wios::badbit);  // failbit - невозможность интерпретирования string в int
                                                    // badbit - ошибка чтения потока
    while (true){
        try{
            wcin >> n;
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
            return n;
        }
        catch (const ios_base::failure& error){
            wcout << L"Неверный ввод, ошибка " << error.what() <<  L" ! Повторите попытку: ";
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
        }
    }
}