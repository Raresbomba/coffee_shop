#include "../headers/DessertFactory.hpp"
#include "../headers/Exceptions.hpp"

std::unique_ptr<Product> DessertFactory::createProduct(const std::string& name) {
    if (name == "Cinnamon Roll") {
        return std::make_unique<Dessert>(name, 7, dessert, true, true, false,
        std::vector<std::string>{"Lactose", "Gluten", "Nuts"}, true, std::vector<std::string>{"None"});
    }

    if (name == "Pie Slice") {
        string topping;
        cout << "Cream?(y/n):";
        cin >> topping;
        if (topping == "y") {
            std::vector<std::string> toppings;
            toppings.emplace_back("Cream");
            return std::make_unique<Dessert>(name, 8, dessert, true, true, false,
                std::vector<std::string>{"Lactose", "Gluten"}, false, toppings);
        }
        if (topping == "n") {
            return std::make_unique<Dessert>(name, 8, dessert, true, true, false,
                std::vector<std::string>{"Lactose", "Gluten"}, false, std::vector<std::string>{"None"});
        }
        throw InvalidInputException("Invalid Input: Cream must be y/n");
    }

    if (name == "Pancakes") {
        std::vector<std::string> toppings;
        string topping;
        cout << "Cream?(y/n):";
        cin >> topping;
        if (topping == "y") {
            toppings.emplace_back("Cream");
        }
        else if (topping != "n") {
            throw InvalidInputException("Invalid Input: Cream must be y/n");
        }
        cout << "Chocolate?(y/n):";
        cin >> topping;
        if (topping == "y") {
            toppings.emplace_back("Chocolate");
        }
        else if (topping != "n") {
            throw InvalidInputException("Invalid Input: Chocolate must be y/n");
        }
        cout << "Bananas?(y/n):";
        cin >> topping;
        if (topping == "y") {
            toppings.emplace_back("Bananas");
        }
        else if (topping != "n") {
            throw InvalidInputException("Invalid Input: Bananas must be y/n");
        }
        cout << "Strawberries?(y/n):";
        cin >> topping;
        if (topping == "y") {
            toppings.emplace_back("Strawberries");
        }
        else if (topping != "n") {
            throw InvalidInputException("Invalid Input: Strawberries must be y/n");
        }
        if (toppings.empty()) {
            return std::make_unique<Dessert>(name, 15, dessert, true, true, false,
                std::vector<std::string>{"Lactose", "Gluten"}, false, std::vector<std::string>{"None"});
        }
        return std::make_unique<Dessert>(name, 15, dessert, true, true, false,
                std::vector<std::string>{"Lactose", "Gluten"}, false, toppings);

    }

    if (name == "Cookie") {
        std::string gluten, lactose, vegan;
        bool glu, lac, veg;
        cout << "Gluten-Free?(y/n):";
        cin >> gluten;
        if (gluten == "y") {
            glu=false;
        }
        if (gluten == "n") {
            glu=true;
        }
        else {
            throw InvalidInputException("Invalid Input: Gluten-Free must be y/n");
        }
        cout << "Lactose-Free?(y/n):";
        cin >> lactose;
        if (lactose == "y") {
            lac=false;
        }
        if (lactose == "n") {
            lac=true;
        }
        else {
            throw InvalidInputException("Invalid Input: Lactose-Free must be y/n");
        }
        cout << "Vegan?(y/n):";
        cin >> vegan;
        if (vegan == "y") {
            veg=false;
        }
        if (vegan == "n") {
            veg=true;
        }
        else {
            throw InvalidInputException("Invalid Input: Vegan must be y/n");
        }
        return std::make_unique<Dessert>(name, 8, dessert, glu, lac, veg,
                std::vector<std::string>{"Lactose", "Gluten"}, false, std::vector<std::string>{"None"});
    }
    throw InvalidInputException("Invalid Input: Product does not exist in the menu");
}