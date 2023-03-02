#include "employer.cpp"
using namespace std;

int main(){

    cout << "\n------------- Employer Details -------------\n\n";
    employer empr;

    string companyName;
    vector<string> allLocations;
    vector<string> allBands;
    vector<string> allDepartments;

    cout << "Enter Company name: ";
    getline(cin>>ws, companyName);
    
    cout << "Enter all locations of the company :- " << endl;
    int input=0;
    while(true){
        if(input==0){
            string loc;
            cout << "Enter a location: ";
            getline(cin>>ws, loc);
            allLocations.push_back(loc);
        }
        else if(input==1){
            break;
        }
        else{
            cout << "!!! Invalid Input !!!" << endl;
        }
        cout << "For enter a new location press 0 otherwise press 1: ";
        cin >> input;
    }
    cout << endl;

    cout << "Enter all available bands :- " << endl;
    input=0;
    while(true){
        if(input==0){
            string band;
            cout << "Enter a band: ";
            getline(cin>>ws, band);
            allBands.push_back(band);
        }
        else if(input==1){
            break;
        }
        else{
            cout << "!!! Invalid Input !!!" << endl;
        }
        cout << "For enter a new band press 0 otherwise press 1: ";
        cin >> input;
    }
    cout << endl;

    cout << "Enter all Departments:- " << endl;
    input=0;
    while(true){
        if(input==0){
            string department;
            cout << "Enter a department: ";
            getline(cin>>ws, department);
            allDepartments.push_back(department);
        }
        else if(input==1){
            break;
        }
        else{
            cout << "!!! Invalid Input !!!" << endl;
        }
        cout << "For enter a new department press 0 otherwise press 1: ";
        cin >> input;
    }
    cout << endl << endl;

    Employer employer1(companyName, allLocations, allBands, allDepartments);

    cout << employer1.companyName << endl;
    for(int i=0; i<employer1.companyLocations.size(); i++){
        cout << employer1.companyLocations[i] << "/ " ;
    }
    cout << endl;
    for(int i=0; i<employer1.companyBands.size(); i++){
        cout << employer1.companyBands[i] << "/ " ;
    }
    cout << endl;
    for(int i=0; i<employer1.companyDepartments.size(); i++){
        cout << employer1.companyDepartments[i] << "/ " ;
    }
    cout << endl;


    //------------------------------- Select menu options
    displayMenu();

    employee user1;
    bool exit;
	int opt;
	while(exit!=true){
		cout << "Select a option: ";
		cin >> opt;
		switch(opt){
            case 1: {
                cout << ".....Not availible yet. Try another option.\n\n";
                break;
            }

            case 2: {
                cout << ".....Not availible yet. Try another option.\n\n";
                break;
            }

            case 3: {
                cout << ".....Not availible yet. Try another option.\n\n";
                break;
            }

            case 4: {
                cout << ".....Not availible yet. Try another option.\n\n";
                break;
            }

            case 5: {
                cout << "\n------------- Employees Details ------------\n\n";
                string str;
                float ctc;
                vector<string> str1;

                ifstream in("Input.txt");

                cout << "Name: ";
                getline(in, str);
                user1.setName(str);
                cout << user1.getName() << endl;

                cout << "Gender: ";
                getline(in, str);
                user1.setGender(str);
                cout << user1.getGender() << endl;

                cout << "Addres :- " << endl;
                for(int i=0; i<5; i++){
                    getline(in, str);
                    str1.push_back(str);
                }
                user1.Address(str1[0], str1[1], str1[2], str1[3], str1[4]);

                cout << "Base Location: ";
                getline(in, str);
                user1.setLocation(str);
                cout << user1.getLocation() << endl;

                cout << "Employee ID: ";
                getline(in, str);
                user1.setEmpID(str);
                cout << user1.getEmpID() << endl;

                cout << "Department: ";
                getline(in, str);
                user1.setDepartment(str);
                cout << user1.getDepartment() << endl;

                cout << "Employment types: ";
                cout << "Permanent /Part-time /Contractor" << endl;
                getline(in, str);
                user1.setEmpType(str);
                cout <<"Select any one type: " << user1.getEmpType() << endl;

                cout << "Band: ";
                getline(in, str);
                user1.setBand(str);
                cout << user1.getBand() << endl;

                cout << "PF number: ";
                getline(in, str);
                user1.setPfNo(str);
                cout << user1.getPfNo() << endl;

                cout << "Bank Account Number: ";
                getline(in, str);
                user1.setBankAccNo(str);
                cout << user1.getBankAccNo() << endl;

                cout << "CTC (per Annum): ";
                in >> ctc;
                user1.setCTC(ctc);
                printf("%0.2f\n", user1.getCTC());
                cout << "-------------------------------------------\n\n";
                break;
            }

            case 6: {
                cout << ".....Not availible yet. Try another option.\n\n";
                break;
            }

            case 7: {
                float ctc, basic, vpp, pf, incometax, allowance, messBill, net, gross;
                ctc = user1.getCTC();
                basic = (ctc * 0.6) / 12;
                vpp = (ctc * 0.3) / 12;
                pf = (ctc * 0.05) / 12;
                allowance = (ctc * 0.05) / 12;

                // if(ctc < 500000){
                //     incometax = 0;
                // } else if(ctc>=500000 && ctc<=1000000){
                //     incometax = (ctc)
                // }

                // cout << "Enter mess bill amount : ";
                // cin >> messBill;

                gross = basic + vpp + pf + allowance;
                // net = gross - incometax - messBill;



                cout << "\n---------------- Salary slip ---------------\n\n";
                printf("Total CTC : %0.2f\n", ctc);
                printf("Basic salary : %0.2f\n", basic);
                printf("Variable pay : %0.2f\n", vpp);
                printf("Provident fund : %0.2f\n", pf);
                printf("Other allowance : %0.2f\n", allowance);
                // printf("Income tax : %0.2f\n", (user1.getCTC())*(0.6/12));
                // printf("Mess bill : %0.2f\n", messBill);
                // printf("Net pay : %0.2f\n", (user1.getCTC())*(0.6/12));
                printf("Gross pay : %0.2f\n", gross);
                cout << "-------------------------------------------\n\n";
                break;
            }

            case 8: {
                cout << "\n---------------- Thank You -----------------\n\n";
                exit = true;
                break;
            }
            
            default: {
                cout << ".....Enter a valid input.\n\n";
                displayMenu();
                break;
            }
		};
	}
    return 0;
}

void displayMenu(){
    cout << "\n-------------------- Menu ------------------\n\n";
    cout << "1. Add a new employee" << endl;
    cout << "2. Modify employee details" << endl;
    cout << "3. Remove an employee" << endl;
    cout << "4. Search an employee" << endl;
    cout << "5. Print all the employee details" << endl;
    cout << "6. Generate pay slip" << endl;
    cout << "7. Exit" << endl;
    cout << "\n--------------------------------------------\n\n";
}