// Developed an application that implements the features of a Payroll Management System.

#include "employer.cpp"
using namespace std;

int main(){

    // Employer Details

    Employer employer1;

    employer1.inputEmployerDetails();
    employer1.displayEmployerDetails();

    // Employee Details
    bool exit;
	while(exit!=true){
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
