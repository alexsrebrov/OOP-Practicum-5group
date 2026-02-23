#include<iostream>

const int MAX_SIZE=100;

enum Position {
    Software_Engineer,
    Senior_Software_Engineer,
    Engineer_Manager,
    Lead_Software_Engineer
};

struct Employee {
    char name[MAX_SIZE];
    Position position;
    double salary;
    int grade;
};

void readEmployee(Employee& n) {
    std::cin.getline(n.name,MAX_SIZE);
    int pos;
    std::cin>>pos;
    n.position=(Position)pos;
    std::cin>>n.salary;
    std::cin>>n.grade;
}

void printEmployeeInfo(Employee n) {
    std::cout<<"Name:"<<n.name<<std::endl;
    std::cout<<"Position:"<<n.position<<std::endl;
    std::cout<<"Salary:"<<n.salary<<std::endl;
    std::cout<<"Grade:"<<n.grade<<std::endl;
}

void changeSalary(Employee& n,double newS) {
    n.salary=newS;
}

void changeGrade(Employee& n,int newGrade) {
    n.grade=newGrade;
}

void changePosition(Employee& n,Position pos) {
    n.position=pos;
}

struct Company {
    int employeeCount;
    Employee employees[MAX_SIZE];
    double avrgSalary;
};

void readCompany(Company& c) {
    std::cin>>c.employeeCount;
    for (int i=0; i<c.employeeCount; ++i) {
        readEmployee(c.employees[i]);
    }
    double sum=0;
    for (int i=0; i<c.employeeCount; ++i) {
        sum+=c.employees[i].salary;
    }
    c.avrgSalary=sum/c.employeeCount;
}

void showEmployeesWithHigherSalaryThanAvrg(Company c) {
    for (int i=0; i<c.employeeCount; ++i) {
        if (c.employees[i].salary>c.avrgSalary) {
           std::cout<<c.employees[i].name<<std::endl;
        }
    }
}

void printLowestAndHighestGradeForEachPosition(Company c,Position p) {
    int min,max;
    for (int i=0; i<c.employeeCount; ++i) {
        if (c.employees[i].position==p){max=c.employees[i].grade; min=c.employees[i].grade; break;}
    }
    for (int i=0; i<c.employeeCount; ++i) {
        if (c.employees[i].position==p && c.employees[i].grade>max){max=c.employees[i].grade;}
        if (c.employees[i].position==p && c.employees[i].grade<min){min=c.employees[i].grade;}
    }
    std::cout<<max<<" "<<min;
}

void printAvrgSumForEachPosition(Company c,Position p) {
    double sum=0;
    double avrg=0;
    int employeesInPosition=0;
    for (int i=0; i<c.employeeCount; ++i) {
        if (c.employees[i].position==p) {
            employeesInPosition++;
            sum+=c.employees[i].salary;
        }
    }
    avrg=sum/employeesInPosition;
    std::cout<<avrg;
}

void printNamesInEachPosition(Company c,Position p) {
    for (int i=0; i<c.employeeCount; ++i) {
        if (c.employees[i].position==p) {
            std::cout<<c.employees[i].name<<std::endl;
        }
    }
}

void printNamesForGrades(Company c,int grade) {
   for (int i=0; i<c.employeeCount; ++i) {
       if (c.employees[i].grade==grade) {
           std::cout<<c.employees[i].name<<" "<<c.employees[i].grade<<std::endl;
       }
   }
}

void printNamesForSalary(Company c,double salary) {
    for (int i=0; i<c.employeeCount; ++i) {
        if (c.employees[i].salary==salary) {
            std::cout<<c.employees[i].name<<" "<<c.employees[i].salary<<std::endl;
        }
    }
}

int strcmp(char* str1,char* str2) {
    while (*str1 && *str2) {
        if (*str1>*str2) {
            return 1;
        }
        if (*str1<*str2) {
            return -1;
        }
        str1++;
        str2++;
    }
    if (*str1==*str2) {
        return 0;
    }
    if (*str1>*str2) {
        return 1;
    }
    return -1;
}

void swapEmployees(Employee& e1,Employee& e2) {
    Employee temp=e1;
    e1=e2;
    e2=temp;
}

void sortInAlphabeticalOrder(Employee* employees,int employeeCount) {
    for (int i=0; i<employeeCount-1; ++i) {
        for (int j=0; j<employeeCount-1-i; ++j) {
            if (strcmp(employees[j].name,employees[j+1].name)==1) {
                swapEmployees(employees[j],employees[j+1]);
            }
        }
    }
}

void SortEmployeesByPositionInAlphabeticalOrder(Company c,Position p) {
    sortInAlphabeticalOrder(c.employees,c.employeeCount);
    for (int i=0; i<c.employeeCount; ++i) {
        if (c.employees[i].position==p) {
            std::cout<<c.employees[i].name<<" "<<c.employees[i].position<<std::endl;
        }
    }
}

int main() {

}