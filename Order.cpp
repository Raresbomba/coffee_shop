#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Order.hpp"

string Order::getDateTime() {
    time_t timestamp;
    time(&timestamp);
    return { (ctime(&timestamp)) };
}

Order::Order(const int id, const vector<Product>& products, const Client& client){
    this->id = id;
    this->date = getDateTime();
    this->products = products;
    this->client = client;
    for (auto &product: products) {
        this->price += product.getProductPrice();
    }
}

void Order::addProductInOrder(const Product& product) {
    this->products.push_back(product);
    this->price += product.getProductPrice();
}

ostream& operator<<(ostream& os, const Order& order) {
    os << "Id Comanda: " << order.id << endl;
    os << "Produse: " << endl;
    for (const Product& product : order.products) {
        os << product.getProductName() << ' ' << product.getProductPrice() << endl;
    }
    os << "Total: " << order.price << endl;
    os << "Comanda plasata la " << order.date;
    return os;
}