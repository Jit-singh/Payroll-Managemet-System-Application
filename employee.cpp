#include<bits/stdc++.h>
using namespace std;

// define a structure for employee address
struct EmployeeAddress{
    string houseNum;
    string street;
    string area;
    string city;
    string pincode;
};

// define a structure for employee salary slip
struct PaySlip{
    public:
    string date;
    float basic;
    float variable;
    float pf;
    float allowance;
    float incometax;
    float messBill;
    float netPay;
    float grossPay;
};

class Employee {
    string name;
    string gender;
    string location;
    string employeeType;
    string band;
    string bankAccNum;
    float ctc;

    public: 
        // Default constructor
        Employee() = default;
        
        // Address object
        EmployeeAddress address;
        
        // Constructor with parameters
        Employee(string name, string gender, string houseNum, string street, string area, string city, string pincode, 
            string location, string employeeType, string band, string bankAccNum, float ctc){
                
            this->name = name;
            this->gender = gender;
            address.houseNum = houseNum;
            address.street = street;
            address.area = area;
            address.city = city;
            address.pincode = pincode;
            this->location = location;
            this->employeeType = employeeType;
            this->band = band;
            this->bankAccNum = bankAccNum;
            this->ctc = ctc;
        }

        // Setter methods for all data members
        void setName(string name){ 
            this->name = name; 
        }
        void setGender(string gender){ 
            this->gender = gender; 
        }
        void setAddress(string houseNum, string street, string area, string city, string pincode){
            address.houseNum = houseNum;
            address.street = street;
            address.area = area;
            address.city = city;
            address.pincode = pincode;
        }
        void setLocation(string location){ 
            this->location = location; 
        }
        void setEmployeeType(string employeeType){ 
            this->employeeType = employeeType; 
        }
        void setBand(string band){ 
            this->band = band; 
        }
        void setBankAccNum(string bankAccNum){ 
            this->bankAccNum = bankAccNum; 
        }
        void setCTC(float ctc){ 
            this->ctc = ctc; 
        }

        // Getter methods for all data members
        string getName(){ 
            return name; 
        }
        string getGender(){ 
            return gender; 
        }
        EmployeeAddress getAddress(){ 
            return address; 
        }
        string getLocation(){ 
            return location; 
        }
        string getEmployeeType(){ 
            return employeeType; 
        }
        string getBand(){ 
            return band; 
        }
        string getBankAccNum(){ 
            return bankAccNum; 
        }
        float getCTC(){ 
            return ctc; 
        }

        // contain all parameters of generated salary slip using vector of type payslip structure
        vector<PaySlip> listAllSalarySlips;
        
};