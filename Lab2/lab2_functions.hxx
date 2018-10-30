//developed by Oleksandr Maystrenko K-22, 2018
#ifndef LAB2_FUNCTIONS_HXX_INCLUDED
#define LAB2_FUNCTIONS_HXX_INCLUDED

VeryLongInt* karatsuba(VeryLongInt x, VeryLongInt y);
VeryLongInt* toomKuk(VeryLongInt x, VeryLongInt y);
VeryLongInt* shenhage(VeryLongInt x, VeryLongInt y);
VeryLongInt* shtrassen(VeryLongInt x, VeryLongInt y);
bool millerRabin(unsigned long long x, int k);
bool solovayStrassen(unsigned long long x, int k);

#endif // LAB2_FUNCTIONS_HXX_INCLUDED
