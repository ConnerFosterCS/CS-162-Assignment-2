#include "resturant.h"

//menu constructor
Restaurant::Restaurant() {
    cout << "Resturant Constructor Called" << endl;
    this -> employees = NULL;
    this -> week = NULL;
    this -> name = "-default_string-";
    this -> phone = "-default_string-";
    this -> address = "-default_string-";
    this -> num_employees = 0;
    this -> num_orders = 0;
    Menu m;
}

/*********************************************************************
** Function: number_employees
** Description: reads the number of lines in employee.txt to determine the number of employees.
** Parameters: ifstream &employee_f
** Pre-Conditions: filed opened porperly
*********************************************************************/ 
void Restaurant::number_employees(ifstream &employee_f) {
    employee_f.open("employee.txt");
    
    string s;
    
    while (!employee_f.eof()) {
        getline(employee_f, s);
        num_employees ++;
    } employee_f.close(); 
}

void Restaurant::number_orders(ifstream &orders) {
    orders.open("orders.txt");
    
    string s;
    
    while (!orders.eof()) {
        getline(orders, s);
        num_orders ++;
    } orders.close(); 
}

/*********************************************************************
** Function: set_name
** Description: This function sets the class variables
*********************************************************************/
void Restaurant::set_name(string names) {
    this -> name = names;
}

/*********************************************************************
** Function: get_name
** Description: This function returns the class variables
*********************************************************************/
string Restaurant::get_name() const{
    return name;
}

/*********************************************************************
** Function: set_phone
** Description: This function sets the class variables
*********************************************************************/
void Restaurant::set_phone(string phone_num) {
    this -> phone = phone_num;
}

/*********************************************************************
** Function: get_phone
** Description: This function returns the class variables
*********************************************************************/
string Restaurant::get_phone() const{
    return phone;
}

/*********************************************************************
** Function: set_address
** Description: This function sets the class variables
*********************************************************************/
void Restaurant::set_address(string address_s) {
    this -> address = address_s;
}

/*********************************************************************
** Function: get_address
** Description: This function returns the class variables
*********************************************************************/
string Restaurant::get_address() const{
    return address;
}

/*********************************************************************
** Function: load_data
** Description: This functions fills the structs and more of the classes with info from file streams
** Parameters: ifstream &employee_f, ifstream &restaurant_info
** Pre-Conditions: Files are opened properly
** Post-Conditions: structs and classes filled
*********************************************************************/ 
void Restaurant::load_data(ifstream &employee_f, ifstream &restaurant_info) { //reads from files to correctly populate menu, employees, hours, etc.
    employee_f.open("employee.txt");
    restaurant_info.open("restaurant_info.txt");

    cout << "num_emp2: " << num_employees << endl;
    this -> employees = new struct employee[num_employees];
    this -> week = new struct hours[7];

    for (int i = 0; i < num_employees; i++) {
        employee_f >> this -> employees[i].id;
        employee_f >> this -> employees[i].password;
        employee_f >> this -> employees[i].first_name;
        employee_f >> this -> employees[i].last_name;
    }
    
    getline(restaurant_info, name);
    getline(restaurant_info, phone);
    getline(restaurant_info, address);
    for (int i = 0; i < 7; i++) {
        restaurant_info >> this -> week[i].day;
        restaurant_info >> this -> week[i].open_hour;
        restaurant_info >> this -> week[i].close_hour;
    }
    employee_f.close();
    restaurant_info.close();
}

/*********************************************************************
** Function: login
** Description: This function checks the user login information
** Parameters: int id, string password
** Pre-Conditions: user is an employee
** Post-Conditions: employee is logged in.
*********************************************************************/ 
bool Restaurant::login(int id, string password) {
    cout << "\nPlease enter your ID number here: ";
    id = error(); //ta help: how to call error handle?
    cout << "Please enter your password here: ";
    cin >> password;
    
    for (int i = 0; i < num_employees; i++) {
        if (id == employees[i].id && password == employees[i].password) {
            cout << "\nWelcome " << employees[i].first_name << " " << employees[i].last_name;
            break;
        }
        else if (id != employees[i].id || password != employees[i].password) {
            cout << "Incorrect ID or password. Try again." << endl;
            login(id, password);
        }
    } employeeui();
}

/*********************************************************************
** Function: view_menu
** Description: reads the menu.txt file and prints it to the screen 
** Parameters: ifstream &menu_f
** Pre-Conditions: user chooses to view menu
** Post-Conditions: menu is printed to terminal
*********************************************************************/ 
void Restaurant::view_menu(ifstream &menu_f) {
    menu_f.open("menu.txt");
    string s;
    
    for (int i = 0; i < 6; i++) {
        getline(menu_f, s);
        cout << s << endl;
    } menu_f.close();
}

/*********************************************************************
** Function: view_hours
** Description: reads the class info
** Pre-Conditions: user chooses to view menu
** Post-Conditions: menu is printed to terminal
*********************************************************************/ 
void Restaurant::view_hours() {
    cout << "\nOur hours are: " << endl;
    for (int i = 0; i < 7; i++) {
        cout << week[i].day << ' ' << week[i].open_hour << " to " << week[i].close_hour << endl;
    }
}

/*********************************************************************
** Function: view_address
** Description: reads the class info
** Pre-Conditions: user chooses to view address
** Post-Conditions: address is printed to terminal
*********************************************************************/ 
void Restaurant::view_address() {
    cout << "Our adress is: " << address << endl;
}

/*********************************************************************
** Function: view_phone
** Description: reads the class info
** Pre-Conditions: user chooses to view phone number
** Post-Conditions: phone number is printed to terminal
*********************************************************************/ 
void Restaurant::view_phone() {
    cout << "Out phone number is: " << phone << endl;
}

/*********************************************************************
** Function: search_by_ingredients
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::search_menu_by_price() {
    cout << "\nDoesnt work sorry :(" << endl;
}

/*********************************************************************
** Function: search_by_ingredients
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::search_by_ingredients() {
    cout << "\nDoesnt work sorry :(" << endl;
}

// you may also choose to use this prototype that was originally included:
/*********************************************************************
** Function: place_order
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::place_order(Pizza* selection) {
    ofstream orders;
    orders.open("orders.txt", ios_base::app);
    string name, pizza, size;
    char choice;
    int cnum, pnum, ammount, i = 0;
    cout << "\nEnter your name: ";
    cin >> name;
    cout << "Enter your card number: ";
    cnum = error();
    cout << "Enter your phone number: ";
    pnum = error();
    orders << "\n" << name << ' ' << cnum << ' ' << pnum;
    while (i == 0) {
        cout << "Enter a pizza: ";
        cin >> pizza;
        cout << "Do you want a S, M, or L?";
        cin >> size;
        cout << "How many do you want? ";
        ammount = error();
        orders << ' ' << pizza << ' ' << size << ' ' << ammount;
        cout << "Do you want to add another pizza? enter y or n: ";
        cin >> choice;
        if (choice == 'y')
            i = 0;
        else if (choice == 'n')
            i++;
    } orders.close();
    cout << endl;
}

/*********************************************************************
** Function: change_hours
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::change_hours() {
    string choice, open, close;
    cout << "\nWhich day would you like to change the hours for? ";
    cin >> choice;
    for (int i = 0; i < 7; i++) {
        if (choice == week[i].day) {
            cout << "What should the opening time be? ";
            cin >> open;
            week[i].open_hour = open;
            cout << "What should the closing time be? ";
            cin >> close;
            week[i].close_hour = close;
        }
    } view_hours();
}

/*********************************************************************
** Function: add_to_menu
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::add_to_menu() {
    ofstream menu;
    menu.open("menu.txt", ios_base::app);
    string name, ingredient;
    int num, smlcst, medcst, lrgcst;
    cout << "\nEnter the pizza name(No Spaces!): ";
    cin >> name;
    cout << "Enter the small cost: "; 
    smlcst = error();
    cout << "Enter the medium cost: "; 
    medcst = error();
    cout << "Enter the large cost: "; 
    lrgcst = error();
    cout << "How many ingredients are of the pizza? "; 
    cin >> num;
    menu << "\n" << name << ' ' << smlcst << ' ' << medcst << ' ' << lrgcst;
    
    for (int i = 0; i < num; i++) {
        cout << "Enter ingredient: ";
        cin >> ingredient;
        menu << ' ' << ingredient;
    }
}

/*********************************************************************
** Function: remove_from_menu
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::remove_from_menu() {
    cout << "\nDoesnt work sorry :(" << endl;
}

/*********************************************************************
** Function: view_orders
** Description: Opens the orders file to 
** Parameters: ifstrem &orders
** Pre-Conditions: ifstream for orders.txt opens properly.
** Post-Conditions: current orders are printed to screen.
*********************************************************************/ 
void Restaurant::view_orders(ifstream &orders) {
    orders.open("orders.txt");
    string s;

    cout << "\nPending Orders: ";
    for (int i = 0; i < num_orders; i++) {
        getline(orders, s);
        cout << s << endl;
    } orders.close();
}

/*********************************************************************
** Function: remove_orders
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Restaurant::remove_orders() {
    cout << "\nDoesnt work sorry :(" << endl;
}

//copy constructor
Restaurant::Restaurant(const Restaurant& other) {
    cout << "Restaurant Copy Constructor Called" << endl;
    int num_employees;
    employees = new employee[num_employees];
    week = new hours[7];
    name = other.name;
    phone = other.phone;
    address = other.address;

    for(int i = 0; i < num_employees; i++) {
        employees[i] = other.employees[i];
    }

    for(int i = 0; i < 7; i++) {
        week[i] = other.week[i];
    }
}

//assignment operator overload
const Restaurant& Restaurant::operator=(const Restaurant& other) {
    cout << "Restaurant Assignment Operator Invoked" << endl;
    delete[] employees;
    employees = NULL;
    delete[] week;
    week = NULL;
    
    employees = new employee[num_employees];
    week = new hours[7];
    this -> name = other.name;
    this -> phone = other.phone;
    this -> address = other.address;

    for(int i = 0; i < num_employees; i++) {
        employees[i] = other.employees[i];
    }

    for(int i = 0; i < 7; i++) {
        week[i] = other.week[i];
    }
}
/*********************************************************************
** Function: print_pizza
** Description: This function prints the current values of the pizza class.
*********************************************************************/
void Restaurant::print_restaurant() {
    cout << this -> employees << endl;
    cout << this -> week << endl;
    cout << this -> name << endl;
    cout << this -> phone << endl;
    cout << this -> address << endl;
}

/*********************************************************************
** Function: customerui
** Description: This function directs the path of the customer in their decision making
*********************************************************************/
void Restaurant::customerui() {
    int choicenum, id;
    ifstream menu_f;
    Pizza* selection;
    
    cout << "\nWhat would you like to do?\n" << "  1. View Menu\n" << "  2. Search by Cost\n" << "  3. Search by Ingredients\n" << "  4. Place Order\n" << "  5. View Hours\n" << "  6. View Address\n" << "  7. View Phone\n" << "  8. Log out\n" << "  Enter choice here: ";
    choicenum = error();
    if (choicenum == 1) {
        view_menu(menu_f); //works
        customerui();
    } else if(choicenum == 2) {
        search_menu_by_price();
        customerui();
    } else if(choicenum == 3) {
        search_by_ingredients();
        customerui();
    } else if(choicenum == 4) {
        place_order(selection); //works
        customerui();
    } else if(choicenum == 5) {
        view_hours(); //works
        customerui();
    } else if(choicenum == 6) {
        view_address(); //works
        customerui();
    } else if(choicenum == 7) {
        view_phone(); //works
        customerui();
    } else if(choicenum == 8) {
        uiselection(); //works
    } else {
        cout << "Incorrect input" << endl;
        customerui();
    }
}

/*********************************************************************
** Function: employeeui
** Description: This function directs the path of the employee in their decision making
** Pre-Conditions: the employee correctly logged in.
*********************************************************************/
void Restaurant::employeeui() {
    int choicenum;
    ifstream menu_f, orders;
    cout << "\nWhat would you like to do?\n" << "  1. Change Hours\n" << "  2. View Orders\n" << "  3. Remove Order\n" << "  4. Add Item to Menu\n" << "  5. Remove Item from Menu\n" << "  6. View Menu\n" << "  7. View Hours\n" << "  8. View Address\n" << "  9. View Phone\n" << "  10. Log Out\n" << "  Enter choice here: ";
    choicenum = error();
    if (choicenum == 1) {
        change_hours(); //works
        employeeui();
    } else if(choicenum == 2) {
        view_orders(orders); // works
        employeeui();
    } else if(choicenum == 3) {
        remove_orders();
        employeeui();
    } else if(choicenum == 4) {
        add_to_menu();
        employeeui();
    } else if(choicenum == 5) {
        remove_from_menu();
        employeeui();
    } else if(choicenum == 6) {
        view_menu(menu_f); //works
        employeeui();
    } else if(choicenum == 7) {
        view_hours(); //works
        employeeui();
    } else if(choicenum == 8) {
        view_address(); //works
        employeeui();
    } else if(choicenum == 9) {
        view_phone(); //works
        employeeui();
    } else if(choicenum == 10) {
        uiselection(); //works
    } else {
        cout << "Incorrect input" << endl;
        employeeui();
    }
}

/*********************************************************************
** Function: uiselection
** Description: Directs the choice if the user is a customer or an employee.
*********************************************************************/
void Restaurant::uiselection() {
    char choicechar;
    int id;
    string password;
    cout << "\nWelcome to Bytes Pizza!\n" << "Are you a customer (C) or employee (E) or would you like to quit (Q)?\n" << "Enter choice here: ";
    cin >> choicechar;
    if (choicechar == 'c' || choicechar == 'C') {
        customerui();
    } else if (choicechar == 'e' || choicechar == 'E') {
        login(id, password);
        employeeui();
    } else if (choicechar == 'q' || choicechar == 'Q') {
        exit(0);
    } else {
        cout << "incorrect input" << endl;
        uiselection();
    }
}

//restaurant destructor
Restaurant::~Restaurant() {
    cout << "Restaurant Destructor Called" << endl;
    delete[] employees;
    employees = NULL;
    delete[] week;
    week = NULL;
}