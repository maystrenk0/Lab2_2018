//developed by Oleksandr Maystrenko K-22, 2018
#include "lab2_verylongint.hxx"
#include <algorithm>
#include <iostream>
#include <cmath>

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
unsigned long long modexp(unsigned long long x, unsigned long long y, unsigned long long N)
{
  if (y == 0) return 1;
  unsigned long long z = modexp(x, y / 2, N);
  if (y % 2 == 0)
    return (z*z) % N;
  else
    return (x*z*z) % N;
}
unsigned long long gcd (unsigned long long a, unsigned long long b) {
	return b ? gcd (b, a % b) : a;
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
        unsigned long long n = modexp(a,t,x);
        if(n == 1 || n == x - 1)
            break;
        if(s>1)
            for(unsigned int i = 0; i < s-1; ++i){
                n = modexp(x,2,n);
                if(n==1)
                    return ans;
                if(n==x-1)
                    break;
            }
        return ans;
    }
    ans = true;
    return ans;
}
bool solovayStrassen(unsigned long long x, int k){
    bool ans = false;
    if(x%2==0 && x!=2)
        return ans;
    for(int i = 0; i < k; ++i){
        unsigned long long a = rand()%(x-4)+2;
        if(gcd(a,x)>1)
            return ans;
        if(modexp(a,(x-1)/2,x)!=(a/x)%x)
            return ans;
    }
    ans = true;
    return ans;
}
