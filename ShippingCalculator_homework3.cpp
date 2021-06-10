// ShippingCalculator_homework3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Write a Item Shipping Calculator program that does the following:
/*Promptand retrieve the following input from the user(through the console) :
    Item name
    Is the item fragile(add in $2.00 if the item is fragile)
    The order total(without shipping)
    The destination to which the item will be shipped(USA, Canada, Australia)
    If the item is fragile add $2.00 to the shipping cost.*/


#include <iostream>
#include <algorithm>    //this is needed for.... transform(input.begin(), input.end(), input.begin(), toupper); changes input to cap letters
#include <iomanip>     //stream manipulators
#include <string>
#include <fstream>  //So i can write to a file
using namespace std;

//constant variables
const double Y_FRAGILE = 2.00;  //when item is fragile = $2.00 fee
//constants for less than 50
const double USA_LESS50 = 6.00;
const double CAN_LESS50 = 8.00;
const double AUS_LESS50 = 10.00;
const double MARS_LESS50 = 20.00;
//constants for 50.01 to 100.00
const double USA_50_TO_100 = 9.00;
const double CAN_50_TO_100 = 12.00;
const double AUS_50_TO_100 = 14.00;
const double MARS_50_TO_100 = 35.00;
//constants for 100.01 to 150
const double USA_100_TO_150 = 12.00;
const double CAN_100_TO_150 = 15.00;
const double AUS_100_TO_150 = 17.00;
const double MARS_100_TO_150 = 45.00;

int main()
{
    //ofsteam= Stream class to write on files
    //ifstream= Stream class to read from files
    ofstream outFile;
   //opening output file order.txt
    outFile.open("order.txt"); 

    //using stram manipulators. writing to console....
    cout << setw(80) << setfill('*') << "" << endl;		//this will print out 80 '*'
    cout << setw(60) << setfill('*') << right << "ITCS 2530 - Programming Assignment for Week #3" << left << setw(20) << setfill('*') << "" << endl;	//centering my text within 80 collumns
    cout << setw(80) << setfill('*') << "" << endl << endl;	//setw() = sets a number of collumns, setfill()= allows you to fill in thoes blank collumns when needed
    //writing to file....
    outFile << setw(80) << setfill('*') << "" << endl;
    outFile << setw(60) << setfill('*') << right << "ITCS 2530 - Programming Assignment for Week #3" << left << setw(20) << setfill('*') << "" << endl;
    outFile << setw(80) << setfill('*') << "" << endl << endl;
    
    
    //asking user for input
    string item_name;
    cout << setw(60) << setfill('.') << left << "Please enter the item name (no spaces)" << setw(20) << right << ":";   //using manipulators to display to console
    outFile << setw(60) << setfill('.') << left << "Please enter the item name (no spaces)" << setw(20) << right << ":"; //using manipulators to display to file
    cin >> item_name;   //input from console 
    outFile << item_name << endl;   //write to file
    transform(item_name.begin(), item_name.end(), item_name.begin(), ::toupper); //this takes the input and makes it all CAPS

    // asking user if item is fragile? y or no. CHAR
    char fragile;
    cout << setw(60) << setfill('.') << left << "Is the item fragile (y=yes/n=no)" << setw(20) << right << ":";
    outFile << setw(60) << setfill('.') << left << "Is the item fragile (y=yes/n=no)" << setw(20) << right << ":";
    cin >> fragile; //console
    outFile << fragile << endl; //to file..
  
    //asking for order total BEFORE SHIPPING
    double order_total;
    cout << setw(60) << setfill('.') << left << "Please enter your order total" << setw(20) << right << ":";
    outFile << setw(60) << setfill('.') << left << "Please enter your order total" << setw(20) << right << ":";
    cin >> order_total;
    outFile << order_total << endl;

    //asking user for the destination (usa/can/aus)
    string des;
    cout << setw(60) << setfill('.') << left << "Please enter destination. (usa/can/aus/mars)" << setw(20) << right << ":" ;
    outFile << setw(60) << setfill('.') << left << "Please enter destination. (usa/can/aus/mars)" << setw(20) << right << ":";
    cin >> des;
    outFile << des << endl;
    transform(des.begin(), des.end(), des.begin(), ::toupper); //changing to CAPS for ouput

    //just a space between input and output
    cout << endl;   
    outFile << endl;

    //initializing strings for output. this makes it easier to type in the loop
    string s1 = "Your item is : ";
    string s2 = "Your shipping cost is: ";
    string s3 = "You are shipping to: ";
    string s4 = "Your total shipping cost is: "; 

    double total=0;   //initilizing user_total + shipping 

    //OUTPUT TO USER
    if ((des == "usa") || (des == "USA")) //USA SHIPPING, begining of if-else statment 
        //using the or || operator to include CAPS and lower case... && = AND
        switch (fragile)    //using switch statment to determine fragile fee
        {
        case 'N':   //includes both CAP and lower case
        case 'n':   //groups both cases into one
            if (order_total < 50.00)                                //less than 50
                total = order_total + USA_LESS50;                   // I used constants because these values never change
            else if (order_total > 50.00 && order_total <= 100.00)  //between 50.01 and 100
                total = order_total + USA_50_TO_100;
            else if (order_total > 100.00 && order_total <= 150.00) //between 100.01 and 150
                total = order_total + USA_100_TO_150;
            else if (order_total > 150.00)                          //no fees over 150.0
                total = order_total;
            //display to console...
            cout << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            cout << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;    //setprecision(2)= 2 decimal places
            cout << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            cout << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            cout << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            //display to file...
            outFile << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            outFile << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            outFile << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            outFile << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            outFile << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            break;
        case 'Y':   // Yes fragile item
        case 'y':
            if (order_total < 50.00)
                total = order_total + USA_LESS50 + Y_FRAGILE;
            else if (order_total > 50.00 && order_total <= 100.00)
                total = order_total + USA_50_TO_100 + Y_FRAGILE;
            else if (order_total > 100.00 && order_total <= 150.00)
                total = order_total + USA_100_TO_150 + Y_FRAGILE;
            else if (order_total > 150.00)
                total = order_total + Y_FRAGILE;  //no fees over 150
            //to console...
            cout << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            cout << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            cout << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            cout << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            cout << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            //to file...
            outFile << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            outFile << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            outFile << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            outFile << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            outFile << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            break;
        }
    else if ((des == "can") || (des == "CAN")) //CANADA SHIPPING, pay attention to parentheses!!! Because of the order of precedence, i needed double parentheses
        switch (fragile)
        {
        case 'N':   //not fragle
        case 'n':
            if (order_total < 50.00)
                total = order_total + CAN_LESS50;
            else if (order_total > 50.00 && order_total <= 100.00)
                total = order_total + CAN_50_TO_100;
            else if (order_total > 100.00 && order_total <= 150.00)
                total = order_total + CAN_100_TO_150;
            else if (order_total > 150.00)
                total = order_total;
            //console
            cout << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            cout << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            cout << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            cout << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            cout << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            //file
            outFile << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            outFile << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            outFile << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            outFile << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            outFile << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            break;

        case 'Y':   //yes fragile
        case 'y':
            if (order_total < 50.00)
                total = order_total + CAN_LESS50 + Y_FRAGILE;
            else if (order_total > 50.00 && order_total <= 100.00)
                total = order_total + CAN_50_TO_100 + Y_FRAGILE;
            else if (order_total > 100.00 && order_total <= 150.00)
                total = order_total + CAN_100_TO_150 + Y_FRAGILE;
            else if (order_total > 150.00)
                total = order_total + Y_FRAGILE;  //no fees over 150
            cout << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            cout << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            cout << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            cout << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            cout << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            //file
            outFile << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            outFile << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            outFile << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            outFile << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            outFile << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            break;
        }
    else if ((des == "aus") || (des == "AUS")) //AUS SHIPPING, else if statment 
        switch (fragile)
        {
        case 'N':
        case 'n':
            if (order_total < 50.00)
                total = order_total + AUS_LESS50;
            else if (order_total > 50.00 && order_total <= 100.00)
                total = order_total + AUS_50_TO_100;
            else if (order_total > 100.00 && order_total <= 150.00)
                total = order_total + AUS_100_TO_150;
            else if (order_total > 150.00)
                total = order_total;
            cout << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            cout << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            cout << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            cout << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            cout << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            //file 
            outFile << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            outFile << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            outFile << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            outFile << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            outFile << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            break;

        case 'Y':
        case 'y':
            if (order_total < 50.00)
                total = order_total + AUS_LESS50 + Y_FRAGILE;
            else if (order_total > 50.00 && order_total <= 100.00)
                total = order_total + AUS_50_TO_100 + Y_FRAGILE;
            else if (order_total > 100.00 && order_total <= 150.00)
                total = order_total + AUS_100_TO_150 + Y_FRAGILE;
            else if (order_total > 150.00)
                total = order_total + Y_FRAGILE;  //no fees over 150
            cout << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            cout << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            cout << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            cout << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            cout << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            //file
            outFile << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
            outFile << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
            outFile << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
            outFile << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
            outFile << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
            break;
        }
    else if ((des == "mars") || (des == "MARS")) // SHIPPING TO MARS, else if statment 
    switch (fragile)
    {
    case 'N':
    case 'n':
        if (order_total < 50.00)
            total = order_total + MARS_LESS50;
        else if (order_total > 50.00 && order_total <= 100.00)
            total = order_total + MARS_50_TO_100;
        else if (order_total > 100.00 && order_total <= 150.00)
            total = order_total + MARS_100_TO_150;
        else if (order_total > 150.00)
            total = order_total;
        cout << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
        cout << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
        cout << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
        cout << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
        cout << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
        //file 
        outFile << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
        outFile << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
        outFile << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
        outFile << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
        outFile << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
        break;

    case 'Y':
    case 'y':
        if (order_total < 50.00)
            total = order_total + MARS_LESS50 + Y_FRAGILE;
        else if (order_total > 50.00 && order_total <= 100.00)
            total = order_total + MARS_50_TO_100 + Y_FRAGILE;
        else if (order_total > 100.00 && order_total <= 150.00)
            total = order_total + MARS_100_TO_150 + Y_FRAGILE;
        else if (order_total > 150.00)
            total = order_total + Y_FRAGILE;  //no fees over 150
        cout << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
        cout << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
        cout << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
        cout << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
        cout << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
        //file
        outFile << setw(60) << left << s1 << setw(20) << right << "" << item_name << endl;
        outFile << setw(60) << left << s2 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total - order_total << endl;
        outFile << setw(60) << left << s3 << setw(20) << right << "" << des << endl;
        outFile << setw(60) << left << s4 << setw(20) << right << "" << "$" << setprecision(2) << fixed << total << endl;
        outFile << endl << setw(86) << setfill('-') << right << "Thank You!" << endl;
        break;
    }
    else    //invaild entry for des or fragile, print out this!
        cout << "Invaild entry, exiting" << endl;
       

        //closing ouptut file....
        outFile.close();
    }


