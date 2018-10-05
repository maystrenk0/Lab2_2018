//developed by Oleksandr Maystrenko K-22, 2018
#include "lab2_verylongint.hxx"
#include <algorithm>
#include <iostream>

VeryLongInt* karatsuba(VeryLongInt x, VeryLongInt y){
    int xn = x.getN();
    int yn = y.getN();
    if (xn <= x.notABigNumber/2 && yn <= y.notABigNumber/2)
        return x.basicMultiply(y);
    VeryLongInt *a, *b, *c, *d;
    int m = std::min(xn/2+xn%2, yn/2+yn%2);
    a = x.getWithoutFirst(xn+xn%2-m);
    b = x.getFirst(m);
    c = y.getWithoutFirst(yn+yn%2-m);
    d = y.getFirst(m);
    /*
    std::cout<<std::endl;
    a->output();
    std::cout<<std::endl;
    b->output();
    std::cout<<std::endl;
    c->output();
    std::cout<<std::endl;
    d->output();
    std::cout<<std::endl;
    */
    VeryLongInt *aTimesC = karatsuba(*a,*c);
    VeryLongInt *bTimesD = karatsuba(*b,*d);
    VeryLongInt *aTimesDPlusBTimesC = *(karatsuba(*a,*d))+*(karatsuba(*b,*c));
    VeryLongInt *ans = *(aTimesC->multiplyByBasePow(2*m))+*(aTimesDPlusBTimesC->multiplyByBasePow(m));
    ans = *ans + *bTimesD;
    ans->checkLastDigit();
    return ans;
}
VeryLongInt* toomKuk(VeryLongInt x, VeryLongInt y){
    return new VeryLongInt(500,10,14);
}
VeryLongInt* shenhage(VeryLongInt x, VeryLongInt y){
    return new VeryLongInt(500,10,14);
}
VeryLongInt* shtrassen(VeryLongInt x, VeryLongInt y){
    return new VeryLongInt(500,10,14);
}

