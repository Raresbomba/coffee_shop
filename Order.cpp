#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Order.hpp"

#include <memory>

string Order::getDateTime() {
    time_t timestamp;
    time(&timestamp);
    return { (ctime(&timestamp)) };
}

Order::Order(const int id, const vector<Product*>& products, const Client& client){
    this->id = id;
    this->date = getDateTime();
    for (const Product* productPtr : products) {
        // Aici se apelează metoda clone() corectă (Drink::clone, Dessert::clone, etc.)
        this->products.push_back(unique_ptr<Product>(productPtr->clone()).get());
        this->price += productPtr->FinalPrice();
    }
    this->client = client;
}

void Order::addProductInOrder(const Product& product) {
    this->products.push_back(unique_ptr<Product>(product.clone()).get());
    this->price += product.getProductPrice();
}

ostream& operator<<(ostream& os, const Order& order) {
    os << "Id Comanda: " << order.id << endl;
    os << "Produse: " << endl;
    for (const auto& productPtr : order.products) {
        os << productPtr->getProductName() << ' ' << productPtr->FinalPrice() << endl;
    }
    os << "Total: " << order.price << endl;
    os << "Comanda plasata la " << order.date;
    return os;
}