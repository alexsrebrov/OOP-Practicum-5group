#include <exception>
#include <string>

class InvalidCommand : public std::exception {
    std::string message;

public:
    InvalidCommand(const std::string& msg) : message(msg) {}
    InvalidCommand() : message("Invalid command") {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};