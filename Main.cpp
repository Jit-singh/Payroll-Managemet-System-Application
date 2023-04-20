// Developed an application that implements the features of a Payroll Management System.

#include "employer.cpp"
using namespace std;

int main(){

    // Employer Details

    Employer employer1;

    string employerName, employerBand, employerLocation;
    cout << "Enter employer name : ";
    getline(cin>>ws, employerName);
    employer1.companyName = employerName;

    while(true){
        cout << "Enter employer locations : ";
        getline(cin>>ws, employerLocation);
        employer1.companyLocations.push_back(employerLocation);
        int n;
        cout << "Press 1 to add a employer locations or Press any key to continue : ";
        cin >> n;
        if(n!=1){
            break;
        }
    }

    while(true){
        cout << "Enter employer band : ";
        getline(cin>>ws, employerBand);
        employer1.companyBands.push_back(employerBand);
        int n;
        cout << "Press 1 to add a employer locations or Press any key to continue : ";
        cin >> n;
        if(n!=1){
            break;
        }
    }

    // Employee Details
    bool exit;
	while(exit!=true){
        employer1.displayEmployerDetails();
        employer1.displayMenu();

        int opt;
		cout << "Select a option: ";
		cin >> opt;
		
        switch(opt){
            case 1: {
                employer1.addNewEmployee();
                break;
            }

            case 2: {
                employer1.generateSalarySlip();
                break;
            }

            case 3: {
                employer1.modifyEmployeeDetails();
                break;
            }

            case 4: {
                employer1.removeEmployee();
                break;
            }

            case 5: {
                employer1.searchEmployee();
                break;
            }

            case 6: {
                employer1.displayAllEmployeeDetails();
                break;
            }

            case 7: {
                employer1.displayAllSalarySlips();
                break;
            }

            case 8: {
                cout << "\n---------------- Thank You -----------------\n\n";
                exit = true;
                break;
            }
            
            default: {
                cout << "\n\t !!! Invalid Input !!!\n\n";
                break;
            }
		};
        cout << endl;
	}
    return 0;
}
