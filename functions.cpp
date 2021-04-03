#include "structs.h"

/*********************************************************************
** Function: error
** Description: This function takes all user input and makes sure that it is a float or an int.
** Parameters: none
** Pre-Conditions: user input = to function.
** Post-Conditions: i/user input or error msg.
*********************************************************************/ 
float error() {
	float i;
	string s;
	bool error;
	do {
		error = false;
		cin >> s;
        
		for (float i = 0; i < s.size(); i++) {
			if(!(s.at(i) >= '0' && s.at(i) <= '9')) {
				cout << "error: your input must be a whole number or a decimal number." << endl;
                cout << "Enter your input here: ";
				error = true;
                break;
			}
		}
	} while(error);
    
	i = atof(s.c_str());
    return i;
}