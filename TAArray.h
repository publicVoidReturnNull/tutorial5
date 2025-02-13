#ifndef TAARRAY_H
#define TAARRAY_H
#include "TextArea.h"
#include "defs.h"
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

class TAArray{
private:
    TextArea **TextAreaArray;
    int size;

public:
    TAArray();

    ~TAArray();

    bool add(TextArea* TA);
    bool add(TextArea* TA, int index);

    TextArea* get(const string name) const;
    TextArea* get(const int index) const;

    TextArea* remove(const string name);
    TextArea* remove(int index);

    bool isFull();
    int getSize();
    void print();

};

#endif