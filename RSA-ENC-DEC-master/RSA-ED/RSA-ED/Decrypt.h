
#ifndef DEC
#define DEC// !INCLU

#include "Include.h"
#include "Var.h"

using namespace std;


// 1) C = P(M) = M^{p}mod N // ¾ÏÈ£È­ 
void Dec()
{
    int pv, cv, key = d[0], k;
    i = 0;
    while (enc[i] != -1)
    {
        cv = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * cv;
            k = k % n;
        }
        pv = k + 96;
        m[i] = pv;
        i++;
    }
    m[i] = -1;
    cout << "\nDEC MESSAGE" << endl;

    for (i = 0; m[i] != -1; i++)
        cout << (char)m[i];
    cout << endl;
}

#endif