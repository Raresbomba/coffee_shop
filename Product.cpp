#include "Product.hpp"
#include <iostream>
#include <utility>

Product::Product(string  name, const float price, const Product_Type& type) : name(std::move(name)), price(price), type(type) {}

Product::Product(const Product& product) {
    this->name = product.name;
    this->price = product.price;
    this->type = product.type;
}

ostream& operator<<(ostream& os, const Product& product) {
    os << product.name << " " << product.price << " " << product.type;
    return os;
}

Drink::Drink(const string& name, const float price, const Product_Type& type, string  size, string  milkType,
const bool decaf, const bool extraShot) : Product(name, price, type), size(std::move(size)), milkType(std::move(milkType)),
decaf(decaf), extraShot(extraShot) {}

Product* Drink::clone() const {
    return new Drink(*this);
}

[[nodiscard]] float Drink::FinalPrice() const {
    float price = this->getProductPrice();
    if (this->size == "Mediu") price+=3;
    else if (this->size == "Mare") price+=6;
    if (this->milkType != "Normal" && this-> milkType != "None") {
        price+=3;
    }
    if (this->decaf == true) {
        price+=2;
    }
    if (this->extraShot == true) {
        price+=3;
    }
    return price;
}

Dessert::Dessert(const string& name, const float price, const Product_Type& type, const bool hasGluten, const bool hasLactose,
        const bool isVegan, const vector<string>& allergens, const bool isFrozen, const vector<string>& toppings)
        : Product(name, price, type), hasGluten(hasGluten), hasLactose(hasLactose), isVegan(isVegan), allergens(allergens),
        isFrozen(isFrozen), toppings(toppings) {}

Product* Dessert::clone() const {
    return new Dessert(*this);
}

void Dessert::DisplayAllAllergens() const {
    cout<<"Lista de alergeni: ";
    if (hasGluten) {
        cout<<"Gluten, ";
    }
    if (hasLactose) {
        cout<<"Lactoza, ";
    }
    for (const string& allergen : allergens) {
        cout<<allergen<<", ";
    }
    cout<<endl;
}

[[nodiscard]] float Dessert::FinalPrice() const {
    float price = getProductPrice();
    for (auto& topping : toppings) {
        if (topping == "None") {
            break;
        }
        price+=2;
    }
    return price;
}

Sandwich::Sandwich(const string& name, const float price, const Product_Type& type, const vector<string>& ingredients,
        const bool isVegan, const vector<string>& allergens, const bool isFrozen, const vector<string>& extraIngredients ) : Product(name, price, type),
        ingredients(ingredients), isVegan(isVegan), allergens(allergens), isFrozen(isFrozen), extraIngredients(extraIngredients) {}

Product* Sandwich::clone() const {
    return new Sandwich(*this);
}

void Sandwich::DisplayAllAllergens() const {
    cout<<"Lista de alergeni: ";
    for (const string& allergen : allergens) {
        cout<<allergen<<", ";
    }
    cout<<endl;
}

void Sandwich::AddIngredient(const string& ingredient) {
    ingredients.push_back(ingredient);
}

void Sandwich::DeleteIngredient(const string& ingredient) {
    for (const string& i : ingredients) {
        if (i == ingredient) {
            ingredients.erase(ingredients.begin());
        }
    }
}

[[nodiscard]] float Sandwich::FinalPrice() const {
    float price = this->getProductPrice();
    for (const string& ingredient : extraIngredients) {
        if (ingredient == "None") {
            break;
        }
        price+=2;
    }
    return price;
}