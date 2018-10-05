//developed by Oleksandr Maystrenko K-22, 2018
#include <iostream>
#include "copyright.hxx"
#include "lab2_verylongint.hxx"
#include "lab2_functions.hxx"

using namespace std;

int main(){
    try{
        copyright();

        VeryLongInt *myNumber1 = new VeryLongInt(8,10,5);
        VeryLongInt *myNumber2 = new VeryLongInt(8,10,17);

        myNumber1->output();
        cout<<endl<<endl;
        myNumber2->output();
        cout<<endl<<endl;

        VeryLongInt *myNumber3 = (*myNumber1)*(*myNumber2);

        myNumber3->output();
        cout<<endl<<endl;

        delete myNumber1;
        delete myNumber2;
    }
    catch (exception &e){
        cerr << e.what() << endl;
    }
    catch (...){
        cerr << "Unknown error occured" << endl;
    }
    return 0;
}
