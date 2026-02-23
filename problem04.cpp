#include<iostream>

const int MAX_SIZE=1024;

class Student {
    char name[MAX_SIZE];
    char fn[MAX_SIZE];
    char password[MAX_SIZE];

public:

    int strlen(char* arr) {
        int len=0;
        while (*arr) {
            arr++;
            len++;
        }
        return len;
    }

    bool checkPassword(char* pass,char* check) {
        while (*pass) {
            if (*pass!=*check) {
                return 0;
            }
            pass++;
            check++;
        }
        return *check=='\0';
    }

    void printInfo(Student s) {
        std::cout<<s.name<<std::endl;
        std::cout<<s.fn<<std::endl;
    }

    void newPassword(Student& s,char* oldPass,char* newPass) {
        if (checkPassword(s.password,oldPass)) {
            int newPassLen=strlen(newPass);
            for (int i=0; i<newPassLen; ++i){
                s.password[i]=newPass[i];
            }
            s.password[newPassLen]='\0';
        }
        else {
            std::cout<<"Wrong pass";
        }
    }
};
int main() {

}