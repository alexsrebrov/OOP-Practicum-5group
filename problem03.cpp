#include<iostream>
#include<fstream>

const int MAX_SIZE=100;

enum Position {
    SOFTWARE_ENGINEER,
    SENIOR_SOFTWARE_ENGINEER,
    ENGINEER_MANAGER,
    LEAD_SOFTWARE_ENGINEER
};

struct Employee {
    char name[MAX_SIZE];
    Position position;
    double salary;
    int grade;
};

void writeEmployeeToFile(std::ofstream& file,Employee& e) {
    file << e.name <<std::endl;
    file << e.position << std::endl;
    file << e.salary << std::endl;
    file << e.grade << std::endl;
}

void readEmployeeFromFile(std::ifstream& file,Employee& e) {
    file.getline(e.name,MAX_SIZE);
    int pos;
    file >> pos;
    e.position=(Position)pos;
    file >> e.salary;
    file >> e.grade;
    file.ignore();
}

void readEmployee(Employee& n) {
    std::cin.getline(n.name,MAX_SIZE);
    int pos;
    std::cin>>pos;
    n.position=(Position)pos;
    std::cin>>n.salary;
    std::cin>>n.grade;
    std::cin.ignore();
}

void printEmployeeInfo(Employee n) {
    std::cout<<"Name:"<<n.name<<std::endl;
    std::cout<<"Position:"<<n.position<<std::endl;
    std::cout<<"Salary:"<<n.salary<<std::endl;
    std::cout<<"Grade:"<<n.grade<<std::endl;
}

struct Company {
    int employeeCount;
    Employee employees[MAX_SIZE];
    double avrgSalary;
};

void printCompanyInfo(Company& c) {
    std::cout<<"Numbers of empoloyees:"<<c.employeeCount<<std::endl;
    std::cout<<"Averege Salary:"<<c.avrgSalary<<std::endl;
    for (int i=0; i<c.employeeCount; ++i) {
        printEmployeeInfo(c.employees[i]);
        std::cout<<std::endl;
    }
}

void readCompany(Company& c) {
    std::cin>>c.employeeCount;
    std::cin.ignore();
    for (int i=0; i<c.employeeCount; ++i) {
        readEmployee(c.employees[i]);
    }
    double sum=0;
    for (int i=0; i<c.employeeCount; ++i) {
        sum+=c.employees[i].salary;
    }
    c.avrgSalary=sum/c.employeeCount;
}

class CompanySerializer {
public:
    void writeCompanyToFile(std::ofstream& file,Company& c) {
        file << c.employeeCount <<std::endl;
        file << c.avrgSalary<<std::endl;
        for (int i=0; i<c.employeeCount; ++i) {
            writeEmployeeToFile(file,c.employees[i]);
        }
    }

    void readCompanyFromFile(std::ifstream& file,Company& c) {
        file >> c.employeeCount;
        file >> c.avrgSalary;
        file.ignore();
        for (int i=0; i<c.employeeCount; ++i) {
            readEmployeeFromFile(file,c.employees[i]);
        }
    }

    void save(Company& c,const char* fileName) {
        std::ofstream file(fileName);
        if (!file.is_open()) {
            return;
        }
        writeCompanyToFile(file,c);
        file.close();
    }

    void load(Company& c,const char* fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            return;
        }
        readCompanyFromFile(file,c);
        file.close();
    }
};

int main() {
    Company c,loaded;
    readCompany(c);
    printCompanyInfo(c);
    CompanySerializer cs;
    cs.save(c,"ITCompany.txt");
    cs.load(loaded,"ITCompany.txt");
    printCompanyInfo(loaded);

}