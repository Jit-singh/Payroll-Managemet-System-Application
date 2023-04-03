#include<bits/stdc++.h>
using namespace std;

struct EmployeeAddress{
    int doorNum;
    string street;
    string area;
    string city;
    int pincode;
};

class Employee {
    string name;
    string gender;
    string location;
    string department;
    string employeeType;
    string band;
    string PF_num;
    string bankAccNum;
    float ctc;

    public: 
        Employee() = default;
        
        EmployeeAddress address;
        
        Employee(string name, string gender, int doorNum, string street, string area, string city, int pincode, string location, string department, string employeeType, string band, string PF_num, string bankAccNum, float ctc){
            this->name = name;
            this->gender = gender;
            address.doorNum = doorNum;
            address.street = street;
            address.area = area;
            address.city = city;
            address.pincode = pincode;
            this->location = location;
            this->department = department;
            this->employeeType = employeeType;
            this->band = band;
            this->PF_num = PF_num;
            this->bankAccNum = bankAccNum;
            this->ctc = ctc;
        }

        //--------------------------------------- setters

        void setName(string name){ this->name = name; }
        void setGender(string gender){ this->gender = gender; }
        void setAddress(int doorNum, string street, string area, string city, int pincode){
            address.doorNum = doorNum;
            address.street = street;
            address.area = area;
            address.city = city;
            address.pincode = pincode;
        }
        void setLocation(string location){ this->location = location; }
        void setDepartment(string department){ this->department = department; }
        void setEmployeeType(string employeeType){ this->employeeType = employeeType; }
        void setBand(string band){ this->band = band; }
        void setPF_num(string PF_num){ this->PF_num = PF_num; }
        void setBankAccNum(string bankAccNum){ this->bankAccNum = bankAccNum; }
        void setCTC(float ctc){ this->ctc = ctc; }

        //--------------------------------------- getters
        string getName(){ return name; }
        string getGender(){ return gender; }
        EmployeeAddress getAddress(){ return address; }
        string getLocation(){ return location; }
        string getDepartment(){ return department; }
        string getEmployeeType(){ return employeeType; }
        string getBand(){ return band; }
        string getPF_num(){ return PF_num; }
        string getBankAccNum(){ return bankAccNum; }
        float getCTC(){ return ctc; }
};
