#include <iostream>
#include <vector>
#include "headers/Product.hpp"
#include "headers/Client.hpp"
#include "headers/Order.hpp"
#include "headers/Exceptions.hpp"

using namespace std;

int main() {

    Product* espresso = new Drink("Espresso", 10, drink, "Small", "None", false, false);
    Product* pie = new Dessert("Pie Slice", 15, dessert, true, true, false,
        {"Lactose", "Gluten"}, false, {"Cream"});
    Product* prosciutto = new Sandwich("Prosciutto Sandwich", 15, sandwich, {"Focaccia", "Prosciutto", "Mozzarella", "Tomatoes"},
        false, {"Lactose", "Gluten"}, false, {"Arugula", "Pesto"});
    Product* prosciutto2 = prosciutto;

    espresso->DisplayDetails();
    pie->DisplayDetails();
    prosciutto->DisplayDetails();
    prosciutto2->DisplayDetails();

    try {
        Product* invalid = new Drink("Espresso", 5, drink, "Small", "None", false, false);
        invalid->DisplayDetails();
    }

    catch (exception& e) {
        cerr << e.what() << endl;
    }

    Product* brazil = new CoffeeBeans("Brazil Blend", 60, coffee_beans, "500g", "Medium",
        {"Brazil"}, {"Caramel", "Berries", "Citrus"});

    brazil->DisplayDetails();

    return 0;
}