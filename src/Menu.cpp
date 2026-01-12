//
// Created by zzrar on 1/12/2026.
//

#include "../headers/Menu.hpp"

#include <iostream>
#include <ostream>

Menu::Menu(){}

Menu &Menu::getInstance() {
    static Menu instance;
    return instance;
}

void Menu::showDrinks() {
    std::cout << "DRINK MENU:" << std::endl;
    std::cout << "1. Espresso     30ml    10 Ron" << std::endl;
    std::cout << "2. Doppio       60ml    13 Ron" << std::endl;
    std::cout << "3. Americano    60ml    13 Ron" << std::endl;
    std::cout << "4. Long Black   100ml   10 Ron" << std::endl;
    std::cout << "5. Flat White   180ml   16 Ron" << std::endl;
    std::cout << "6. Cappuccino   200ml   17 Ron" << std::endl;
    std::cout << "7. Latte        220ml   18 Ron" << std::endl;
    std::cout << "8. Macchiato    60ml    13 Ron" << std::endl;
    std::cout << "9. Cortado      100ml   15 Ron" << std::endl;
    std::cout << "10. V60         300ml   20 Ron" << std::endl;
    std::cout << std::endl;
}

void Menu::showDesserts(){
    std::cout << "DESSERT MENU:" << std::endl;
    std::cout << "1. Cinnamon Roll 100g   7 Ron" << std::endl;
    std::cout << "2. Pie Slice     150g   8 Ron" << std::endl;
    std::cout << "3. Pancakes      220g   15 Ron" << std::endl;
    std::cout << "4. Cookie        90g    8 Ron" << std::endl;
}





