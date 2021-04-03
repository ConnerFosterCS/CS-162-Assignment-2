/**********************************************************************
 ** Program: assignment2.cpp (Pizza Portal)
 ** Author: Conner Foster
 ** Date: 04/25/2019
 ** Decription: Creating a pizza portal with customer and employee functions for odering and making pizzas.
 ** Ouput: Pizza orders and store information.
 *********************************************************************/
#include "resturant.h"

int main() {
    int id;
    string password;

    ifstream restaurant_info, employee_f, menu_f, orders;
    ofstream fout;

    Menu m;
    m.set_num_pizzas(menu_f);

    Restaurant r;
    r.number_employees(employee_f);
    r.number_orders(orders);
    r.load_data(employee_f, restaurant_info);
    r.uiselection();
}