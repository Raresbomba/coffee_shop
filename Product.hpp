#ifndef OOP_PRODUCT_HPP
#define OOP_PRODUCT_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Product_Type {
    drink,
    dessert,
    sandwich
};

class Product {
    private:
    string name;
    float price{};
    Product_Type type{};

    public:

    Product() = default;

    Product(const string& name, const float price, const Product_Type& type);

    Product(const Product& product);

    ~Product() = default;

    [[nodiscard]] const string& getProductName() const{return this->name;}

    [[nodiscard]] float getProductPrice() const{return this->price;}

    [[nodiscard]] Product_Type getProductType() const{return this->type;}

    void setProductName(const string& setterName){this->name = setterName;}

    void setProductPrice(float setterPrice){this->price = setterPrice;}

    void setProductType(const Product_Type& setterType){this->type = setterType;}

    Product& operator=(const Product& product) = default;

    friend ostream& operator<<(ostream& os, const Product& product);

};

class Drink : public Product {
    private:
    string size;
    string milkType;
    bool decaf{};
    bool extraShot{};

    public:

    Drink() = default;

    Drink(const string& name, const float price, const Product_Type& type, string  size, string  milkType,
        const bool decaf, const bool extraShot);

    ~Drink() = default;

    [[nodiscard]] float FinalPrice() const;

};

class Dessert : public Product {
    private:
    bool hasGluten{};
    bool hasLactose{};
    bool isVegan{};
    vector<string> allergens;
    bool isFrozen{};

    public:
    Dessert() = default;

    Dessert(const string& name, const float price, const Product_Type& type, const bool hasGluten, const bool hasLactose,
        const bool isVegan, const vector<string>& allergens, const bool isFrozen);

    ~Dessert() = default;

    void DisplayAllAllergens() const;

    [[nodiscard]] bool getIsVegan() const{return this->isVegan;}

    [[nodiscard]] bool getIsFrozen() const{return this->isFrozen;}
};

class Sandwich : public Product {
    private:
    vector<string> ingredients;
    bool isVegan{};
    vector<string> allergens;
    bool isFrozen{};

    public:

    Sandwich() = default;

    Sandwich(const string& name, const float price, const Product_Type& type, const vector<string>& ingredients,
        const bool isVegan, const vector<string>& allergens, const bool isFrozen);

    ~Sandwich() = default;

    void DisplayAllAllergens() const;

    [[nodiscard]] bool getIsVegan() const{return this->isVegan;}

    [[nodiscard]] bool getIsFrozen() const{return this->isFrozen;}

    void AddIngredient(const string& ingredient);

    void DeleteIngredient(const string& ingredient);
};

#endif //OOP_PRODUCT_HPP