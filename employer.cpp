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

void Employer :: modifyEmployeeDetails(){
    cout << "\n---------- Modify Employee Details ---------\n\n";
    cout << "Enter employee ID : ";
    int id;
    cin >> id;
    if(employeeDetails.find(id) == employeeDetails.end()){
        cout << "Employee of ID " << id << " doesn't exist." << endl;
    }
    else{
        while(true){
            string input;
            cout << "Do you want to change employee name [yes/ no] : ";
            getline(cin>>ws, input);
            if(input == "yes"){
                string changedName;
                cout << "Enter a new name: ";
                getline(cin>>ws, changedName);
                employeeDetails[id].setName(changedName);
                break;
            }
            else if(input == "no"){
                break;
            }
            else{
                cout << "Invalid input. Please enter yes or no." << endl << endl;
            }
        }
    }
}