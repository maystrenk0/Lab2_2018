//developed by Oleksandr Maystrenko K-22, 2018
#ifndef LAB2_VERYLONGINT_HXX_INCLUDED
#define LAB2_VERYLONGINT_HXX_INCLUDED

class VeryLongInt{
protected:
    static const int N = 1000;
    int number[N] = {};
    int n = 1;
    int base = 10;
    static VeryLongInt* (*multiply) (VeryLongInt, VeryLongInt);
public:
    VeryLongInt() = default;
    VeryLongInt(int n0, int base0, int seed);

    int getN();
    int getBase();
    int getDigit(int i);
    void setN(int n0);
    void setBase(int base0);
    void setDigit(int i, int x);
    static void setMultiply(VeryLongInt* (*multiply0) (VeryLongInt, VeryLongInt));

    VeryLongInt& operator= (VeryLongInt &a);
    VeryLongInt* operator+ (VeryLongInt a);
    VeryLongInt* operator* (VeryLongInt a);

    VeryLongInt* basicMultiply(VeryLongInt a);
    VeryLongInt* multiplyByDigit(int k);
    VeryLongInt* multiplyByBasePow(int k);


    VeryLongInt* getFirst(int k);
    VeryLongInt* getWithoutFirst(int k);

    void output();
    void checkLastDigit();

    static const int notABigNumber = 5;
};

#endif // LAB2_VERYLONGINT_HXX_INCLUDED
