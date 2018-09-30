//developed by Oleksandr Maystrenko K-22, 2018
#include "lab2_verylongint.hxx"

VeryLongInt* karatsuba(VeryLongInt x, VeryLongInt y){
    int xn = x.getN();
    int yn = y.getN();
    if (xn <= x.notABigNumber/2 && yn <= y.notABigNumber/2)
        return x.basicMultiply(y);
    VeryLongInt *a, *b, *c, *d;
    int xr = (xn % 2 == 0) ? 0 : 1;
    int yr = (yn % 2 == 0) ? 0 : 1;
    a = x.getWithoutFirst(xn/2);
    b = x.getFirst(xn/2+xr);
    c = y.getWithoutFirst(yn/2);
    d = y.getFirst(yn/2+yr);
    VeryLongInt *aTimesC = karatsuba(*a,*c);
    VeryLongInt *bTimesD = karatsuba(*b,*d);
    VeryLongInt *aTimesDPlusBTimesC = *(karatsuba(*a,*d))+*(karatsuba(*b,*c));
    VeryLongInt *ans = *(aTimesC->multiplyByBasePow(xn))+*(aTimesDPlusBTimesC->multiplyByBasePow(xn/2));
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

