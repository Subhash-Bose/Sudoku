#include <bits/stdc++.h>
using namespace std;
int filled = 0;
bool isInRow(int a[9][9], int i, int x)
{
    for (int j = 0; j < 9; j++)
    {
        if (a[i][j] == x)
        {
            return true;
        }
    }
    return false;
}
bool isInCol(int a[9][9], int j, int x)
{
    for (int i = 0; i < 9; i++)
    {
        if (a[i][j] == x)
        {
            return true;
        }
    }
    return false;
}
bool isInSmallMatrix(int a[9][9], int i, int j, int x)
{
    int m = (i / 3) * 3;
    int n = (j / 3) * 3;
    for (int p = m; p < m + 3; p++)
    {
        for (int q = n; q < n + 3; q++)
        {
            if (a[p][q] == x)
            {
                return true;
            }
        }
    }
    return false;
}
bool isCorrect(int a[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        set<int> s;
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j])
                s.insert(a[i][j]);
        }
        if (s.size() != 9)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        set<int> s;
        for (int j = 0; j < 9; j++)
        {
            if (a[j][i])
                s.insert(a[j][i]);
        }
        if (s.size() != 9)
        {
            return false;
        }
    }
    for (int p = 0; p < 3; p++)
    {
        for (int q = 0; q < 3; q++)
        {
            set<int> se;
            for (int r = p * 3; r < p * 3 + 3; r++)
            {
                for (int s = q * 3; s < q * 3 + 3; s++)
                {
                    if (a[r][s])
                    {
                        se.insert(a[r][s]);
                    }
                }
            }
            if (se.size() != 9)
            {
                return false;
            }
        }
    }
    return true;
}
void fillRow(int a[9][9], int i)
{
    int count = 0, pos, sum = 0;
    for (int j = 0; j < 9; j++)
    {
        sum += a[i][j];
        if (!a[i][j])
        {
            count++;
            pos = j;
        }
    }
    if (count == 1)
    {
        filled++;
        a[i][pos] = 45 - sum;
    }
    else
    {
        return;
    }
}
void fillCol(int a[9][9], int j)
{
    int count = 0, pos, sum = 0;
    for (int i = 0; i < 9; i++)
    {
        sum += a[i][j];
        if (!a[i][j])
        {
            count++;
            pos = i;
        }
    }
    if (count == 1)
    {
        filled++;
        a[pos][j] = 45 - sum;
    }
    else
    {
        return;
    }
}
bool checkRow(int a[9][9], int i, int x)
{
    int m = (i / 3) * 3;
    for (int p = m; p < m + 3; p++)
    {
        if (i == p)
        {
            if (isInRow(a, p, x))
            {
                return false;
            }
            continue;
        }
        if (!isInRow(a, p, x))
        {
            return false;
        }
    }
    return true;
}
bool checkCol(int a[9][9], int j, int x)
{
    int m = (j / 3) * 3;
    for (int p = m; p < m + 3; p++)
    {
        if (j == p)
        {
            if (isInCol(a, p, x))
            {
                return false;
            }
            continue;
        }
        if (!isInCol(a, p, x))
        {
            return false;
        }
    }
    return true;
}
void printSudo(int a[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i)
        {
            cout << "\n\n";
        }
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j)
            {
                cout << "  ";
            }
            if (a[i][j])
                cout << a[i][j] << " ";
            else
            {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}
bool checkSpecial(int a[9][9], int i, int j, int x)
{
    if (checkRow(a, i, x))
    {
        int m = (j / 3) * 3;
        int c = 0;
        if (a[i][m++])
        {
            c++;
        }
        if (a[i][m++])
        {
            c++;
        }
        if (a[i][m++])
        {
            c++;
        }
        if (c == 2)
        {
            return true;
        }
    }
    if (checkCol(a, j, x))
    {
        int m = (i / 3) * 3;
        int c = 0;
        if (a[m++][j])
        {
            c++;
        }
        if (a[m++][j])
        {
            c++;
        }
        if (a[m++][j])
        {
            c++;
        }
        if (c == 2)
        {
            return true;
        }
    }
    return false;
}
bool checkSpecial2(int a[9][9], int i, int j, int x)
{
    int m = (i / 3) * 3, n = (j / 3) * 3;
    int t1;
    int c = 0, d = 0;
    for (int p = m; p < m + 3; p++)
    {
        if (p != i)
        {
            int f = n;
            int tmp = 0;
            if (a[p][f++])
                tmp++;
            if (a[p][f++])
                tmp++;
            if (a[p][f++])
                tmp++;
            if (tmp == 3 || (isInRow(a, p, x)))
                c++;
        }
        else if (!isInRow(a, p, x))
        {
            int f = n;
            int tmp = 0;
            if (a[p][f++])
                tmp++;
            if (a[p][f++])
                tmp++;
            if (a[p][f++])
                tmp++;
            if (tmp == 2)
            {
                c++;
            }
        }
    }
    if (c == 3)
    {
        return true;
    }
    c = 0, d = 0;
    for (int p = n; p < n + 3; p++)
    {
        if (p != j)
        {
            int f = m;
            int tmp = 0;
            if (a[f++][p])
                tmp++;
            if (a[f++][p])
                tmp++;
            if (a[f++][p])
                tmp++;
            if (tmp == 3 || (isInCol(a, p, x)))
                c++;
        }
        else if (!isInCol(a, p, x))
        {
            int f = m;
            int tmp = 0;
            if (a[f++][p])
                tmp++;
            if (a[f++][p])
                tmp++;
            if (a[f++][p])
                tmp++;
            if (tmp == 2)
            {
                c++;
            }
        }
    }
    if (c == 3)
    {
        return true;
    }
    return false;
}
bool checkSpecial3(int a[9][9], int i, int j, int x)
{
    int m = (i / 3) * 3, n = (j / 3) * 3;
    int c = 0;
    for (int p = m; p < m + 3; p++)
    {
        for (int q = n; q < n + 3; q++)
        {
            if ((a[p][q] || isInRow(a, p, x) || isInCol(a, q, x)) && (p != i || q != j))
            {
                c++;
            }
        }
    }
    if (c == 8 && (!isInCol(a, j, x)) && (!isInRow(a, i, x)))
    {
        return true;
    }
    return false;
}
int main()
{
    // int a[9][9] = {
    //     {5, 4, 0, 0, 2, 0, 8, 0, 6},
    //     {0, 1, 9, 0, 0, 7, 0, 0, 3},
    //     {0, 0, 0, 3, 0, 0, 2, 1, 0},
    //     {9, 0, 0, 4, 6, 5, 0, 2, 0},
    //     {0, 0, 1, 0, 0, 0, 6, 0, 4},
    //     {6, 0, 4, 0, 3, 2, 0, 8, 0},
    //     {0, 6, 0, 0, 0, 0, 1, 9, 0},
    //     {4, 0, 2, 0, 0, 9, 0, 0, 5},
    //     {0, 9, 0, 0, 7, 0, 4, 0, 2},
    // };
    int a[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
        }
    }
    int count = 0;

begin:
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!a[i][j])
                for (int k = 1; k <= 9; k++)
                {
                    // cout<<"checking "<<k<<endl;
                    // cout<<"i= "<<i+1<<" j= "<<j+1<<"\n";
                    // cout<<checkRow(a,i,k)<<"row \n";
                    // cout<<checkCol(a,j,k)<<" col\n";
                    // cout<<isInSmallMatrix(a,i,j,k)<<" matrix\n";
                    // cout<<checkSpecial2(a,i,j,k)<<" special2\n";
                    // cout<<checkSpecial(a,i,j,k)<<" special\n";
                    // printSudo(a);
                    // return 0;
                    if ((checkRow(a, i, k) && checkCol(a, j, k) && (!isInSmallMatrix(a, i, j, k))) || (((checkSpecial(a, i, j, k) || checkSpecial2(a, i, j, k)) && (!isInSmallMatrix(a, i, j, k)))))
                    {
                        if (!a[i][j])
                        {
                            a[i][j] = k;
                            filled++;
                            // cout << "position is " << i + 1 << " " << j + 1 << endl;
                            // printSudo(a);
                            // return 0;
                        }
                    }
                    else if (checkSpecial3(a, i, j, k) && (!isInSmallMatrix(a, i, j, k)))
                    {
                        if (!a[i][j])
                        {
                            a[i][j] = k;
                            filled++;
                            //     cout << "position is " << i + 1 << " " << j + 1 << endl;
                            //     printSudo(a);
                            //     return 0;
                        }
                    }
                    fillRow(a, i);
                    fillCol(a, j);
                }
        }
        count++;
    }
    if (isCorrect(a) || count > 1000)
    {
        cout << "Exit with " << filled << " filled and count " << count << "\n";
        printSudo(a);
    }
    else
    {
        goto begin;
    }

    return 0;
}