#include<iostream>
#include<fstream>

const int MAX_SIZE=1024;

enum class currency {
    EUR,
    USD,
    ARS,
    GBP,
    BTC
};

class BankAccount {
    char name[MAX_SIZE];
    double balance;
    char IBAN[MAX_SIZE];
public:

    void addBankAccount() {
        std::cout<<"Name:";
        std::cin.getline(name,MAX_SIZE);
        std::cout<<"Balance:";
        std::cin>>balance;
        std::cin.ignore();
        std::cout<<"IBAN:";
        std::cin.getline(IBAN,MAX_SIZE);
        std::cout<<std::endl;
    }

    double withdraw(double amount) {
        if (amount<0 || amount>balance) {
            return balance;
        }
        balance-=amount;
        return balance;
    }

    double deposit(double amount) {
        if (amount<0) {
            return balance;
        }
        balance+=amount;
        return balance;
    }

    void showBalance(currency c = currency::EUR) const {
        switch (c) {
            case currency::EUR : std::cout<<"Balance is:"<<balance<<" EUR"; break;
            case currency::USD : std::cout<<"Balance is:"<<balance*1.178<<" USD"; break;
            case currency::ARS : std::cout<<"Balance is:"<<balance*1626<<" ARS"; break;
            case currency::GBP : std::cout<<"Balance is:"<<balance*0.872<<" GBP"; break;
            case currency::BTC : std::cout<<"Balance is:"<<balance*0.000016<<" BTC"; break;
            default: std::cout<<"Balance is:"<<balance<<" EUR"; break;
        }
        std::cout<<std::endl;
    }

    void writeToFile(std::ofstream& file) const {
        file << name <<std::endl;
        file << IBAN <<std::endl;
        file << balance <<std::endl;
    }

    void readFromFile(std::ifstream& file) {
        file.getline(name,MAX_SIZE);
        file.getline(IBAN,MAX_SIZE);
        file >> balance;
    }
};

class BankAccountSerializer {
public:

    void save(const BankAccount& b, const char* fileName) {
        std::ofstream file(fileName);
        if (!file.is_open()) {
            return;
        }
        b.writeToFile(file);
        file.close();
    }

    void read(BankAccount& b, const char* fileName) {
        std::ifstream file(fileName);
        if (!file.is_open()) {
            return;
        }
        b.readFromFile(file);
        file.close();
    }

};

int main(){
 BankAccount acc;
 acc.addBankAccount();
 acc.deposit(500);
 acc.withdraw(200);
 acc.showBalance();
 acc.showBalance(currency::BTC);
 BankAccountSerializer serializer;
 serializer.save(acc,"info.txt");
 BankAccount loaded;
 serializer.read(loaded,"info.txt");
 loaded.showBalance();
}