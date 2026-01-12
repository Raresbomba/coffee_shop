#ifndef OOP_CLIENT_HPP
#define OOP_CLIENT_HPP
#include <iostream>
#include <string>

using namespace std;

class Client {
    private:
    string name;
    int id{};
    int points{};

    public:

    Client() = default;

    Client(const string& name, const int id);

    ~Client() = default;

    Client& operator=(const Client& client) = default;

    void addPoints(const int addedPoints) {this->points += addedPoints;}

    friend ostream& operator<<(ostream& os, const Client& client);

};

#endif //OOP_CLIENT_HPP