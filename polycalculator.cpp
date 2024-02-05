
#include<fstream>
#include<iostream>
#include "polycalculator.h"
#include<string>
using namespace std;

void PolyCalculator::input() {
// initialising two polynomials
    string polynomial1, polynomial2;
// it runs until break is called
    while (true) {
        list1.removeAll();    
        list2.removeAll();
        
        cout << "Enter the first polynomial expression: ";
        // getting first polynomial as input
        getline(cin, polynomial1);
// calling parse function to parse polynomial1 and insert to list1
        if (parse(polynomial1, list1)) {
            // if parse doesn't succed, it will start again
            cout << "First polynomial expression has been successfully parsed and stored." << endl;
            // if parse works(means input is correct) it will breka the loop
            break;  
        } 
    }
    while (true) {
        cout << "Enter the second polynomial expression: ";
      // getting second polynomial as input
        getline(cin, polynomial2);
// calling parse function to parse polynomial2 and insert to list2
        if (parse(polynomial2, list2)) {
            cout << "Second polynomial expression has been successfully parsed and stored." << endl;
          // if parse works(means input is correct) it will breka the loop
            break; 
        }
    }
}
// display functin to print out both th polynomials
void PolyCalculator::display(ostream &os) {
    // calling print function to print the polynomials
    os << "Exp1: ";
    list1.print(os);
    os << "Exp2: ";
    list2.print(os);
}
// Add Function
void PolyCalculator::add(ostream &os) {
    // Get the head of list1 to current 1 node
    Node* current1 = list1.getHead(); 
    // Get the head of list2 to current2 node
    Node* current2 = list2.getHead(); 

    // Initialize list3 for the result
    // Clear any previous contents
    list3.removeAll(); 
    int coef, expo;
   // it runs until there are terms in one of lists 
    while (current1 || current2) {
         // Both lists have terms
        if (current1 && current2) {
        //    if exponents of current1=current2
            if (current1->expo == current2->expo) {
                // add coefficients
                coef = current1->coef + current2->coef;
                expo = current1->expo;
                // move pointer to the next node
                current1 = current1->next;
                current2 = current2->next;
                // If expo of current1 is less than expo of current2
            } else if (current1->expo < current2->expo) {
                // Copy term from list2
                coef = current2->coef;
                expo = current2->expo;
                // // move pointer to the next node
                current2 = current2->next;
                // If expo of current2 is less than expo of current1
            } else {
                // Copy term from list1 
                coef = current1->coef;
                expo = current1->expo;
                // move pointer to the next node
                current1 = current1->next;
            }
            // If list one has remaining terms
        } else if (current1) {
            // copy  it
            coef = current1->coef;
            expo = current1->expo;
             // move pointer to the next node
            current1 = current1->next;
            // If list 2 has remaining terms
        } else {
            // copy  it
            coef = current2->coef;
            expo = current2->expo;
            // move pointer to the next node
            current2 = current2->next;
        }
        // Insert the term into list3
        list3.insert(coef, expo);
    }
    // checks if list3 has terms
    if (list3.getHead()) {
        // if not empty, print
        os << "Addition: ";
        list3.print(os);
        // if empty
    } else {
        cout << "Empty list3" << endl;
    }
}

void PolyCalculator::sub(ostream &os) {
    // Get the head of list1
    Node* current1 = list1.getHead(); 
    // Get the head of list2
    Node* current2 = list2.getHead(); 

    // Initialize list3 
    // Clear any previous contents
    list3.removeAll(); 
    int coef, expo;
// it runs until there are terms in one of lists
    while (current1 || current2) {
        // Both lists have terms
        if (current1 && current2) {
            // if coefficients are same
            if (current1->expo == current2->expo) {
                // Subtract coefficients 
                coef = current1->coef - current2->coef;
                expo = current1->expo;
                // move pointer to next node
                current1 = current1->next;
                current2 = current2->next;
                 // If expo of current1 is less than expo of current2
            } else if (current1->expo < current2->expo) {
                // Copy term from list2 
                coef = -current2->coef;
                expo = current2->expo;
                // move pointer to next node
                current2 = current2->next;
                 // If expo of current2 is less than expo of current1
            } else {
                // Copy term from list1 
                coef = current1->coef;
                expo = current1->expo;
                // move pointer to next node
                current1 = current1->next;
            }
             // If list one has remaining terms
        } else if (current1) {
        //    copy term
            coef = current1->coef;
            expo = current1->expo;
             // move pointer to next node
            current1 = current1->next;
             // If list2 has remaining terms
        } else {
        //     copy term
            coef = -current2->coef;
            expo = current2->expo;
             // move pointer to next node
            current2 = current2->next;
        }
        // Insert the term into list3
        list3.insert(coef, expo);
    }
    // cheks if list3 has terms
    if (list3.getHead()) {
        // print
        os << "Subtraction: ";
        list3.print(os);
        // if empty
    } else {
        cout << "Empty list3" << endl;
    }
}

void PolyCalculator::mul(ostream &os) {
     // Get the head of list1
    Node* current1 = list1.getHead();
    Node* current2;

    // Initialize list3 
    // Clear any previous contents
    list3.removeAll(); 
// until current1 has terms this loop executes
    while (current1) {
        // // Get the head of list2
        current2 = list2.getHead();
        // until current2 has terms this loop executes
        while (current2) {
            // multiply coef and expo of current1 and current2
            int coef = current1->coef * current2->coef;
            int expo = current1->expo + current2->expo;

            // Insert the term into list3
            list3.insert(coef, expo);
        // move pointer to next node 
            current2 = current2->next;
        }
        // move pointer to next term
        current1 = current1->next;
    }
    // if list3 is not empty
    if (list3.getHead()) {
        // print
        os << "Multiply: ";
        list3.print(os);
        // if list3 is empty
    } else {
        cout << "Empty list3" << endl;
    }
}
// function to read form file
void PolyCalculator::readData(string path) {
    // inputfile is created and opened with path
    ifstream inputFile(path);
// if there is error while opening this file
    if (!inputFile.is_open()) {
        cout << "Error: Could not open the file for reading." << endl;
        return;
    }
// declaring two polynomials
    string polynomial1, polynomial2;
// read line by line form the file and add them to polinomials respectively
    getline(inputFile, polynomial1);
    getline(inputFile, polynomial2);
    
// close the file
    inputFile.close();
    // remove previous contents from lists
    list1.removeAll();
    list2.removeAll();
    // Parse the expressions
    if (parse(polynomial1, list1) && parse(polynomial2, list2)) {
        cout << "Polynomial expressions have been successfully read and parsed." << endl;
    } else {
        cout << "Invalid polynomial expression(s) in the file." << endl;
    }
}

// Function to write to the file
void PolyCalculator::writeData(string path) {
    // Outputfile is created and opened with path
    ofstream outputFile(path);
// Cheks it successfully opened
    if (!outputFile.is_open()) {
        cout << "Error: Could not open the file for writing." << endl;
        return;
    }
//    write content of list1 to outputfile
    outputFile << "Polynomial 1: ";
    list1.print(outputFile);
//    write content of list2 to outputfile
    outputFile << "Polynomial 2: ";
    list2.print(outputFile);
//    write addition result to outputfile
    outputFile << "Addition Result: ";
    add();
    list3.print(outputFile);
//    write subtraction result to outputfile
    outputFile << "Subtraction Result: ";
    sub();
    list3.print(outputFile);
//    write multiplication result to outputfile
    outputFile << "Multiplication Result: ";
    mul();
    list3.print(outputFile);
// close the file
    outputFile.close();

    cout << "Results have been written to the file." << endl;
}

// pasing polynomials
bool PolyCalculator::parse(string str, LinkedList& list) {
    // initializing i,coef,expo,operator(op)
    int i = 0;
    int coef, expo;
    char op = '+';
    // Check for first operator sign in the polynomial
    if (i == 0 && (str[i] != '+' && str[i] != '-')) {
        // if there is no operator, default is +
            op = '+';
    } else if (str[i] == '+' || str[i] == '-') {
            op = str[i];
            i++;
    } 
    // Iterating over every character in polynomial 
    while (i < str.length()) {
        // checking for coeeficient/if it is digit
        if (i < str.length() && isdigit(str[i])) {
            // initializing it with 0 as we can't use previous coffecient for the next one
            coef = 0; 
            while (i < str.length() && isdigit(str[i])) {
                // wriitng down the coefficient 
// getting integer value of coef after subtracting cahracter code of 0
                coef = coef * 10 + (str[i] - '0');
                i++;
            }
            //  Coefficient is missing, so it's assumed to be 1
        } else if (i < str.length() && str[i] == 'x') {
            coef = 1;
    
        } else {
            cout << "Invalid Expression: Coefficient is missing or not valid" << endl;
            return false;
        }

        // Checking for 'x'
        if (i < str.length() && str[i] == 'x' && i+1<str.length()) {
            i++;
        } else {
            cout << "Invalid Expression x missing"<< endl;
            return false;
        }

        // Checking for '^' and extracting the exponent
        if (i < str.length() && str[i] == '^') {
            i++;
            // if next term is a digit get inside the loop and extract exponent the same way we extracted coef
            if (isdigit(str[i])) {
                expo = 0;
                while (i < str.length() && isdigit(str[i])) {
                    expo = expo * 10 + (str[i] - '0');
                    i++;
                }
            } else {
                cout << "Invalid Expression: Exponent is missing or not valid" << endl;
                return false;
            }
        }

        // Apply the sign
        if (op == '-') {
            coef = -coef;
        }

        // Calling insert function of linkedlist claasss to insert the term into the linked list
        list.insert(coef, expo);

        // Check for operators between terms,i+1<str.length checks if i is not the last character of the polynomial, if it does this becomes invalid polynomial
        if (i < str.length() && (str[i] == '+' || str[i] == '-')&&(i+1<str.length())) {
            if(str[i+1]=='+'||str[i+1]=='-'){
                cout << "Invalid Expression : Double operator used"<< endl;
                return false;
            }
            else{
                op = str[i];
                i++;}
        } else if (i < str.length()) {
            // if operator deosn't exist, invL EXPRESIIN
            cout << "Invalid Expression  "<< endl;
            return false;
        }
    }
    // If successfully parsed the expression
    return true;
}

