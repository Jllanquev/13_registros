#ifndef ESTRUCT_H
#define ESTRUCT_H
#include <string>
#include <iostream>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

#endif