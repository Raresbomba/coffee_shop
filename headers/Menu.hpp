//
// Created by zzrar on 1/12/2026.
//

#ifndef OOP_MENU_HPP
#define OOP_MENU_HPP


class Menu {
private:
    Menu();

public:

    Menu(const Menu&) = delete;
    Menu operator=(const Menu&) = delete;

    static Menu& getInstance();

    static void showDrinks() ;
    static void showDesserts();

};


#endif //OOP_MENU_HPP