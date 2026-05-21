#pragma once
#include <functional>
#include <sstream>
#include "InvalidCommand.h"
class Calculator
{
private:

    const double e = 2.72;
    std::function<double(double, double)> add = [](double a, double b) { return a + b; };
    std::function<double(double, double)> sub = [](double a, double b) { return a - b; };
    std::function<double(double, double)> mul = [](double a, double b) { return a * b; };

    std::function<double(double, double)> div = [](double a, double b) {
        if (b == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return a / b;
        };

    std::function<double(double, double)> pow = [](double a, double b) {
        double res = 1;
        for (int i = 0; i < b; i++)
        {
            res *= a;
        }
        return res;
        };
    std::function<double(double)> exp = [this](double num) { return pow(e, num); };

public:
    double evaluate(const std::string& commandLine){
        std::stringstream ss(commandLine);
        std::string label;
        ss >> label;
        double num1, num2;
        if (label == "add")
        {
            if (!(ss >> num1))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }

                throw std::invalid_argument("Instead of number a string is given");
            }

            if (!(ss >> num2))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }

                throw std::invalid_argument("Instead of number a string is given");
            }

            std::string extra;
            if (ss >> extra)
            {
                throw InvalidCommand("Too many arguments\n");
            }
          return add(num1, num2);
        }

        else if (label == "sub")
        {
            if (!(ss >> num1))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }

                throw std::invalid_argument("Instead of number a string is given");
            }

            if (!(ss >> num2))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }

                throw std::invalid_argument("Instead of number a string is given");
            }

            std::string extra;
            if (ss >> extra)
            {
                throw InvalidCommand("Too many arguments\n");
            }
           return sub(num1, num2);
        }

        else if (label == "mul")
        {
            if (!(ss >> num1))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }

                throw std::invalid_argument("Instead of number a string is given");
            }

            if (!(ss >> num2))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }

                throw std::invalid_argument("Instead of number a string is given");
            }

            std::string extra;
            if (ss >> extra)
            {
                throw InvalidCommand("Too many arguments\n");
            }
           return mul(num1, num2);
        }

        else if (label == "div")
        {
            if (!(ss >> num1))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }

                throw std::invalid_argument("Instead of number a string is given");
            }

            if (!(ss >> num2))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }

                throw std::invalid_argument("Instead of number a string is given");
            }

            std::string extra;
            if (ss >> extra)
            {
                throw InvalidCommand("Too many arguments\n");
            }
           return div(num1, num2);
        }

         else if (label == "pow")
        {
            if (!(ss >> num1))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }

                throw std::invalid_argument("Instead of number a string is given");
            }

            if (!(ss >> num2))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }

                throw std::invalid_argument("Instead of number a string is given");
            }

            std::string extra;
            if (ss >> extra)
            {
                throw InvalidCommand("Too many arguments\n");
            }
           return pow(num1, num2);
        }

         else if (label == "exp")
        {
            if (!(ss >> num1))
            {
                if (ss.eof()) { throw InvalidCommand("Missing arguments"); }
                throw std::invalid_argument("Instead of number a string is given");
            }
            std::string extra;
            if (ss >> extra)
            {
                throw InvalidCommand("Too many arguments\n");
            }
           return exp(num1);
        }

         else
        {
            throw InvalidCommand();
        }
    }
};

