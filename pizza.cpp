#include "pizza.h"

//pizza constructor
Pizza::Pizza() {
    //cout << "Pizza Constructor Called" << endl;
    this -> name = "-default_string-";
    this -> small_cost = 0;
    this -> medium_cost = 0;
    this -> large_cost = 0;
    this -> num_ingredients = 0;
    this -> ingredients = NULL;
}

/*
void Pizza::load_pizza_data(ifstream &menu_f) {
    menu_f.open("menu.txt");
    string s;

    Pizza* pizzas = new Pizza[6];

    for (int i = 0; i < 6; i++) {
        getline(menu_f, s);
        pizzas[i] = s;
    }
    
    menu_f.close();
}*/

/*********************************************************************
** Function: set_name
** Description: This function sets the class variables
*********************************************************************/ 
void Pizza::set_name(string n) {
    this -> name = n;
}

/*********************************************************************
** Function: get_name
** Description: This function returns the set value from the class
*********************************************************************/ 
string Pizza::get_name() const{
    return name;
}

/*********************************************************************
** Function: set_num_ingredients
** Description: This function sets the class variables
*********************************************************************/ 
void Pizza::set_num_ingredients(int num_ingr) {
    this -> num_ingredients = num_ingr;
}

/*********************************************************************
** Function: get_num_ingredients
** Description: This function returns the set value from the class
*********************************************************************/
int Pizza::get_num_ingredients() const{
    return num_ingredients;
}

/*********************************************************************
** Function: set_from_file
** Description: This function sets the set value from the class
*********************************************************************/
void Pizza::set_from_file(ifstream &menu_f) {
    string name;
    for (int i = 0; i < 6; i++) {
        menu_f >> this -> name;
    }
}
/*********************************************************************
** Function: get_from_file
** Description: This function returns the set value from the class
*********************************************************************/
string Pizza::get_from_file() {
    return name;
}

/*********************************************************************
** Function: set_small_cost
** Description: This function sets the class variables
*********************************************************************/
void Pizza::set_small_cost(int smll_cst) {
    this -> small_cost = smll_cst;
}

/*********************************************************************
** Function: get_small_cost
** Description: This function returns the set value from the class
*********************************************************************/
int Pizza::get_small_cost() const{
    return small_cost;
}

/*********************************************************************
** Function: set_medium_cost
** Description: This function sets the class variables
*********************************************************************/
void Pizza::set_medium_cost(int med_cst) {
    this -> medium_cost = med_cst;
}

/*********************************************************************
** Function: get_medium_cost
** Description: This function returns the set value from the class
*********************************************************************/
int Pizza::get_medium_cost() const{
    return medium_cost;
}

/*********************************************************************
** Function: set_large_cost
** Description: This function sets the class variables
*********************************************************************/
void Pizza::set_large_cost(int lrg_cst) {
    this -> large_cost = lrg_cst;
}

/*********************************************************************
** Function: get_large_cost
** Description: This function returns the set value from the class
*********************************************************************/
int Pizza::get_large_cost() const{
    return large_cost;
}

//copy constructor
Pizza::Pizza(const Pizza& other) {
    //cout << "Pizza Copy Constuctor Called" << endl;
    
    name = other.name;
    small_cost = other.small_cost;
    medium_cost = other.medium_cost;
    large_cost = other.large_cost;
    num_ingredients = other.num_ingredients;
    ingredients = new string[num_ingredients];

    for(int i = 0; i < num_ingredients; i++) {
        ingredients[i] = other.ingredients[i];
    }
}

//assignment operator overload
const Pizza& Pizza::operator=(const Pizza& other) {
    //cout << "Pizza Assignment Operator Invoked" << endl;
    
    delete[] ingredients;
    ingredients = NULL;
    cout << "test1" << endl;
    this -> name = other.name;
    cout << "kek" <<endl;
    this -> small_cost = other.small_cost;
    this -> medium_cost = other.medium_cost;
    this -> large_cost = other.large_cost;
    this -> num_ingredients = other.num_ingredients;
    cout << "test2" << endl;
    ingredients = new string[num_ingredients];
    cout << "test3" << endl;

    
    for(int i = 0; i < num_ingredients; i++) {
        ingredients[i] = other.ingredients[i];
    }
}

/*********************************************************************
** Function: print_pizza
** Description: This function prints the current values of the pizza class.
*********************************************************************/
void Pizza::print_pizza() {
    cout << this -> name << endl;
    cout << this -> small_cost << endl;
    cout << this -> medium_cost << endl;
    cout << this -> large_cost << endl;
    cout << this -> num_ingredients << endl;
    cout << this -> ingredients << endl;
}

//pizza destructor
Pizza::~Pizza() {
    //cout << "Pizza Destuctor Called" << endl;
    delete[] ingredients;
    ingredients = NULL;
}