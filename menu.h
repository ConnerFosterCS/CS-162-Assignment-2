#include "pizza.h"

class Menu {
    private:
        int num_pizzas;
        Pizza* pizzas;
    public:
        Menu();
        void set_num_pizzas(ifstream &menu);
        void set_num_pizzas(int num_p);
        int get_num_pizzas() const;
        //need to include accessor functions and mutator functions for each private member
        //need to include constructors, copy constructors, assignment operator overload,
        //and destructors where appropriate
        // Only one of the following two prototypes should be used:
        Menu search_pizza_by_cost(int upper_bound, string size);
        Menu search_ingredients_include(string* ingredients, int num_ingredients);
        Menu search_ingredients_exclude(string* ingredients, int num_ingredients);
        void add_to_menu(Pizza pizza_to_add);
        void remove_from_menu(int index_of_pizza_on_menu);
        Menu(const Menu&); //copy constructor
        const Menu& operator=(const Menu&); //assignment operator overload
        void print_menu();
        ~Menu();
};