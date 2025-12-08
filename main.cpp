#include <iostream>
#include <vector>
#include "Product.hpp"
#include "Client.hpp"
#include "Order.hpp"
#include "Exceptions.hpp"

using namespace std;

int main() {

    /*Product* espresso = new Drink("Espresso", 10, drink, "Small", "None", false, false);
    Product* pie = new Dessert("Felie de placinta", 15, dessert, true, true, false,
        {"Lactoza", "Gluten"}, false, {"Frisca"});
    Product* prosciutto = new Sandwich("Sandwich Prosciutto", 15, sandwich, {"Focaccia", "Prosciutto", "Mozzarella", "Rosii"},
        false, {"Lactoza", "Gluten"}, false, {"Rucola", "Pesto"});
    Product* prosciutto2 = prosciutto;

    espresso->DisplayDetails();
    pie->DisplayDetails();
    prosciutto->DisplayDetails();
    prosciutto2->DisplayDetails();*/

    /*try {
        Product* invalid = new Drink("Espresso", 5, drink, "Mic", "None", false, false);
        invalid->DisplayDetails();
    }

    catch (exception& e) {
        cerr << e.what() << endl;
    }*/

    Product* brazil = new CoffeeBeans("Brazil Blend", 60, coffee_beans, "500g", "Mediu",
        {"Brazilia"}, {"Caramel", "Zmeura", "Trandafir"});

    brazil->DisplayDetails();

    return 0;
}