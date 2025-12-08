#include "Product.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <utility>
#include <algorithm>

Product::Product(string  name, const float price, const Product_Type& type) : name(std::move(name)), price(price), type(type) {
    if (this->name.empty()) throw InvalidInputException("Nu a fost specificat numele produsului");
    if (this->price <= 0) throw InvalidInputException("Pretul produsului nu poate fi negativ");
}

Product::Product(const Product& product) {
    this->name = product.name;
    this->price = product.price;
    this->type = product.type;
}

ostream& operator<<(ostream& os, const Product& product) {
    os << product.name << " " << product.price << " " << product.type;
    return os;
}

void swap(Product& first, Product& second) noexcept {
    swap(first.name, second.name);
    swap(first.price, second.price);
    swap(first.type, second.type);
}

Drink::Drink(const string& name, const float price, const Product_Type& type, string  size, string  milkType,
const bool decaf, const bool extraShot) : Product(name, price, type), size(std::move(size)), milkType(std::move(milkType)),
decaf(decaf), extraShot(extraShot) {}

Product* Drink::clone() const {
    return new Drink(*this);
}

void swap(Drink& first, Drink& second) noexcept {
    using std::swap;
    swap(static_cast<Product&>(first), second);
    swap(first.size, second.size);
    swap(first.milkType, second.milkType);
    swap(first.decaf, second.decaf);
    swap(first.extraShot, second.extraShot);
}

Drink& Drink::operator=(const Drink& other) {
    Drink temp(other);
    swap(*this, temp);
    return *this;
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

void swap(Dessert& first, Dessert& second) noexcept {
    using std::swap;
    swap(static_cast<Product&>(first), second);
    swap(first.hasGluten, second.hasGluten);
    swap(first.hasLactose, second.hasLactose);
    swap(first.isVegan, second.isVegan);
    swap(first.allergens, second.allergens);
    swap(first.isFrozen, second.isFrozen);
    swap(first.toppings, second.toppings);
}

Dessert& Dessert::operator=(const Dessert& other) {
    Dessert temp(other);
    swap(*this, temp);
    return *this;
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

void swap(Sandwich& first, Sandwich& second) noexcept {
    using std::swap;
    swap(static_cast<Product&>(first), second);
    swap(first.ingredients, second.ingredients);
    swap(first.isVegan, second.isVegan);
    swap(first.allergens, second.allergens);
    swap(first.isFrozen, second.isFrozen);
    swap(first.extraIngredients, second.extraIngredients);
}

Sandwich& Sandwich::operator=(const Sandwich& other) {
    Sandwich temp(other);
    swap(*this, temp);
    return *this;
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

CoffeeBeans::CoffeeBeans(const string &name, const float price, const Product_Type &type, string size, string roastType,
    const vector<string> &origins, const vector<string> &blend)
    :Product(name, price, type), size(std::move(size)), roastType(std::move(roastType)), origins(origins), blend(blend){}

Product* CoffeeBeans::clone() const {
    return new CoffeeBeans(*this);
}

void swap(CoffeeBeans& first, CoffeeBeans& second) noexcept {
    using std::swap;
    swap(static_cast<Product&>(first), second);
    swap(first.size, second.size);
    swap(first.roastType, second.roastType);
    swap(first.origins, second.origins);
    swap(first.blend, second.blend);
}

CoffeeBeans& CoffeeBeans::operator=(const CoffeeBeans& other) {
    CoffeeBeans temp(other);
    swap(*this, temp);
    return *this;
}

[[nodiscard]] float CoffeeBeans::FinalPrice() const {
    float price = this->getProductPrice();
    if (size == "500g") price*=2;
    else if (size == "1kg") price*=3;
    return price;
}




