#include <exception>
#include <string>

using namespace std;

class InvalidInputException : public exception {
private:
    wstring message;

public:
    explicit InvalidInputException(const wstring& msg)
        : message(msg) {}

    const char* what() const noexcept override {
        return "InvalidInputException occurred.";
    }

    const wstring& GetMessage() const noexcept {
        return message;
    }
};

template <typename T>
T GetIntValue();
