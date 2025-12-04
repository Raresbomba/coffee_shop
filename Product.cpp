#include "Product.hpp"
#include <iostream>

Product::Product(const string& name, const float price, const Product_Type& type) : name(name), price(price), type(type) {}

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

[[nodiscard]] float Drink::FinalPrice() const {
    float price = this->getProductPrice();
    if (this->size == "Medium") price+=3;
    else if (this->size == "Large") price+=6;
    if (this->milkType != "Whole" || this-> milkType != "None") {
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
        const bool isVegan, const vector<string>& allergens, const bool isFrozen)
        : Product(name, price, type), hasGluten(hasGluten), hasLactose(hasLactose), isVegan(isVegan), allergens(allergens),
        isFrozen(isFrozen) {}

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

Sandwich::Sandwich(const string& name, const float price, const Product_Type& type, const vector<string>& ingredients,
        const bool isVegan, const vector<string>& allergens, const bool isFrozen ) : Product(name, price, type),
        ingredients(ingredients), isVegan(isVegan), allergens(allergens), isFrozen(isFrozen) {}

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