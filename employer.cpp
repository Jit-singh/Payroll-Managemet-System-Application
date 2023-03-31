#include "employee.cpp"
using namespace std;

class Employer {
    public:
    string companyName = "Sasken Technologies Private Limited";
    vector<string> companyLocations = {"Banglore", "Channai", "Pune", "Kolkata"};
    vector<string> companyBands = {"GT", "E1", "E2", "E3", "L1", "L2", "L3"};
    vector<string> companyDepartments = {"SEC", "SatComm", "Devices", "RAN"};
    int employeeID=0;

    map<int, Employee> employeeDetails;
    map<int, Employee>:: iterator itr;

    void displayMenu();

    void addNewEmployee();

    // void modifyMenu();
    void modifyEmployeeDetails();

    // void removeEmployee();
    // void searchEmployee();
    void displayAllEmployeeDetails();

};

void Employer :: displayMenu(){
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

void Employer :: addNewEmployee(){
    string name;
    string gender;
    string location;
    string department;
    string employeeType;
    string band;
    string PF_num;
    string bankAccNum;
    float ctc;

    cout << "Enter employee name: "; getline(cin>>ws, name);
    cout << "Enter employee gender: "; getline(cin>>ws, gender);
    cout << "Enter employee job location: "; getline(cin>>ws, location);
    cout << "Enter employee department: "; getline(cin>>ws, department);
    cout << "Enter employee type [Permanent/ Part-time/ contractor]: "; getline(cin>>ws, employeeType);
    cout << "Enter employee band: "; getline(cin>>ws, band);
    cout << "Enter employee PF number: "; getline(cin>>ws, PF_num);
    cout << "Enter employee bank account number: "; getline(cin>>ws, bankAccNum);
    cout << "Enter employee CTC: "; cin >> ctc;

    Employee emp(name, gender, location, department, employeeType, band, PF_num, bankAccNum, ctc);
    employeeID++;

    employeeDetails.insert({employeeID, emp});
    
}

void Employer :: displayAllEmployeeDetails(){
    if(employeeDetails.size()==0){
        cout << "Sorry! List is Empty." << endl;
    }
    else{
        cout << "\n--------- Display Employee Details ---------\n\n";
        for(itr=employeeDetails.begin(); itr!=employeeDetails.end(); itr++){
            cout << "\t\tEmployee ID " << (*itr).first << endl;
            cout << "Employee name \t\t\t:" << (*itr).second.getName() << endl;
            cout << "Employee gender \t\t:" << (*itr).second.getGender() << endl;
            cout << "Employee job location \t\t:" << (*itr).second.getLocation() << endl;
            cout << "Employee department \t\t:" << (*itr).second.getDepartment() << endl;
            cout << "Employee type \t\t\t:" << (*itr).second.getEmployeeType() << endl;
            cout << "Employee band \t\t\t:" << (*itr).second.getBand() << endl;
            cout << "Employee PF number \t\t:" << (*itr).second.getPF_num() << endl;
            cout << "Employee bank account number \t:" << (*itr).second.getBankAccNum() << endl;
            cout << "Employee CTC \t\t\t:" << (*itr).second.getCTC() << endl << endl;
        }
    }
}


void modifyMenu(){
    cout << "\n-------------- What to change --------------\n\n";
    cout << "Press 1. For change in employee name" << endl;
    cout << "Press 2. For change in employee address" << endl;
    cout << "Press 3. For change in employee location" << endl;
    cout << "Press 4. For change in employee department" << endl;
    cout << "Press 5. For change in employee type" << endl;
    cout << "Press 6. For change in employee band" << endl;
    cout << "Press 7. For change in employee bank account number" << endl;
    cout << "Press 8. For change in employee CTC" << endl;
    cout << "Press 9. For no change or exit" << endl << endl;
}

void Employer :: modifyEmployeeDetails(){
    if(employeeDetails.size()==0){
        cout << "Sorry! List is Empty." << endl;
    }
    else{
        cout << "\n---------- Modify Employee Details ---------\n\n";
        cout << "Enter employee ID : ";
        int id;
        cin >> id;

        if(employeeDetails.find(id) == employeeDetails.end()){
            cout << "Employee of ID " << id << " doesn't exist." << endl;
        }
        else{
            bool out=false;
            while(!out){
                modifyMenu();
                cout << "Choose an option to changes for: ";
                int opt;
                cin >> opt;

                switch(opt){
                    case 1: {
                        string changedName;
                        cout << "Enter a new name: ";
                        getline(cin>>ws, changedName);
                        employeeDetails[id].setName(changedName);
                        cout << "Name has changed successfully..." << endl;
                        modifyMenu();
                        break;
                    }

                    case 2: {
                        cout << "Not Avaliable now..." << endl;
                        break;
                    }
                    
                    case 3: {
                        string changedLocation;
                        cout << "Enter new location: ";
                        getline(cin>>ws, changedLocation);
                        employeeDetails[id].setLocation(changedLocation);
                        cout << "Location has changed successfully..." << endl;
                        break;
                    }

                    case 4: {
                        string changedDepartment;
                        cout << "Enter new department: ";
                        getline(cin>>ws, changedDepartment);
                        employeeDetails[id].setDepartment(changedDepartment);
                        cout << "Department has changed successfully..." << endl;
                        break;
                    }

                    case 5: {
                        string changedEmpType;
                        cout << "Enter new employement type: ";
                        getline(cin>>ws, changedEmpType);
                        employeeDetails[id].setEmployeeType(changedEmpType);
                        cout << "Employement type has changed successfully..." << endl;
                        break;
                    }

                    case 6: {
                        string changedBand;
                        cout << "Enter new Band: ";
                        getline(cin>>ws, changedBand);
                        employeeDetails[id].setBand(changedBand);
                        cout << "Band has changed successfully..." << endl;
                        break;
                    }

                    case 7: {
                        string changedBankAccNum;
                        cout << "Enter new bank account number: ";
                        getline(cin>>ws, changedBankAccNum);
                        employeeDetails[id].setBankAccNum(changedBankAccNum);
                        cout << "Bank account number has changed successfully..." << endl;
                        break;
                    }

                    case 8: {
                        float changedCTC;
                        cout << "Enter new CTC: ";
                        cin >> changedCTC;
                        employeeDetails[id].setCTC(changedCTC);
                        cout << "CTC has changed successfully..." << endl;
                        break;
                    }

                    case 9: {
                        cout << "\n Employee Details Successfully changed \n\n";
                        out=true;
                        break;
                    }
                    default: {
                        cout << "\n Invalid input! Please try again...\n";
                        break;
                    }
                }
            }
        }
    }
}


/*

/////// Generate pay slip

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

*/