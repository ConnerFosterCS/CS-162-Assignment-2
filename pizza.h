#include "structs.h"

//classes
class Pizza {
    private:
        string name;
        int small_cost;
        int medium_cost;
        int large_cost;
        int num_ingredients;
        string* ingredients;
    public:
        Pizza();
        void load_pizza_data(ifstream &menu_f);
        void set_name(string);
        string get_name() const;
        void set_num_ingredients(int);
        int get_num_ingredients() const;
        void set_from_file(ifstream &menu_f);
        string get_from_file();
        void set_small_cost(int);
        int get_small_cost() const;
        void set_medium_cost(int);
        int get_medium_cost() const;
        void set_large_cost(int);
        int get_large_cost() const;
        Pizza(int); //anternative copy constuctor
        Pizza(const Pizza&); //copy constuctor
        const Pizza& operator=(const Pizza&); //assignment operator overload
        void print_pizza();
        ~Pizza();
};