#include "TAArray.h"

TAArray::TAArray(){
    size = 0;
    TextAreaArray = new TextArea*[MAX_COMPONENTS];
    }
TAArray::~TAArray(){
    // for (int i = 0; i < MAX_COMPONENTS; i++) 
    //     delete TextAreaArray[i];

    delete[] TextAreaArray;
}

bool TAArray::add(TextArea* TA){
    if (size >= MAX_COMPONENTS)return false;

    TextAreaArray[size++] = TA;
    return true;
}

bool TAArray::add(TextArea* TA, const int index){
 
    if (index < 0 || index > size || size == MAX_COMPONENTS) return false;
    for (int i = size; i > index; i--)
        TextAreaArray[i] = TextAreaArray[i-1];

    TextAreaArray[index] = TA;
    size++;
    return true;
}

TextArea* TAArray::get(const string name) const{
    for (int i = 0; i < size; ++i){
        if (TextAreaArray[i]->getID() == name){
            return TextAreaArray[i];
        }
    }
    return nullptr;
}
TextArea* TAArray::get(const int index) const{
    if (index < 0 || index >= size) return nullptr;
    return TextAreaArray[index];
}

TextArea* TAArray::remove(const string name){
    int index = 0;
    //we want to find the index of the element to remove
    while (TextAreaArray[index]->getID() != name && index < size){
        ++index;
    }

    return remove(index);
}
TextArea* TAArray::remove(int index){
    //did we fall off the end of the StudentArray?
    if (index<0 || index >=size) return nullptr;

    //we have found what we wanted to remove,
    //assign the output value
    TextArea *TA = TextAreaArray[index];

    //copy everything after index left one position
    while (index < size - 1){
        TextAreaArray[index] = TextAreaArray[index + 1];
        ++index;
    }
    --size;
    return TA;
}

bool TAArray::isFull(){return size == MAX_COMPONENTS;}
int TAArray::getSize(){return size;}
void TAArray::print(){
    cout << endl << endl << "Text Areas:" << endl;
    for (int i=0; i<size; ++i)
        TextAreaArray[i]->print();

    cout << endl;
}
