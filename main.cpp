#include <iostream>
#include <ctime>
#include <vector>
#include "Product.hpp"
#include "Client.hpp"

using namespace std;

class Order {
    int id{};
    vector<Product> products;
    string date;
    float price{};
    Client client;

public:

    static string getDateTime() {
        time_t timestamp;
        time(&timestamp);
        return { (ctime(&timestamp)) };
    }

    Order() = default;

    Order(const int id, const vector<Product>& products, const Client& client){
        this->id = id;
        this->date = getDateTime();
        this->products = products;
        this->client = client;
        for (auto &product: products) {
            this->price += product.getProductPrice();
        }
    }

    void addProductInOrder(const Product& product) {
        this->products.push_back(product);
        this->price += product.getProductPrice();
    }

    friend ostream& operator<<(ostream& os, const Order& order) {
        os << "Id Comanda: " << order.id << endl;
        os << "Produse: " << endl;
        for (const Product& product : order.products) {
            os << product.getProductName() << ' ' << product.getProductPrice() << endl;
        }
        os << "Total: " << order.price << endl;
        os << "Comanda plasata la " << order.date;
        return os;
    }

    ~Order() = default;

};



int main() {

    const Product p1("Espresso", 10, drink);
    Product p2;
    p2.setProductName("Cappuccino");
    p2.setProductPrice(12);
    p2.setProductType(drink);
    cout << p1 << endl << p2.getProductName() << ' ' << p2.getProductPrice() << ' ' << p2.getProductType() << endl;
    const Product& p3 = p1;
    cout << p3 << endl;
    cout << endl;

    Client c1("Razvan", 243);
    c1.addPoints(15);
    cout << c1 << endl;

    vector<Product> products;
    products.push_back(p1);
    Order o1(554,products,c1);
    cout << o1 << endl;
    o1.addProductInOrder(p2);
    cout << o1 << endl;



    return 0;
}