#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

float error();

/*********************************************************************
** Struct: employee
** Description: This is a struct that stores the employee info and login info.
*********************************************************************/ 
struct employee {
    int id;
    string password;
    string first_name;
    string last_name;
};

/*********************************************************************
** Struct: hours
** Description: This is a struct that stores the hours for the store.
*********************************************************************/ 
struct hours {
    string day;
    string open_hour;
    string close_hour;
};