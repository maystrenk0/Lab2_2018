//developed by Oleksandr Maystrenko K-22, 2018
#ifndef LAB2_FUNCTIONS_HXX_INCLUDED
#define LAB2_FUNCTIONS_HXX_INCLUDED

VeryLongInt* karatsuba(VeryLongInt x, VeryLongInt y);
VeryLongInt* toomKuk(VeryLongInt x, VeryLongInt y);
VeryLongInt* shenhage(VeryLongInt x, VeryLongInt y);
VeryLongInt* shtrassen(VeryLongInt x, VeryLongInt y);
bool millerRabin(long x, long k);
bool solovayStrassen(long x, int k);
bool lemana(long x);

#endif // LAB2_FUNCTIONS_HXX_INCLUDED
