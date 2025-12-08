#include <iostream>
#include <vector>
#include "Product.hpp"
#include "Client.hpp"
#include "Order.hpp"

using namespace std;

int main() {

    Product* espresso = new Drink("Espresso", 10, drink, "Small", "None", false, false);
    Product* pie = new Dessert("Felie de placinta", 15, dessert, true, true, false,
        {"Lactoza", "Gluten"}, false, {"Frisca"});
    Product* prosciutto = new Sandwich("Sandwich Prosciutto", 15, sandwich, {"Focaccia", "Prosciutto", "Mozzarella", "Rosii"},
        false, {"Lactoza", "Gluten"}, false, {"Rucola", "Pesto"});

    espresso->DisplayDetails();
    pie->DisplayDetails();
    prosciutto->DisplayDetails();

    return 0;
}