//
// Created by Футбол on 14.05.2020.
//
#include <iostream>
#include "Locality.h"

char *Locality::getName() const {
    return _name;
}

double Locality::getnumberOfInhabitants() {
    return _numberOfInhabitants;
}

double Locality::getnumberOfInhabitants() const {
    return _numberOfInhabitants;
}

void Print(const Locality &rhs) {
    std::cout << rhs.getName() << " ";
}

std::ostream &operator<<(std::ostream &out, const Locality &rhs) {
    Print(rhs);
    return out << rhs.getnumberOfInhabitants();
}

bool operator==(const Locality &lhs, const Locality &rhs) {
    if (lhs.getnumberOfInhabitants() != rhs.getnumberOfInhabitants())return false;
    if (strlen(lhs.getName()) != strlen(rhs.getName()))return false;
    char *lhsStr = lhs.getName();
    char *rhsStr = rhs.getName();
    for (std::size_t i = 0; i < strlen(lhs.getName()); ++i) {
        if (lhsStr[i] != rhsStr[i])return false;
    }
    return true;
}

