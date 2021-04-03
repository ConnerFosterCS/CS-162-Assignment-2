#include "menu.h"

//menu constructor
Menu::Menu() {
    //cout << "Menu Constructor Called" << endl;
    this -> num_pizzas = 0;
    this -> pizzas = NULL;
}

/*********************************************************************
** Function: set_num_pizzas
** Description: This function reads the ammount of lines in the menu file to count the ammount of pizzas within the menu.
** Parameters: ifstream &menu_f
** Pre-Conditions: menu.txt opened by ifstream.
** Post-Conditions: number of pizzas in class is correct.
*********************************************************************/ 
void Menu::set_num_pizzas(ifstream &menu_f) {
    menu_f.open("menu.txt");
    
    string s;
    
    while (!menu_f.eof()) {
        getline(menu_f, s);
        num_pizzas ++;
    }
    menu_f.close(); 
}

/*********************************************************************
** Function: get_Pizzas
** Description: This function returns the set value from the class
*********************************************************************/ 
int Menu::get_num_pizzas() const{
    return num_pizzas;
}

/*********************************************************************
** Function: search_cost
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
Menu search_cost(int upper_bound, string size) {

}

/*********************************************************************
** Function: search_to_include
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
Menu search_to_include(string* ingredients, int num_ingredients) {

}

/*********************************************************************
** Function: search_to_exclude
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
Menu search_to_exclude(string* ingredients, int num_ingredients) {

}

/*********************************************************************
** Function: add_to_menu
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Menu::add_to_menu(Pizza pizza_to_add) {

}

/*********************************************************************
** Function: remove_from_menu
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Menu::remove_from_menu(int index_of_pizza_on_menu) {

}

//copy constructor
Menu::Menu(const Menu& other) {
    //cout << "Menu Copy Constructor Called" << endl;

    num_pizzas = other.num_pizzas;
    pizzas = new Pizza[num_pizzas];

    for(int i = 0; i < num_pizzas; i++) {
        pizzas[i] = other.pizzas[i];
    }
}

//assignment operator overload
const Menu& Menu::operator=(const Menu& other) {
    //cout << "Menu Assignment Operator Invoked" << endl;
    delete[] pizzas;
    pizzas = NULL;

    this -> num_pizzas = other.num_pizzas;
    pizzas = new Pizza[num_pizzas];

    for(int i = 0; i < num_pizzas; i++) {
        pizzas[i] = other.pizzas[i];
    }
}

void Menu::print_menu() {
    cout << this -> num_pizzas << endl;
    //cout << this -> pizzas << endl;
}

//menu destructor
Menu::~Menu() {
    //cout << "Menu Destructor Called" << endl;
    delete[] pizzas;
    pizzas = NULL;
}