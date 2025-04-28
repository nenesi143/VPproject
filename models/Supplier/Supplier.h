#include <iostream>
#include "../User/User.h"

using namespace std;

class Supplier : public User {
    private:
        wstring m_type;

    public:
        wstring getType() const;
        wstring getSurname() const;
        wstring getName() const;
        int getAge() const;

        void setRecord() override;
        void getRecord() const override;

        friend wostream& operator<<(wostream& out, const Supplier& supplier);
        friend wistream& operator>>(wistream& in, Supplier& supplier);
        bool operator>(const Supplier& other) const;
        bool operator<(const Supplier& other) const;
};