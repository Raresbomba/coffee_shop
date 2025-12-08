#ifndef OOP_EXCEPTIONS_HPP
#define OOP_EXCEPTIONS_HPP
#include <string>
#include <utility>

using namespace std;

class CoffeeShopException : public exception {
    string message;

    public:

    CoffeeShopException() = default;

    explicit CoffeeShopException(string  msg) : message(std::move(msg)){}

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidInputException final : public CoffeeShopException {
    public:
    explicit InvalidInputException(const string& msg) : CoffeeShopException("EROARE VALIDARE: " + msg) {}
};

class StockException final : public CoffeeShopException {
    public:
    explicit StockException(const string& msg) : CoffeeShopException("EROARE STOC" + msg) {}
};

class AccesException final : public CoffeeShopException {
    public:
    explicit AccesException(const string& msg) : CoffeeShopException("EROARE ACCESS" + msg) {}
};


#endif //OOP_EXCEPTIONS_HPP