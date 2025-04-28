#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    protected:
        wstring m_name;
        wstring m_surname;
        int m_age;
        /*wstring m_login;
        wstring m_password;*/
    
    public:
        virtual void setRecord() = 0;
        virtual void getRecord() const = 0;
};

#endif