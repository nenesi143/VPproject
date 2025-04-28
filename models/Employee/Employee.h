#include <iostream>
#include "../User/User.h"

using namespace std;

class Employee : public User {
    private:
        wstring m_position;
    
    public:
        wstring getPosition() const;
        wstring getSurname() const;
        wstring getName() const;
        int getAge() const;

        void setRecord() override;
        void getRecord() const override;

        friend wostream& operator<<(wostream& out, const Employee& employee);
        friend wistream& operator>>(wistream& in, Employee& employee);
        bool operator>(const Employee& other) const;
        bool operator<(const Employee& other) const;
};