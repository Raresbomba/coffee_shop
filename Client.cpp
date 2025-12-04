#include "Client.hpp"
#include <iostream>
#include <string>

Client::Client(const string& name, const int id) {
    this->name = name;
    this->id = id;
    this->points = 0;
}

ostream& operator<<(ostream& os, const Client& client) {
    os << "Id Client: " << client.id << endl;
    os << "Nume Client: " << client.name << endl;
    os << "Puncte de fidelitate: " << client.points << endl;
    return os;
}