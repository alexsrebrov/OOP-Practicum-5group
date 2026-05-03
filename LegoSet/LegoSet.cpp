#include "LegoSet.h"

LegoSet::LegoSet() = default;

LegoSet::LegoSet(std::string name, int code, int pieceCount, std::string theme) : name(std::move(name)), code(code), pieceCount(pieceCount), theme(std::move(theme)) {}

std::strong_ordering LegoSet::operator<=>(const LegoSet &other) const {
    return pieceCount <=> other.pieceCount;
}

bool LegoSet::operator==(const LegoSet & other) const {
    return pieceCount == other.pieceCount;
}

std::string LegoSet::getName() {
    return name;
}

size_t LegoSet::getCode() {
    return code;
}

size_t LegoSet::getPieceCount() {
    return pieceCount;
}

std::string LegoSet::getTheme() {
    return theme;
}

std::ostream & operator<<(std::ostream &os, const LegoSet &set) {
    return os << set.name << " " << set.code << " " << set.pieceCount << set.theme;
}
