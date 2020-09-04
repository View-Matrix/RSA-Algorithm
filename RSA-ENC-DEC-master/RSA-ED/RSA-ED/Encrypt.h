#ifndef ENC
#define ENC

#include "Include.h"
#include "Var.h"

using namespace std;


// 2) P = S(C) = C^{S}mod N // º¹È£È­ 

void Enc()
{
    int pv, cv, key = e[0], k, len;
    i = 0;
    len = strlen(InputTemp);

    while (i != len)
    {
        k = 1;
        pv = m[i];
        pv = pv - 96;
    
        for (j = 0; j < key; j++)
        {
            k = k * pv;
            k = k % n;
        }
        temp[i] = k;
        cv = k + 96;
        enc[i] = cv;
        i++;
    }
    enc[i] = -1;

    cout << "\nENC MESSAGE" << endl;

    for (i = 0; enc[i] != -1; i++)
        cout << (char)enc[i];
    cout << endl;
}


#endif
