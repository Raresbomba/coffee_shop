#ifndef OOP_PRODUCT_HPP
#define OOP_PRODUCT_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Product_Type {
    drink,
    dessert,
    sandwich,
    coffee_beans
};

class Product {
    private:
    string name;
    float price{};
    Product_Type type{};

    public:

    Product() = default;

    Product(string  name, float price, const Product_Type& type);

    Product(const Product& product);

    virtual ~Product() = default;

    [[nodiscard]] virtual Product* clone() const = 0;

    [[nodiscard]] const string& getProductName() const{return this->name;}

    [[nodiscard]] float getProductPrice() const{return this->price;}

    [[nodiscard]] Product_Type getProductType() const{return this->type;}

    void setProductName(const string& setterName){this->name = setterName;}

    void setProductPrice(float setterPrice){this->price = setterPrice;}

    void setProductType(const Product_Type& setterType){this->type = setterType;}

    Product& operator=(const Product& product) = default;

    friend ostream& operator<<(ostream& os, const Product& product);

    friend void swap(Product& first, Product& second) noexcept;

    [[nodiscard]] virtual float FinalPrice() const = 0;

    void DisplayDetails() {
        cout << "--- Detalii Produs: " << this->getProductName() << " ---" << endl;
        cout << "Nume: " << this->getProductName() << endl;
        cout << "Pret de baza: " << this->getProductPrice() << "Ron" << endl;
        this->DisplaySpecifics();
        cout << "Pret final: " << this->FinalPrice() << endl;
        cout << "--------------------------------------" << endl;
    }

private:
    virtual void DisplaySpecifics() = 0;

};

class Drink final : public Product {
    private:
    string size;
    string milkType;
    bool decaf{};
    bool extraShot{};

    public:

    Drink() = default;

    Drink(const string& name, float price, const Product_Type& type, string  size, string  milkType,
        bool decaf, bool extraShot);

    Drink(const Drink& other) = default;

    Drink& operator=(const Drink& other);

    friend void swap(Drink& first, Drink& second) noexcept;

    [[nodiscard]] bool getExtraShot() const {return this->extraShot;}

    [[nodiscard]] Product* clone() const override;

    [[nodiscard]] float FinalPrice() const override;


private:
    void DisplaySpecifics() override {
        cout << "Tip: Bautura" << endl;
        cout << "Dimensiune: " << this->size << endl;
        cout << "Lapte: " << this->milkType << endl;
        cout << "Decafeinizata: ";
        if (this->decaf) {
            cout << "Da" << endl;
        }
        else cout << "Nu" << endl;
        cout << "Extra Shot: ";
        if (this->extraShot) {
            cout << "Da" <<endl;
        }
        else cout << "Nu" << endl;
    }

};

class Dessert final : public Product {
    private:
    bool hasGluten{};
    bool hasLactose{};
    bool isVegan{};
    vector<string> allergens;
    bool isFrozen{};
    vector<string> toppings;

    public:
    Dessert() = default;

    Dessert(const string& name, float price, const Product_Type& type, bool hasGluten, bool hasLactose,
        bool isVegan, const vector<string>& allergens, bool isFrozen, const vector<string>& toppings);

    [[nodiscard]] Product* clone() const override;

    void DisplayAllAllergens() const;

    Dessert(const Dessert& other) = default;

    Dessert& operator=(const Dessert& other);

    friend void swap(Dessert& first, Dessert& second) noexcept;

    [[nodiscard]] bool getIsVegan() const{return this->isVegan;}

    [[nodiscard]] bool getIsFrozen() const{return this->isFrozen;}

    [[nodiscard]] float FinalPrice() const override;

    private:

    void DisplaySpecifics() override {
        cout << "Tip: Desert" << endl;
        cout << "Gluten: ";
        if (this->hasGluten) cout << "Da" << endl;
        else cout << "Nu" << endl;
        cout << "Lactoza: ";
        if (this->hasLactose) cout << "Da" << endl;
        else cout << "Nu" << endl;
        cout << "Vegan: ";
        if (this->isVegan) cout << "Da" << endl;
        else cout << "Nu" << endl;
        cout << "Alergeni: ";
        for (string& allergen : allergens) {
            cout << allergen << " ";
        }
        cout << endl;
        cout << "Congelat: ";
        if (this->isFrozen) cout << "Da" << endl;
        else cout << "Nu" << endl;
        cout << "Topping-uri: ";
        for (string& topping : toppings) {
            cout << topping << " ";
        }
        cout << endl;
    }
};

class Sandwich final : public Product {
    vector<string> ingredients;
    bool isVegan{};
    vector<string> allergens;
    bool isFrozen{};
    vector<string> extraIngredients;

    public:

    Sandwich() = default;

    Sandwich(const string& name, float price, const Product_Type& type, const vector<string>& ingredients,
    bool isVegan, const vector<string>& allergens, bool isFrozen, const vector<string>& extraIngredients);

    [[nodiscard]] Product* clone() const override;

    void DisplayAllAllergens() const;

    [[nodiscard]] bool getIsVegan() const{return this->isVegan;}

    [[nodiscard]] bool getIsFrozen() const{return this->isFrozen;}

    void AddIngredient(const string& ingredient);

    void DeleteIngredient(const string& ingredient);

    Sandwich(const Sandwich& other) = default;

    Sandwich& operator=(const Sandwich& other);

    friend void swap(Sandwich& first, Sandwich& second) noexcept;

    [[nodiscard]] float FinalPrice() const override;

    private:
    void DisplaySpecifics() override {
        cout << "Tip: Sandwich" << endl;
        cout << "Ingrediente: ";
        for (string& ingredient : ingredients) {
            cout << ingredient << " ";
        }
        cout << endl;
        cout << "Vegan: ";
        if (this->isVegan) cout << "Da" << endl;
        else cout << "Nu" << endl;
        cout << "Alergeni: ";
        for (string& allergen : allergens) {
            cout << allergen << " ";
        }
        cout << endl;
        cout << "Congelat: ";
        if (this->isFrozen) cout << "Da" << endl;
        else cout << "Nu" << endl;
        cout << "Ingrediente extra: ";
        for (string& ingredient : extraIngredients) {
            cout << ingredient << " ";
        }
        cout << endl;
    }

};

class CoffeeBeans final : public Product {
    string size;
    string roastType;
    vector<string> origins;
    vector<string> blend;

    public:
    CoffeeBeans() = default;

    CoffeeBeans(const string& name, float price, const Product_Type& type, string size, string roastType, const vector<string>& origins, const vector<string>& blend);

    [[nodiscard]] Product* clone() const override;

    CoffeeBeans(const CoffeeBeans& other) = default;

    CoffeeBeans& operator=(const CoffeeBeans& other);

    friend void swap(CoffeeBeans& first, CoffeeBeans& second) noexcept;

    [[nodiscard]] float FinalPrice() const override;

private:
    void DisplaySpecifics() override {
        cout << "Tip: Cafea Boabe" << endl;
        cout << "Marime: " << this->size << endl;
        cout << "Gradul de prajire: " << this->roastType << endl;
        cout << "Origini: ";
        for (string& origin : origins) {
            cout << origin << ", ";
        }
        cout << endl;
        cout << "Note: ";
        for (string& bl : blend) {
            cout << bl << ", ";
        }
        cout << endl;
    }
};

#endif //OOP_PRODUCT_HPP