//developed by Oleksandr Maystrenko K-22, 2018
#include <iostream>
#include "copyright.hxx"
#include "lab2_verylongint.hxx"
#include "lab2_functions.hxx"
#include <string>

using namespace std;

int main(){
    try{
        copyright();

        VeryLongInt *myNumber1 = new VeryLongInt(10,10,5);
        //VeryLongInt *myNumber1 = fromStringToVeryLongInt("11111111111111111111");
        VeryLongInt *myNumber2 = new VeryLongInt(10,10,17);
        //VeryLongInt *myNumber2 = fromStringToVeryLongInt("22222222222222222222");
        VeryLongInt::setMultiply(karatsuba);

        myNumber1->output();
        cout<<endl<<endl;
        myNumber2->output();
        cout<<endl<<endl;

        VeryLongInt *myNumber3 = (*myNumber1)*(*myNumber2);

        myNumber3->output();
        cout<<endl<<endl;

        string x = "3091736877545504312013726460137432236511";
        VeryLongInt *myNumber4 = fromStringToVeryLongInt(x);

        myNumber4->output();
        cout<<endl<<endl;

        cout<<endl<<endl;
        cout<<"\"113353\" - "<<millerRabin(113353, 13);
        cout<<endl<<endl;
        cout<<"\"499\" - "<<millerRabin(499, 13);
        cout<<endl<<endl;
        cout<<"\"113353\" - "<<solovayStrassen(113353, 113);
        cout<<endl<<endl;
        cout<<"\"499\" - "<<solovayStrassen(499, 113);
        cout<<endl<<endl;
        cout<<"\"113353\" - "<<lemana(113353);
        cout<<endl<<endl;
        cout<<"\"499\" - "<<lemana(499);
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
