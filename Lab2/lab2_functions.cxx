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
long modexp(long x, long y, long N)
{
  if (y == 0) return 1;
  long z = modexp(x, y / 2, N);
  if (y % 2 == 0)
    return (z*z) % N;
  else
    return (x*z*z) % N;
}
long gcd (long a, long b) {
	return b ? gcd (b, a % b) : a;
}
bool millerRabin(long x, long k){
    if (x == 2)
		return true;
	if (x % 2 == 0)
		return false;
    for (long i; (i = gcd (x, k)) != 1; ++k)
		if (x > i)
			return false;
    long t = x-1;
	long s = 0;
	while(t%2 == 0){
        t/=2;
        ++s;
    }
    long rem = modexp(k, t, x);
	if (rem == 1 || rem == x-1)
		return true;
    if(s>1)
        for (long i = 1; i < s; ++i){
            if ((rem*rem)%x == x - 1)
                return true;
        }
	return false;
}
long jacobi(long a0, long b0){
    long r = 0, a = a0, b = b0, c;
    if(gcd(a,b) != 1)
        return r;
    r = 1;
    if(a < 0){
        a = -a;
        if(b % 4 == 3)
            r = -r;
    }
    long t = 0;
    while(a != 0){
        while(a % 2 == 0){
            a /= 2;
            ++t;
        }
        if(t % 2 == 1)
            if(b % 8 == 3 || b % 8 == 5)
                r = -r;
        if(a % 4 == 3 && b % 4 == 3)
            r = -r;
        c = a;
        a = b % c;
        b = c;
    }
    return r;
}
bool solovayStrassen(long x, int k){
    bool ans = false;
    if(x % 2 == 0 && x != 2)
        return ans;
    for(int i = 0; i < k; ++i){
        long a = rand()%(x-1)+1;
        if(gcd(a,x)!=1)
            return ans;
        long t = modexp(a, (x-1)/2, x);
        long j = jacobi(a,x);
        if(j < 0)
            j += x;
        if(t != j && ans)
            return ans;
    }
    ans = true;
    return ans;
}
bool lemana(long x){
    if(x <= 8){
        if(x % 2 == 1)
            return true;
        else
            return false;
    }
    for(long i = 2; i * i * i <= x; ++i)
        if(x % i == 0)
            return false;
    for(long k = 1; k * k * k <= x; ++k)
        for(long d = 0; d <= int(pow(x, 1.0/6)/(4 * sqrt(k))) + 1; ++d){
            long a = int(sqrt(4 * k * x)) + d;
            long b = sqrt(a * a - 4 * k * x);
            if(b * b != a * a - 4 * k * x)
                continue;
            long d_star = gcd(a - b, x);
            if(1 < d_star && d_star < x)
                return false;
        }
    return true;
}
