#include <iostream>
#include <string>
#include <vector>

using namespace std;

// validation for gender entered by user
bool validateGender(string gender){
    if(gender == "male" || gender == "MALE" || gender == "female" || gender == "FEMALE"){
        return true;
    }
    cout << "Gender can be either male or female..." << endl;
    return false;
}

// validation for house number entered by user
bool validateHouseNumber(string houseNum){
    if(houseNum.size()==0 || houseNum[0]=='-' || houseNum[0]=='/'){
        cout << "House number cannot start from any special character..." << endl;
        return false;
    }
    for(int i=0;i<houseNum.size();i++){
        if(!isdigit(houseNum[i])){
            if(houseNum[i]=='/'){
                continue;
            }
            cout << "House number can only contain numbers and '/'" << endl;
            return false;
        }
    }
    return true;
}

// validation for pincode entered by user
bool validatePincode(string pincode){
    for(int i=0; i<pincode.length(); i++){
        if(!isdigit(pincode[i])){
            cout << "Pincode can only contain numbers..." << endl;
            return false;
        }
    }
    if(pincode[0]=='0'){
        cout << "Pincode can not start from zero..." << endl;
        return false;
    }
    if(pincode.length()!=6){
        cout << "Pincode must be of 6 digits only..." << endl;
        return false;
    }
    return true;
}

// validation for job location entered by user
bool validateLocation(vector<string> allLocations, string location){
    for(int i=0; i<allLocations.size(); i++){
        if(allLocations[i]==location){
            return true;
        }
    }
    cout << "Invalid location! Please enter correct location..." << endl;
    return false;
}

// validation for types of employement entered by user
bool validateEmployeeType(vector<string> allEmployementTypes, string employeeType){
    for(int i=0; i<allEmployementTypes.size(); i++){
        if(allEmployementTypes[i]==employeeType){
            return true;
        }
    }
    cout << "Invalid employement type! Please enter correct employement type..." << endl;
    return false;
}

// validation for band entered by user
bool validateEmployeeBand(vector<string> companyBands, string employeeBand){
    for(int i=0; i<companyBands.size(); i++){
        if(companyBands[i]==employeeBand){
            return true;
        }
    }
    cout << "Invalid employement band! Please enter correct employement band.." << endl;
    return false;
}

// validation for account number entered by user
//  (1) account number should contain only integer
//  (2) account number should have to 11 to 13 digits
//  (3) account number should not start with zero
bool validateAccountNumber(string AccountNum){
    if(AccountNum.size()==0 || AccountNum[0]=='0'){
        cout << "Account number cannot start with zero ..." << endl;
        return false;
    }
    if(AccountNum.size()<11 || AccountNum.size()>13){
        cout << "Total number of digits in a Account number should lie between 11 to 13 ..." << endl;
        return false;
    }
    for(int i=0;i<AccountNum.size();i++){
        if(!isdigit(AccountNum[i])){
            cout << "Account number can only contain integer values only ..." << endl;
            return false;
        }
    }
    return true;
}

// validation for month entered by user
bool validationMonth(string month){
    if(month == "january" || month == "february" || month == "march" || month == "april" || month == "may" || month == "june" ||
         month == "july" || month == "august" || month == "september" || month == "october" || month == "november" || month == "december"){
        return true;
    }
    return false;
}

// validation for date entered by user