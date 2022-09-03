// Auther: Lane Murray
// Date: 9/21/2021
#include "queue.h"
#include "stack.h"
#include "package.h"
#include <iostream>
#include <climits>
#include <stdexcept>
#include <string>

using namespace std;

int main()
{
    string destination, address, city, state;
    int choice, zipCode, postalClass;
    bool isDone = false;
    
    linkedQueue<package> packages; // Master queue.
    linkedQueue<package> packagesTemp; // Temporary queue.
    linkedQueue<package> packagesSorted; // Sorted queue.

    while (isDone != true) // Runs until the user is done adding items to the queue.
    {
        cout << "Please choose and option from the menu:\n 1. Add a package\n 2. Exit (Display Packages in Queue)\n";
        cin >> choice;
        while (!cin || choice < 1 || choice > 2)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\nError... Please enter valid data.";
            cout << "\nPlease choose and option from the menu:\n 1. Add a package\n 2. Exit (Display Packages in Queue)\n";
            cin >> choice;

        }

        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if (choice == 1) // If they choose to add a package
        {
            cout << "\nEnter the name of the destination: ";
            getline(cin, destination);

            cout << "\nEnter the street address: ";
            getline(cin, address);

            cout << "\nEnter the city: ";
            getline(cin, city);

            cout << "\nEnter the state: ";
            getline(cin, state);

            cout << "\nEnter the zip code: ";
            cin >> zipCode;

            while (!cin || zipCode < 10000 || zipCode > 99999) // Only valid zip codes
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "\nError... Please enter valid data.";
                cout << "\nEnter the zip code: ";
                cin >> zipCode;
            }

            // I decided to use a list like this instead of relying on the user writting out everything correctly every time.
            cout << "\nHow would you like to mail the package:\n 1. Priority Mail Express\n 2. Priority Mail\n 3. First-Class Mail\n 4. Periodicals";
            cout << "\n 5. USPS Marketing Mail\n 6. Package Services\n 7. USPS Retail Ground\n";
            cin >> postalClass;

            while (!cin || postalClass < 1 || postalClass > 7)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "\nError... Please enter valid data.";
                cout << "\nHow would you like to mail the package:\n 1. Priority Mail Express\n 2. Priority Mail\n 3. First-Class Mail\n 4. Periodicals";
                cout << "\n 5. USPS Marketing Mail\n 6. Package Services\n 7. USPS Retail Ground\n";
                cin >> postalClass;
            }

            package newPackage(destination, address, city, state, zipCode, postalClass); // Creates a newPackag.

            packages.enqueue(newPackage); // Adds the package to a queue.

        }
        else if (choice == 2) // If the user is done using the program.
        {
            isDone = true;
        }
    }

    for (int i = 0; i < 8; i++) // Sorts the queue based on the postalClass. We do "i < 8" since we have 7 different options for postal class.
    {
        packagesTemp = packages; // Copies packages to packagesTemp.

        while (!packagesTemp.isEmptyQueue())
        {
            if (packagesTemp.front().getPostalClass() == i)
            {
                packagesSorted.enqueue(packagesTemp.front());
            }
            packagesTemp.dequeue();
        }
    }

    while(!packagesSorted.isEmptyQueue()) // Outputs all information stored.
    {
        cout << packagesSorted.front();
        packagesSorted.dequeue();
    }

    return 0;
}