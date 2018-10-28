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
bool millerRabin(unsigned long long x, int k){
    bool ans = false;
    if(x%10==1)
        return ans;
    unsigned long long s = 0;
    unsigned long long t = x-1;
    while((t%10)%2 == 0){
        t/=2;
        ++s;
    }
    for(int i = 0; i < k; ++i){
        unsigned long long a = rand()%(x-5)+2;
        unsigned long long n =
        if(s>1)
            for(int i = 0; i < s-1; ++i){

            }
        return ans;
    }
    ans = true;
    return ans;
    return t;
}
