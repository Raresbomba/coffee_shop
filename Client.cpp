#include "Client.hpp"
#include <iostream>
#include <string>

Client::Client(const string& name, const int id) {
    this->name = name;
    this->id = id;
    this->points = 0;
}

ostream& operator<<(ostream& os, const Client& client) {
    os << "Client ID: " << client.id << endl;
    os << "Name: " << client.name << endl;
    os << "Fidelity Points: " << client.points << endl;
    return os;
}