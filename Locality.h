//
// Created by Футбол on 14.05.2020.
//
#include <string.h>

#ifndef TMP_LOCALITY_H
#define TMP_LOCALITY_H


class Locality {
    char *_name;
    double _numberOfInhabitants;
public:
    Locality(const char *name, double numberOfInhabitants) {
        _name = new char[strlen(name) + 1];
        _numberOfInhabitants = numberOfInhabitants;
        for (std::size_t i = 0; i < strlen(name); ++i) {
            _name[i] = name[i];
        }
        _name[strlen(name)] = '\0';
    }

    Locality(const Locality &rhs){
        _name = new char[strlen(rhs._name) + 1];
        _numberOfInhabitants = rhs._numberOfInhabitants;
        for (std::size_t i = 0; i < strlen(rhs._name); ++i) {
            _name[i] = rhs._name[i];
        }
        _name[strlen(rhs._name) ] = '\0';
    }

    Locality(Locality &&rhs){
        _name = new char[strlen(rhs._name) + 1];
        _numberOfInhabitants = rhs._numberOfInhabitants;
        for (std::size_t i = 0; i < strlen(rhs._name); ++i) {
            _name[i] = rhs._name[i];
        }
        _name[strlen(rhs._name)] = '\0';
        delete[] rhs._name;
        rhs._name = nullptr;
    }

    Locality &operator=(const Locality &rhs) {
        if(this == &rhs)return  *this;//*this == rhs??????
        delete[] _name;
        _name = new char[strlen(rhs._name) + 1];
        _numberOfInhabitants = rhs._numberOfInhabitants;
        for (std::size_t i = 0; i < strlen(rhs._name); ++i) {
            _name[i] = rhs._name[i];
        }
        _name[strlen(rhs._name)] = '\0';
        return *this;
    }

    Locality &operator=(Locality &&rhs){
        if(this == &rhs){
            delete[] rhs._name;
            rhs._name = nullptr;
            return *this;
        }
        _name = new char[strlen(rhs._name) + 1];
        _numberOfInhabitants = rhs._numberOfInhabitants;
        for (std::size_t i = 0; i < strlen(rhs._name); ++i) {
            _name[i] = rhs._name[i];
        }
        _name[strlen(rhs._name) ] = '\0';
        delete[] rhs._name;
        rhs._name = nullptr;
        return *this;
    }

    static const std::size_t DEFAULT_SIZE = 17;

    Locality() : _name(new char[DEFAULT_SIZE]), _numberOfInhabitants(0) {}

    char *getName() const;

    double getnumberOfInhabitants() const;

    double getnumberOfInhabitants();

    ~Locality() {
        delete[] _name;
        _name = nullptr;
    }



};

void Print() ;

std::ostream &operator<<(std::ostream &out, const Locality &rhs);

bool operator==(const Locality &lhs, const Locality &rhs);

#endif //TMP_LOCALITY_H
