#include <iostream>
#include <vector>
#include "Product.hpp"
#include "Client.hpp"
#include "Order.hpp"

using namespace std;

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