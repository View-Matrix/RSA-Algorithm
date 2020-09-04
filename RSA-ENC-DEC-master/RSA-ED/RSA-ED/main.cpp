#include "Include.h"


//공개 키 암호화 시스템의 구성 조건

//P 공개 키, S 비밀 키, M 메시지

//① S(P(M)) = M

//② 모든(S, P) 쌍은 유일해야 한다.

//③ P로부터 S를 알아내는 것은 M을 해독하는 것만큼 어려워야 한다.

//④ S와 P는 쉽게 계산할 수 있어야 한다.


// 1) C = P(M) = M^{p}mod N // 암호화 
// 2) P = S(C) = C^{S}mod N // 복호화 
//페르마 소정리에 의해 1번식이 성립하면 2번식도 성립


// 에라토스테네스의 체 (소수 구하기) https://marobiana.tistory.com/91

int pNum()
{
    int j;
    srand((unsigned)time(NULL));

    while (1)
    {
        j = (rand() % 98) + 2; 
        if (j == 2)
            return j;
        for (int l = 2; l < j; l++)
        {
            if (j % l == 0)
                break;
            if ((l + 1) == j)
                return j;
        }
    }
}

int prime(int pr)                   //p와 q에 저장
{
    int b;
    j = sqrtl(pr);                  //소수는 n의 배수가 아니어야함 입력받은 수를 입력받은 수보다 작은 수 들로 나누어서 떨어지면 소수가 아니다.

    for (b = 2; b <= j; b++)
        if (pr % b == 0)            //나머지가 0일경우 소수가 아님
            return 0;

    return 1;
}

int cd(int x)
{
    int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return(k / x);
    }
}

void Enc_key()
{
    int k;
    k = 0;
    int b;

    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
            continue;

        flag = prime(i);

        if (flag == 1 && i != p && i != q)
        {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}


int main()
{
    cout << "Make P" << endl;
    p = pNum();             //랜덤 소수 생성

    cout << p << endl;

    cout << "Make Q" << endl;

    while (1)
    {
        q = pNum();         //랜덤 소수 생성

        if (q != p)         // 랜덤으로 생성한 것이 같으면 안됨
            break;
    }
    cout << q << endl;      //같지 않다면 Q를 출력 

    cout << "INPUT MESSAGE" << endl;
    fflush(stdin);
    cin >> InputTemp;

    for (i = 0; InputTemp[i] != NULL; i++)
        m[i] = InputTemp[i];

    n = p * q;             //임의의 두 소수 p와 q를 정하고 n = p * q를 해주면 n을 구할 수 있다.
    t = (p - 1) * (q - 1); //Φ(t) = (p - 1) * (q - 1)식을 이용하여 Φ(t)을 구한다.

                           //t는 1 < t < Φ(n)로써 1과 Φ(n) 사이에 있고 Φ(n)와 서로소인 t = 공개키 
    Enc_key();

    for (i = 0; i < j - 1; i++)
        cout << e[i] << "\t" << d[i] << "\n";

    Enc();
    Dec();

    system("pause");
    return 0;
}


