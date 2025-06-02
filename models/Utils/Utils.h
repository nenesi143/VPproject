#include <exception>
#include <string>

using namespace std;

class MyException {
public:
    explicit MyException(const char* error)
        : m_error(error) {}

    const char* getError() const {
        return m_error;
    }

private:
    const char* m_error;
};

template <typename T>
T GetIntValue();
