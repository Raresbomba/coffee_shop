#ifndef OOP_ORDER_HPP
#define OOP_ORDER_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Product.hpp"
#include "Client.hpp"

using namespace std;

class Order {
    private:
    int id{};
    vector<Product> products;
    string date;
    float price{};
    Client client;

    public:

    Order() = default;

    Order(const int id, const vector<Product>& products, const Client& client);

    ~Order() = default;

    static string getDateTime();

    void addProductInOrder(const Product& product);

    friend ostream& operator<<(ostream& os, const Order& order);
};

#endif //OOP_ORDER_HPP