#include "employee.cpp"
#include "validation.cpp"

using namespace std;

class Employer {
    public:
    string companyName;
    vector<string> companyLocations;
    vector<string> companyBands;
    vector<string> allEmployementTypes = {"permanent", "part-time", "contract"};
    int employeeID=0;

    map<int, Employee> employeeDetails;
    map<int, Employee>:: iterator itr;

    void displayEmployerDetails();
    void displayMenu();
    void generateSalarySlip();
    void addNewEmployee();
    void modifyEmployeeDetails();
    void removeEmployee();
    void searchEmployee();
    void displayAllEmployeeDetails();
    void displayAllSalarySlips();
};

void Employer :: displayEmployerDetails(){
    cout << "\n------------- Employer Details -------------\n\n";
    
    cout << companyName << endl << endl;

    cout << "All company locations : " << endl;
    for(int i=0; i<companyLocations.size(); i++){
        cout << "\t[" << i+1 << "]. " << companyLocations[i] << endl;
    }
    
    cout << "All company bands : " << endl;
    for(int i=0; i<companyBands.size(); i++){
        cout << "\t[" << i+1 << "]. " << companyBands[i] << endl;
    }
    cout << endl;
}

void Employer :: displayMenu(){
    cout << "\n-------------------- Menu ------------------\n";
    cout << "1. Add a new employee" << endl;
    cout << "2. Generate pay slip" << endl;
    cout << "3. Modify employee details" << endl;
    cout << "4. Remove an employee" << endl;
    cout << "5. Search an employee" << endl;
    cout << "6. Print all the employee details" << endl;
    cout << "7. Print all salary slips of an employee" << endl;
    cout << "8. Exit" << endl;
    cout << "--------------------------------------------\n\n";
}

void Employer :: addNewEmployee(){
    string name;
    string gender;
    string houseNum;
    string street;
    string area;
    string city;
    string pincode;
    string location;
    string employeeType;
    string band;
    string bankAccNum;
    float ctc;

    cout << endl << "Fill up the employee details correctly to add in employee list." << endl << endl;

    cout << "Enter employee name: ";
    getline(cin>>ws, name);

    inputGenderAgain:
    cout << "Enter employee gender: "; 
    getline(cin>>ws, gender);
    if(!validateGender(gender)){
        goto inputGenderAgain;
    }

    cout << "Now enter the address details -\n";

    inputHouseNumAgain:
    cout << "Enter house number: "; 
    cin >> houseNum;
    if(!validateHouseNumber(houseNum)){
        goto inputHouseNumAgain;
    }

    cout << "Enter street: "; 
    getline(cin>>ws, street);

    cout << "Enter area: "; 
    getline(cin>>ws, area);
    
    cout << "Enter city: "; 
    getline(cin>>ws, city);

    inputPincode:
    cout << "Enter pincode: "; 
    cin >> pincode;
    if(!validatePincode(pincode)){
        goto inputPincode;
    }

    //=======================================================
    cout << "All avaliable locations of company - " << endl;
    for(int i=0; i<companyLocations.size(); i++){
        cout << " [" << i+1 << "]. " << companyLocations[i] << endl;
    }
    inputLocation:
    cout << "Enter employee job location: "; 
    getline(cin>>ws, location);
    if(!validateLocation(companyLocations, location)){
        goto inputLocation;
    }

    //=======================================================
    cout << "All avaliable types of employement - " << endl;
    for(int i=0; i<allEmployementTypes.size(); i++){
        cout << " [" << i+1 << "]. " << allEmployementTypes[i] << endl;
    }
    inputEmployeeType:
    cout << "Choose any one type of employement: "; 
    getline(cin>>ws, employeeType);
    if(!validateEmployeeType(allEmployementTypes, employeeType)){
        goto inputEmployeeType;
    }

    //=======================================================
    cout << "All avaliable bands in company - " << endl;
    for(int i=0; i<companyBands.size(); i++){
        cout << " [" << i+1 << "]. " << companyBands[i] << endl;
    }
    inputEmployeeBand:
    cout << "Enter employee band: "; 
    getline(cin>>ws, band);
    if(!validateEmployeeBand(companyBands, band)){
        goto inputEmployeeBand;
    }

    //=======================================================
    cout << "Enter employee bank account number: "; 
    getline(cin>>ws, bankAccNum);

    cout << "Enter employee CTC: "; 
    cin >> ctc;

    Employee emp(name, gender, houseNum, street, area, city, pincode, location, employeeType, band, bankAccNum, ctc);
    employeeID++;

    employeeDetails.insert({employeeID, emp});
    
}

void Employer:: generateSalarySlip(){
    string monthOfPay;
    int empID;
    float messBill;
    string transferDate;

    cout << "Enter the salary month name : ";
    getline(cin>>ws, monthOfPay);

    if(validationMonth(monthOfPay)){
        cout << "Enter employee ID : ";
        cin >> empID;

        if(employeeDetails.size()==0){
            cout << "Sorry! List is empty...\nYou need to add an emplyee." << endl;
        }
        else{
            if(employeeDetails.find(empID) == employeeDetails.end()){
                cout << "Sorry! There is no any employee exist with ID " << empID << endl;
            }
            else{
                float ctc, monthlyCTC, basic, vpp, pf, incometax, allowance, netPay, grossPay;
                ctc = employeeDetails[empID].getCTC();
                monthlyCTC = ctc/12;

                cout << "Enter amount of mess bill : ";
                cin >> messBill;

                if(messBill > monthlyCTC){
                    cout << "Mess bill should be less than the monthly CTC " << monthlyCTC << endl;
                    cout << "Try again..." << endl;
                }
                else{

                    cout << "Enter date of salary transfer : ";
                    getline(cin>>ws, transferDate);

                    basic = (monthlyCTC * 0.6);
                    vpp = (monthlyCTC * 0.3);
                    pf = (monthlyCTC * 0.05);
                    allowance = (monthlyCTC * 0.05);

                    if(ctc < 500000){
                        incometax = 0;
                    }
                    else if(ctc>=500000 && ctc<=1000000){
                        incometax = (monthlyCTC * 0.05);
                    }
                    else if(ctc>=1000001 && ctc<=1500000){
                        incometax = (monthlyCTC * 0.1);
                    }
                    else if(ctc>=1500001 && ctc<=2000000){
                        incometax = (monthlyCTC * 0.15);
                    }
                    else {
                        incometax = (monthlyCTC * 0.2);
                    }

                    grossPay = basic + vpp + pf + allowance;
                    netPay = grossPay - incometax - messBill;

                    PaySlip salaryslip;

                    salaryslip.date = transferDate;
                    salaryslip.basic = basic;
                    salaryslip.variable = vpp;
                    salaryslip.pf = pf;
                    salaryslip.allowance = allowance;
                    salaryslip.incometax = incometax;
                    salaryslip.messBill = messBill;
                    salaryslip.grossPay = grossPay;
                    salaryslip.netPay = netPay;

                    employeeDetails[empID].listAllSalarySlips.push_back(salaryslip);

                    cout << endl;
                    printf("Basic pay \t\t: %0.2f\n", basic);
                    printf("Variable pay \t\t: %0.2f\n", vpp);
                    printf("Provident fund \t\t: %0.2f\n", pf);
                    printf("Other allowance \t: %0.2f\n", allowance);
                    printf("Income tax \t\t: %0.2f\n", incometax);
                    printf("Mess bill \t\t: %0.2f\n", messBill);
                    printf("Net pay  \t\t: %0.2f\n", netPay);
                    printf("Gross pay \t\t: %0.2f\n", grossPay);

                }
            }
        }
    }
    else{
        cout << "Enter a valid month name..." << endl << endl;
    }
}

void modifyMenu(){
    cout << "\n-------------- What to change --------------\n\n";
    cout << "Press 1. For change in employee name" << endl;
    cout << "Press 2. For change in employee address" << endl;
    cout << "Press 3. For change in employee location" << endl;
    cout << "Press 4. For change in employee type" << endl;
    cout << "Press 5. For change in employee band" << endl;
    cout << "Press 6. For change in employee bank account number" << endl;
    cout << "Press 7. For change in employee CTC" << endl;
    cout << "Press 8. For no change or exit" << endl << endl;
}

void Employer :: modifyEmployeeDetails(){
    if(employeeDetails.size()==0){
        cout << "Sorry! List is empty...\nYou need to add an emplyee." << endl;
    }
    else{
        cout << "\n---------- Modify Employee Details ---------\n\n";
        cout << "Enter employee ID : ";
        int id;
        cin >> id;

        if(employeeDetails.find(id) == employeeDetails.end()){
            cout << "Sorry! There is no any employee exist with ID " << id << endl;
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
                        string changedHouseNum;
                        string changedStreet;
                        string changedArea;
                        string changedCity;
                        string changedPincode;
                        cout << "Enter new house num: ";
                        cin >> changedHouseNum;
                        cout << "Enter new street: ";
                        getline(cin>>ws, changedStreet);
                        cout << "Enter new area: ";
                        getline(cin>>ws, changedArea);
                        cout << "Enter new city: ";
                        getline(cin>>ws, changedCity);
                        cout << "Enter new pincode: ";
                        cin >> changedPincode;

                        employeeDetails[id].setAddress(changedHouseNum, changedStreet, changedArea, changedCity, changedPincode);

                        cout << "Address has changed successfully..." << endl;

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
                        string changedEmpType;
                        cout << "Enter new employement type: ";
                        getline(cin>>ws, changedEmpType);
                        employeeDetails[id].setEmployeeType(changedEmpType);
                        cout << "Employement type has changed successfully..." << endl;
                        break;
                    }

                    case 5: {
                        string changedBand;
                        cout << "Enter new Band: ";
                        getline(cin>>ws, changedBand);
                        employeeDetails[id].setBand(changedBand);
                        cout << "Band has changed successfully..." << endl;
                        break;
                    }

                    case 6: {
                        string changedBankAccNum;
                        cout << "Enter new bank account number: ";
                        getline(cin>>ws, changedBankAccNum);
                        employeeDetails[id].setBankAccNum(changedBankAccNum);
                        cout << "Bank account number has changed successfully..." << endl;
                        break;
                    }

                    case 7: {
                        float changedCTC;
                        cout << "Enter new CTC: ";
                        cin >> changedCTC;
                        employeeDetails[id].setCTC(changedCTC);
                        cout << "CTC has changed successfully..." << endl;
                        break;
                    }

                    case 8: {
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

void Employer:: removeEmployee(){
    cout << "\n---------- Remove Employee Details ---------\n\n";
    cout << "Enter employee ID : ";
    int id;
    cin >> id;

    if(employeeDetails.size()==0){
        cout << "Sorry! List is empty...\nYou need to add an emplyee." << endl;
    }
    else{
        if(employeeDetails.find(id) == employeeDetails.end()){
            cout << "Sorry! There is no any employee exist with ID " << id << endl;
        }
        else{
            employeeDetails.erase(id);
            cout << "Employee details of ID " << id << " has deleted successfully..." << endl << endl;
        }
    }
}


void Employer:: searchEmployee(){
    cout << "\n---------- Search Employee Details ---------\n\n";
    cout << "Enter employee ID : ";
    int id;
    cin >> id;

    if(employeeDetails.size()==0){
        cout << "Sorry! List is empty...\nYou need to add an emplyee." << endl;
    }
    else{
        if(employeeDetails.find(id) == employeeDetails.end()){
            cout << "Sorry! There is no any employee exist with ID " << id << endl;
        }
        else{
            cout << "\n--------- Display Employee Details ---------\n\n";
            cout << "\t\tEmployee ID " << id << endl;
            cout << "Employee name \t\t\t: " << employeeDetails[id].getName() << endl;
            cout << "Employee gender \t\t: " << employeeDetails[id].getGender() << endl;
            cout << "Employee Address" << endl;
            cout << "   House number \t\t: " << employeeDetails[id].getAddress().houseNum << endl;
            cout << "   Street \t\t\t: " << employeeDetails[id].getAddress().street << endl;
            cout << "   Area \t\t\t: " << employeeDetails[id].getAddress().area << endl;
            cout << "   City \t\t\t: " << employeeDetails[id].getAddress().city << endl;
            cout << "   Pincode  \t\t\t: " << employeeDetails[id].getAddress().pincode << endl;
            cout << "Employee job location \t\t: " << employeeDetails[id].getLocation() << endl;
            cout << "Employee type \t\t\t: " << employeeDetails[id].getEmployeeType() << endl;
            cout << "Employee band \t\t\t: " << employeeDetails[id].getBand() << endl;
            cout << "Employee bank account number \t: " << employeeDetails[id].getBankAccNum() << endl;
            printf("Employee CTC \t\t\t: %0.2f", employeeDetails[id].getCTC());
            cout << endl << endl;
        }
    }   
}


void Employer :: displayAllEmployeeDetails(){
    if(employeeDetails.size()==0){
        cout << "Sorry! List is empty...\nYou need to add an emplyee." << endl;
    }
    else{
        cout << "\n--------- Display Employee Details ---------\n\n";
        for(itr=employeeDetails.begin(); itr!=employeeDetails.end(); itr++){
            cout << "\t\tEmployee ID " << (*itr).first << endl;
            cout << "Employee name \t\t\t: " << (*itr).second.getName() << endl;
            cout << "Employee gender \t\t: " << (*itr).second.getGender() << endl;
            cout << "Employee Address -" << endl;
            cout << "   House number \t\t: " << (*itr).second.getAddress().houseNum << endl;
            cout << "   Street \t\t\t: " << (*itr).second.getAddress().street << endl;
            cout << "   Area \t\t\t: " << (*itr).second.getAddress().area << endl;
            cout << "   City \t\t\t: " << (*itr).second.getAddress().city << endl;
            cout << "   Pincode  \t\t\t :" << (*itr).second.getAddress().pincode << endl;
            cout << "Employee job location \t\t: " << (*itr).second.getLocation() << endl;
            cout << "Employee type \t\t\t: " << (*itr).second.getEmployeeType() << endl;
            cout << "Employee band \t\t\t: " << (*itr).second.getBand() << endl;
            cout << "Employee bank account number \t: " << (*itr).second.getBankAccNum() << endl;
            printf("Employee CTC \t\t\t: %0.2f", (*itr).second.getCTC());
            cout << endl << endl;

        }
    }
}

void Employer :: displayAllSalarySlips(){
    cout << "\n--------- Display All Salary Slips ---------\n\n";
    cout << "Enter employee ID : ";
    int empId;
    cin >> empId;

    if(employeeDetails.size()==0){
        cout << "Sorry! List is empty...\nYou need to add an emplyee." << endl;
    }
    else{
        if(employeeDetails.find(empId) == employeeDetails.end()){
            cout << "Sorry! There is no any employee exist with ID " << empId << endl;
        }
        else{
            if(employeeDetails[empId].listAllSalarySlips.size()==0){
                cout << "Sorry! There is not present any salary slip. \nYou need to generate a salary slip." << endl;
            }
            else{
                vector<PaySlip>:: iterator it;
                for(it = employeeDetails[empId].listAllSalarySlips.begin(); it != employeeDetails[empId].listAllSalarySlips.end(); it++){
                    cout << "--------------------------------------------" << endl;
                    cout << "       salary date : " << (*it).date  << endl;
                    printf("Basic pay \t\t\t: %0.2f\n", (*it).basic);
                    printf("Variable pay \t\t\t: %0.2f\n", (*it).variable);
                    printf("Provident fund \t\t: %0.2f\n", (*it).pf);
                    printf("Other allowance \t\t: %0.2f\n", (*it).allowance);
                    printf("Income tax \t\t\t: %0.2f\n", (*it).incometax);
                    printf("Mess bill \t\t\t: %0.2f\n", (*it).messBill);
                    printf("Net pay  \t\t\t: %0.2f\n", (*it).netPay);
                    printf("Gross pay \t\t\t: %0.2f\n\n", (*it).grossPay);
                }
            }
        }
    }
}