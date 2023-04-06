#include "employer.cpp"
using namespace std;

int main(){

    Employer employer1;
    cout << "\n------------- Employer Details -------------\n\n";
    cout << employer1.companyName << endl << endl;

    cout << "All Locations : ";
    for(int i=0; i<employer1.companyLocations.size(); i++){
        cout << employer1.companyLocations[i];
        if(i+1 != employer1.companyLocations.size()){
            cout << "/ ";
        }
    }
    cout << endl;

    cout << "All Bands : ";
    for(int i=0; i<employer1.companyBands.size(); i++){
        cout << employer1.companyBands[i];
        if(i+1 != employer1.companyBands.size()){
            cout << "/ ";
        }
    }
    cout << endl;

    cout << "All Departments : ";
    for(int i=0; i<employer1.companyDepartments.size(); i++){
        cout << employer1.companyDepartments[i];
        if(i+1 != employer1.companyDepartments.size()){
            cout << "/ ";
        }
    }
    cout << endl;

    //----------------------------------------------------------------
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
                employer1.modifyEmployeeDetails();
                break;
            }

            case 3: {
                employer1.removeEmployee();
                break;
            }

            case 4: {
                employer1.searchEmployee();
                break;
            }

            case 5: {
                
                employer1.displayAllEmployeeDetails();
                break;
            }

            case 6: {
                cout << "Not availible yet. Try another option.\n\n";
                break;
            }

            case 7: {
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
