#include <iostream>
#include <vector>
#include "headers/Product.hpp"
#include "headers/Client.hpp"
#include "headers/Order.hpp"
#include "headers/Exceptions.hpp"
#include "headers/DrinkFactory.hpp"
#include "headers/DessertFactory.hpp"

using namespace std;

int main() {
    try {
        DrinkFactory drinkFactory;
        DessertFactory dessertFactory;

        std::vector<std::unique_ptr<Product>> products;

        ///Valid Drink test
        if (auto product1 = drinkFactory.createProduct("Latte"))
            products.push_back(std::move(product1));

        ///Valid Dessert test
        if (auto product2 = dessertFactory.createProduct("Pancakes"))
            products.push_back(std::move(product2));

        ///Invalid Drink test
        if (auto product3 = drinkFactory.createProduct("Mokka"))
            products.push_back(std::move(product3));

        for (const auto &product : products) {
            product->DisplayDetails();
        }
    }

    catch (CoffeeShopException& e) {
        std::cerr << "SPECIFIC ERROR: " << e.what() << std::endl;
    }
    catch (exception& e) {
        std::cerr << "DEFAULT ERROR: " << e.what() << std::endl;
    }

    return 0;
}