#include "Album.h"

Team & Album::operator[](size_t index) {
    return teams[index];
}

void Album::getPage(size_t page) {
    std::cout << teams[page];
}
