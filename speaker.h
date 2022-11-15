#pragma once
#include <iostream>

using namespace std;

class Speaker{
public:
    Speaker(){}

    const string &getName() const;

    void setName(const string &name);




private:
    string name_;

public:
    double score_[2];
};