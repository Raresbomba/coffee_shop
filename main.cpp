#include <iostream>
#include <ctime>
#include <utility>
#include <vector>

using namespace std;

enum Product_Type {
    drink,
    dessert,
    sandwich
};

class Product {
    string name;
    float price{};
    Product_Type type{};

    public:

        Product() = default;

        Product(const string& name, const float price, const Product_Type& type) {
            this->name = name;
            this->price = price;
            this->type = type;
        }

        [[nodiscard]] const string& getProductName() const {
            return this->name;
        }

        [[nodiscard]] float getProductPrice() const {
            return this->price;
        }

        [[nodiscard]] Product_Type getProductType() const {
            return this->type;
        }

        void setProductName(const string& setterName) {
            this->name = setterName;
        }

        void setProductPrice(const float setterPrice) {
            this->price = setterPrice;
        }

        void setProductType(const Product_Type& setterType) {
            this->type = setterType;
        }

        Product(const Product& product) {
            this->name = product.name;
            this->price = product.price;
            this->type = product.type;
        }

        Product& operator=(const Product& product) = default;

        friend ostream& operator<<(ostream& os, const Product& product) {
            os << product.name << " " << product.price << " " << product.type;
            return os;
        }

        ~Product() = default;

};

class Drink : public Product {
    string size;
    string milkType;
    bool decaf{};
    bool extraShot{};

    public:

    Drink() = default;

    Drink(const string& name, const float price, const Product_Type& type, string  size, string  milkType,
        const bool decaf): Product(name, price, type), size(std::move(size)), milkType(std::move(milkType)),
        decaf(decaf) {
    }

    ~Drink() = default;

    [[nodiscard]] float FinalPrice() const {
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
};

class Dessert : public Product {
    bool hasGluten{};
    bool hasLactose{};
    bool isVegan{};
    vector<string> allergens;
    bool isFrozen{};

    public:

    Dessert() = default;

    Dessert(const string& name, const float price, const Product_Type& type, const bool hasGluten, const bool hasLactose,
        const bool isVegan, const vector<string>& allergens, const bool isFrozen)
        : Product(name, price, type), hasGluten(hasGluten), hasLactose(hasLactose), isVegan(isVegan), allergens(allergens),
        isFrozen(isFrozen) {}

    ~Dessert() = default;

    void DisplayAllAllergens() const {
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

    [[nodiscard]] bool getIsVegan() const {
        return isVegan;
    }

    [[nodiscard]] bool getIsFrozen() const {
        return isFrozen;
    }
};

class Sandwich : public Product {
    vector<string> ingredients;
    bool isVegan{};
    vector<string> allergens;
    bool isFrozen{};

    public:

    Sandwich() = default;

    Sandwich(const string& name, const float price, const Product_Type& type, const vector<string>& ingredients,
        const bool isVegan, const vector<string>& allergens, const bool isFrozen ) : Product(name, price, type),
        ingredients(ingredients), isVegan(isVegan), allergens(allergens), isFrozen(isFrozen) {
    }

    ~Sandwich() = default;

    void DisplayAllAllergens() const {
        cout<<"Lista de alergeni: ";
        for (const string& allergen : allergens) {
            cout<<allergen<<", ";
        }
        cout<<endl;
    }

    [[nodiscard]] bool getIsVegan() const {
        return isVegan;
    }

    [[nodiscard]] bool getIsFrozen() const {
        return isFrozen;
    }

    void AddIngredient(const string& ingredient) {
        ingredients.push_back(ingredient);
    }

    void DeleteIngredient(const string& ingredient) {
        for (const string& i : ingredients) {
            if (i == ingredient) {
                ingredients.erase(ingredients.begin());
            }
        }
    }
};

class Client {
    string name;
    int id{};
    int points{};
    public:

    Client() = default;

    Client(const string& name, const int id) {
        this->name = name;
        this->id = id;
        this->points = 0;
    }

    Client& operator=(const Client& client) = default;

    void addPoints(const int addedPoints) {
        this->points += addedPoints;
    }

    friend ostream& operator<<(ostream& os, const Client& client) {
        os << "Id Client: " << client.id << endl;
        os << "Nume Client: " << client.name << endl;
        os << "Puncte de fidelitate: " << client.points << endl;
        return os;
    }

    ~Client() = default;
};

class Order {
    int id{};
    vector<Product> products;
    string date;
    float price{};
    Client client;

public:

    static string getDateTime() {
        time_t timestamp;
        time(&timestamp);
        return { (ctime(&timestamp)) };
    }

    Order() = default;

    Order(const int id, const vector<Product>& products, const Client& client){
        this->id = id;
        this->date = getDateTime();
        this->products = products;
        this->client = client;
        for (auto &product: products) {
            this->price += product.getProductPrice();
        }
    }

    void addProductInOrder(const Product& product) {
        this->products.push_back(product);
        this->price += product.getProductPrice();
    }

    friend ostream& operator<<(ostream& os, const Order& order) {
        os << "Id Comanda: " << order.id << endl;
        os << "Produse: " << endl;
        for (const Product& product : order.products) {
            os << product.getProductName() << ' ' << product.getProductPrice() << endl;
        }
        os << "Total: " << order.price << endl;
        os << "Comanda plasata la " << order.date;
        return os;
    }

    ~Order() = default;

};



int main() {

    const Product p1("Espresso", 10, drink);
    Product p2;
    p2.setProductName("Cappuccino");
    p2.setProductPrice(12);
    p2.setProductType(drink);
    cout << p1 << endl << p2.getProductName() << ' ' << p2.getProductPrice() << ' ' << p2.getProductType() << endl;
    const Product& p3 = p1;
    cout << p3 << endl;
    cout << endl;

    Client c1("Razvan", 243);
    c1.addPoints(15);
    cout << c1 << endl;

    vector<Product> products;
    products.push_back(p1);
    Order o1(554,products,c1);
    cout << o1 << endl;
    o1.addProductInOrder(p2);
    cout << o1 << endl;



    return 0;
}