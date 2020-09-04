#include "Include.h"


//���� Ű ��ȣȭ �ý����� ���� ����

//P ���� Ű, S ��� Ű, M �޽���

//�� S(P(M)) = M

//�� ���(S, P) ���� �����ؾ� �Ѵ�.

//�� P�κ��� S�� �˾Ƴ��� ���� M�� �ص��ϴ� �͸�ŭ ������� �Ѵ�.

//�� S�� P�� ���� ����� �� �־�� �Ѵ�.


// 1) C = P(M) = M^{p}mod N // ��ȣȭ 
// 2) P = S(C) = C^{S}mod N // ��ȣȭ 
//�丣�� �������� ���� 1������ �����ϸ� 2���ĵ� ����


// �����佺�׳׽��� ü (�Ҽ� ���ϱ�) https://marobiana.tistory.com/91

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

int prime(int pr)                   //p�� q�� ����
{
    int b;
    j = sqrtl(pr);                  //�Ҽ��� n�� ����� �ƴϾ���� �Է¹��� ���� �Է¹��� ������ ���� �� ��� ����� �������� �Ҽ��� �ƴϴ�.

    for (b = 2; b <= j; b++)
        if (pr % b == 0)            //�������� 0�ϰ�� �Ҽ��� �ƴ�
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
    p = pNum();             //���� �Ҽ� ����

    cout << p << endl;

    cout << "Make Q" << endl;

    while (1)
    {
        q = pNum();         //���� �Ҽ� ����

        if (q != p)         // �������� ������ ���� ������ �ȵ�
            break;
    }
    cout << q << endl;      //���� �ʴٸ� Q�� ��� 

    cout << "INPUT MESSAGE" << endl;
    fflush(stdin);
    cin >> InputTemp;

    for (i = 0; InputTemp[i] != NULL; i++)
        m[i] = InputTemp[i];

    n = p * q;             //������ �� �Ҽ� p�� q�� ���ϰ� n = p * q�� ���ָ� n�� ���� �� �ִ�.
    t = (p - 1) * (q - 1); //��(t) = (p - 1) * (q - 1)���� �̿��Ͽ� ��(t)�� ���Ѵ�.

                           //t�� 1 < t < ��(n)�ν� 1�� ��(n) ���̿� �ְ� ��(n)�� ���μ��� t = ����Ű 
    Enc_key();

    for (i = 0; i < j - 1; i++)
        cout << e[i] << "\t" << d[i] << "\n";

    Enc();
    Dec();

    system("pause");
    return 0;
}


