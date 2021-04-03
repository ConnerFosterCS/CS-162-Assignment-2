#include "menu.h"

class Restaurant {
    private:
        Menu menu;
        employee* employees;
        hours* week;
        string name;
        string phone;
        string address;
        int num_employees;
        int num_orders;
    public:
        Restaurant();
        void number_employees(ifstream &employee_f);
        void number_orders(ifstream &orders);
        void set_name(string);
        string get_name() const;
        void set_phone(string);
        string get_phone() const;
        void set_address(string);
        string get_address() const;
        //need to include accessor functions and mutator functions for each private member
        //need to include constructors, copy constructors, assignment operator overload,
        //and destructors where appropriate
        void load_data(ifstream &employee, ifstream &restaurant_info); //reads from files to correctly populate menu, employees, hours, etc.
        bool login(int id, string password);
        void view_menu(ifstream &menu);
        void view_hours();
        void view_address();
        void view_phone();
        void search_menu_by_price();
        void search_by_ingredients();
        // note that the following prototype was modified to include additional parameters
        // selection is a dynamically allocated array of Pizza objects that are being ordered
        // selection_size indicates the number of Pizza objects in the array
        // num_ordered is a dynamically allocated array that indicates how many pizzas of each type were ordered
        //void place_order(Pizza* selection, int selection_size, int* num_ordered);
        // you may also choose to use this prototype that was originally included:
        void place_order(Pizza* selection);
        void change_hours();
        void add_to_menu();
        void remove_from_menu();
        void view_orders(ifstream &orders);
        void remove_orders();
        Restaurant(const Restaurant&); //copy constructor
        const Restaurant& operator=(const Restaurant&); //assignment operator overload
        void print_restaurant();
        void customerui();
        void employeeui();
        void uiselection();
        ~Restaurant();
};
