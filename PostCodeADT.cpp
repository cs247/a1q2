/*
 *  main.cpp
 *  
 *
 *  Created by Joanne Atlee on 08/05/11.
 *
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;



class PostCode {
public:
	PostCode();				    // Construct unset postal code 
	~PostCode();				    // Destructor 
	string postcode() const;		    // Accessor
	bool postcodeIs(string p);		    // Mutator
	bool isUnset() const;			    // Test if postal code is unset
	
private:
	string *postcode_;
	PostCode& operator=(const PostCode&);	    // Disable assignment
};


//************************************************************************
//  Your implementation here
//************************************************************************




//************************************************************************
//  Helper functions
//************************************************************************


// check whether whether test harness command has a second operand
bool anotherOperand(stringstream &inputSS) {
	char space = inputSS.peek();
	return ( !inputSS.eof() && space == ' ' );
}



//*******************
// main()
//*******************

int main() {
	
	cout << "Test harness for Postal Code ADT" << endl << endl;
	PostCode *p = new PostCode();
	
	cout << "Command: ";

	// read whole input line into string, then "stream" from string
	string input;
	while ( getline(cin, input) ) {		
		stringstream inputSS(input);
		
		// parse command: one letter command followed by a space
		char command;
		inputSS >> command;
				
		// process command
		switch (command) {
			// new postal code object
			case 'n': {
				delete p;
				p = new PostCode();
				break;
			}
			
			// set postal code value of existing object
			case 's': {
				if ( anotherOperand(inputSS) ) {
					string code;
					inputSS >> code;
					
					if ( anotherOperand(inputSS) ) {
						string code2;
						inputSS >> code2;
						code = code + " " + code2;
					}
						
					if ( p->postcodeIs(code) ) {
						cout << "Postal Code has been set." << endl;
					}
					else {
						cout << "Postal Code is either already set, or provided value does not meet postal-code rules." << endl;
					}
				}
				else {
					cout << "Command takes a second operand." << endl;
				}

				break;
			}


			// print postal code
			case 'p': {
				if ( p->isUnset() ) {
					cout << "Postal Code is unset." << endl;
				}
				else {
					cout << "Postal Code value is \"" << p->postcode() << "\"" << endl;
				}
				
				break;
			}
				
			

			// check whether postal code is unset
			case 'u': {
				if ( p->isUnset() ) {
					cout << "TRUE. Postal Code is unset." << endl;
				}
				else {
					cout << "FALSE. Postal Code has been set." << endl;
				}
				break;
			}	
				
			default:
				cout << "Invalid command." << endl;
		} // switch
						
		cout << endl << "Command: ";
	} // while input
		
		
	return 0;
}
