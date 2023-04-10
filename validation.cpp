#include <iostream>
#include <string>
#include <vector>

using namespace std;

// validation of gender entered by user
bool validateGender(string gender){
    if(gender == "male" || gender == "MALE" || gender == "female" || gender == "FEMALE"){
        return true;
    }
    cout << "Gender can be either male or female..." << endl;
    return false;
}

// validation of house number entered by user
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
            cout << "House numbers can only contain numbers and '/'" << endl;
            return false;
        }
    }
    return true;
}

// validation of pincode entered by user
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

// validation of job location entered by user
bool validateLocation(vector<string> allLocations, string location){
    for(int i=0; i<allLocations.size(); i++){
        if(allLocations[i]==location){
            return true;
        }
    }
    cout << "Invalid location! Please enter correct location..." << endl;
    return false;
}

// validation of types of employement
bool validateEmplyeeType(vector<string> allEmployementTypes, string employeeType){
    for(int i=0; i<allEmployementTypes.size(); i++){
        if(allEmployementTypes[i]==employeeType){
            return true;
        }
    }
    cout << "Invalid employement type! Please enter correct employement type..." << endl;
    return false;
}

bool validateEmplyeeBand(vector<string> companyBands, string employeeBand){
    for(int i=0; i<companyBands.size(); i++){
        if(companyBands[i]==employeeBand){
            return true;
        }
    }
    cout << "Invalid employement band! Please enter correct employement band.." << endl;
    return false;
}

// validation of month entered by user
bool validationMonth(string month){
    if(month == "january" || month == "february" || month == "march" || month == "april" || month == "may" || month == "june" ||
         month == "july" || month == "august" || month == "september" || month == "october" || month == "november" || month == "december"){
        return true;
    }
    return false;
}

