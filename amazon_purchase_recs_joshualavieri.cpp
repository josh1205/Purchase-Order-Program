// Name: Joshua Lavieri
// Course: Foundations of Computer Science

// Description: This program will process purchase orders using a phone number and the item number to verify the the product.


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void input (ifstream &, string &, string &, double &, double &, int &);
void process (double, double, int, double &, double &, double &, double &);
void output (string, string, double, double, int, double, double, double, double);

int main()
{
    string cell_number;
    string item_number;
    double quantity;
    double price;
    int processing_plant;
    double tax_rate;
    double order_tax;
    double net_cost;
    double total_cost;
    
    ifstream in;
    in.open("purchase_data.txt");
    
    if (in.fail())
    {
        cout << "Input file did not open correctly" << endl;
    }
    else
    {
        while (!in.eof())
        {
            input(in, cell_number, item_number, quantity, price, processing_plant);
            
            process(quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
            
            output(cell_number, item_number, quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
        }
    }
    
    in.close();
    
    return 0;
}


// Name: Input
// Precondition: The variables have not yet been initialized
// Postcondition: The variables have now been initialized
// Description: Gets the input numbers from the data file
void input (ifstream & in, string & cell_number, string & item_number, double & quantity, double & price, int & processing_plant)
{
    in >> cell_number;
    in >> item_number;
    in >> quantity;
    in >> price;
    in >> processing_plant;
}


// Name: Output
// Precondition: This function uses the initialized varibales and calculations
// Postcondition: Variables have now been put onto the screen
// Description: Output the variables to the screen
void output (string cell_number, string item_number, double quantity, double price, int processing_plant, double tax_rate, double order_tax, double net_cost, double total_cost)
{
    //***********************************MAGIC FORMULA*******************************************
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::fixed);

    cout << cell_number << "\t\t";
    cout << item_number << "\t\t";
    cout << static_cast <int>(quantity) << "\t\t";
    cout << price << "\t\t";
    cout << processing_plant << "\t\t";
    cout << static_cast <int>(tax_rate) << "\t\t";
    cout << order_tax << "\t\t";
    cout << net_cost << "\t\t";
    cout << total_cost << endl;
    
}

// Name: Process
// Precondition: Variables have been initialized
// Postcondition: Calculations have been created
// Description: Calculates the cost's from the initialized variables
void process (double quantity, double price, int processing_plant, double & tax_rate, double & order_tax, double & net_cost, double & total_cost)
{
    //**************************************TAX RATE CALCULATION********************************
    
    if (processing_plant >= 0 && processing_plant <= 50)
    {
        tax_rate = 6;
    }
    else if(processing_plant >= 51 && processing_plant <= 110)
    {
        tax_rate = 7;
    }
    else if (processing_plant >= 111 && processing_plant <= 200)
    {
        tax_rate = 8;
    }
    else if (processing_plant >= 201 && processing_plant <= 500)
    {
        tax_rate = 9;
    }
    else if (processing_plant > 500)
    {
        tax_rate = 11;
    }
    
    order_tax = quantity * price * (tax_rate / 100);
    
    //*************************************NET COST CALCULATION************************************
    
    net_cost = quantity * price;

    //***********************************TOTAL COST CALCULATION************************************

    total_cost = net_cost + order_tax;
}
