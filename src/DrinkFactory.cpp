#include "../headers/DrinkFactory.hpp"
#include "../headers/Exceptions.hpp"

std::unique_ptr<Product> DrinkFactory::createProduct(const std::string& name){

    if (name == "Espresso") {
        std::string decaf;
        cout << "Decaf?(y/n):";
        cin >> decaf;
        if (decaf == "y") {
            return std::make_unique<Drink>(name, 10, drink, "30ml", "None", 1, 0);
        }
        if (decaf == "n") {
            return std::make_unique<Drink>(name, 10, drink, "30ml", "None", 0, 0);
        }
        throw InvalidInputException("Invalid Input!: Decaf must be y/n");
    }

    if (name == "Doppio") {
        std::string decaf;
        cout << "Decaf?(y/n):";
        cin >> decaf;
        if (decaf == "y") {
            return std::make_unique<Drink>(name, 13, drink, "60ml", "None", 1, 0);
        }
        if (decaf == "n") {
            return std::make_unique<Drink>(name, 13, drink, "60ml", "None", 0, 0);
        }
        throw InvalidInputException("Invalid Input!: Decaf must be y/n");
    }

    if (name == "Americano") {
        std::string decaf;
        cout << "Decaf?(y/n):";
        cin >> decaf;
        if (decaf == "y") {
            return std::make_unique<Drink>(name,13, drink, "60ml", "None", 1, 0);
        }
        if (decaf == "n") {
            return std::make_unique<Drink>(name, 13, drink, "60ml", "None", 0, 0);
        }
        throw InvalidInputException("Invalid Input!: Decaf must be y/n");
    }

    if (name == "Long Black") {
        std::string decaf;
        cout << "Decaf?(y/n):";
        cin >> decaf;
        if (decaf == "y") {
            return std::make_unique<Drink>(name, 15, drink, "100ml", "None", 1, 0);
        }
        if (decaf == "n") {
            return std::make_unique<Drink>(name, 15, drink, "100ml", "None", 0, 0);
        }
        throw InvalidInputException("Invalid Input!: Decaf must be y/n");
    }

    if (name == "Flat White") {
        std::string decaf;
        std::string milkType;
        cout << "Decaf?(y/n):";
        cin >> decaf;
        cout << "Milk?(Whole, Oat, Soy):";
        cin >> milkType;
        if (milkType != "Whole" && milkType != "Oat" && milkType != "Soy") {
            throw InvalidInputException("Invalid Input!: Milk Type does not exist");
        }
        if (decaf == "y") {
            return std::make_unique<Drink>(name, 15, drink, "180ml", milkType, 1, 0);
        }
        if (decaf == "n") {
            return std::make_unique<Drink>(name, 15, drink, "180ml", milkType, 0, 0);
        }
        throw InvalidInputException("Invalid Input!: Decaf must be y/n");
    }

    if (name == "Cappuccino") {
        std::string decaf;
        std::string milkType;
        cout << "Decaf?(y/n):";
        cin >> decaf;
        cout << "Milk?(Whole, Oat, Soy):";
        cin >> milkType;
        if (milkType != "Whole" && milkType != "Oat" && milkType != "Soy") {
            throw InvalidInputException("Invalid Input!: Milk Type does not exist");
        }
        if (decaf == "y") {
            return std::make_unique<Drink>(name, 17, drink, "200ml", milkType, 1, 0);
        }
        if (decaf == "n") {
            return std::make_unique<Drink>(name, 17, drink, "200ml", milkType, 0, 0);
        }
        throw InvalidInputException("Invalid Input!: Decaf must be y/n");
    }

    if (name == "Latte") {
        std::string decaf;
        std::string milkType;
        cout << "Decaf?(y/n):";
        cin >> decaf;
        cout << "Milk?(Whole, Oat, Soy):";
        cin >> milkType;
        if (milkType != "Whole" && milkType != "Oat" && milkType != "Soy") {
            throw InvalidInputException("Invalid Input!: Milk Type does not exist");
        }
        if (decaf == "y") {
            return std::make_unique<Drink>(name, 18, drink, "220ml", milkType, 1, 0);
        }
        if (decaf == "n") {
            return std::make_unique<Drink>(name, 18, drink, "220ml", milkType, 0, 0);
        }
        throw InvalidInputException("Invalid Input!: Decaf must be y/n");
    }

    if (name == "Macchiato") {
        std::string decaf;
        std::string milkType;
        cout << "Decaf?(y/n):";
        cin >> decaf;
        cout << "Milk?(Whole, Oat, Soy):";
        cin >> milkType;
        if (milkType != "Whole" && milkType != "Oat" && milkType != "Soy") {
            throw InvalidInputException("Invalid Input!: Milk Type does not exist");
        }
        if (decaf == "y") {
            return std::make_unique<Drink>(name, 13, drink, "60ml", milkType, 1, 0);
        }
        if (decaf == "n") {
            return std::make_unique<Drink>(name, 13, drink, "60ml", milkType, 0, 0);
        }
        throw InvalidInputException("Invalid Input!: Decaf must be y/n");
    }

    if (name == "Cortado") {
        std::string decaf;
        std::string milkType;
        cout << "Decaf?(y/n):";
        cin >> decaf;
        cout << "Milk?(Whole, Oat, Soy):";
        cin >> milkType;
        if (milkType != "Whole" && milkType != "Oat" && milkType != "Soy") {
            throw InvalidInputException("Invalid Input!: Milk Type does not exist");
        }
        if (decaf == "y") {
            return std::make_unique<Drink>(name, 13, drink, "60ml", milkType, 1, 0);
        }
        if (decaf == "n") {
            return std::make_unique<Drink>(name, 13, drink, "60ml", milkType, 0, 0);
        }
        throw InvalidInputException("Invalid Input!: Decaf must be y/n");
    }

    if (name == "V60") {
        std::string decaf;
        cout << "Decaf?(y/n):";
        cin >> decaf;
        if (decaf == "y") {
            return std::make_unique<Drink>(name, 20, drink, "300ml", "None", 1, 0);
        }
        if (decaf == "n") {
            return std::make_unique<Drink>(name, 20, drink, "300ml", "None", 0, 0);
        }
        throw InvalidInputException("Invalid Input!: Decaf must be y/n");
    }

    throw InvalidInputException("Invalid Input!: Product does not exist in the menu");
}