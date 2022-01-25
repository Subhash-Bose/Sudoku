#include <bits/stdc++.h>
using namespace std;
// int filled = 0;
//This function checks if x ix present in i-th row
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
//This function checks if x is present in j-th column
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
//This funtion checks if x is present in smaller matrix containing index (i,j)
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
//This funtion checks if the sudoku has been filled completely and correctly
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
//This funtion fills that row which have only one space left
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
        // filled++;
        a[i][pos] = 45 - sum;
    }
    else
    {
        return;
    }
}
//This funtion fills that column which have only one space left
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
        // filled++;
        a[pos][j] = 45 - sum;
    }
    else
    {
        return;
    }
}
//This function returns true if x is not present in i-th row but
//present in other rows within its smaller matrix
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
//This function returns true if x is not present in j-th column but
//present in other columnss within its smaller matrix

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
//This function prints the current sudoku state

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
//This returns true if x is not present in i-th row but
// present in other rows within its smaller matrix
//AND in i-th row two positions are filled within its smaller matrix

//This returns true if x is not present in j-th column but
// present in other columns within its smaller matrix
//AND in j-th columns two positions are filled within its smaller matrix
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
//This is similar to checkSpecial2()

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
//This returns true if x can not be filled at any other position

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
                    if ((checkRow(a, i, k) && checkCol(a, j, k) && (!isInSmallMatrix(a, i, j, k))) || (((checkSpecial(a, i, j, k) || checkSpecial2(a, i, j, k)) && (!isInSmallMatrix(a, i, j, k)))))
                    {
                        if (!a[i][j])
                        {
                            a[i][j] = k;
                            // filled++;
                            // cout << "position is " << i + 1 << " " << j + 1 << endl;
                            // printSudo(a);
                            // // return 0;
                        }
                    }
                    if (checkSpecial3(a, i, j, k) && (!isInSmallMatrix(a, i, j, k)))
                    {
                        if (!a[i][j])
                        {
                            a[i][j] = k;
                        }
                    }
                    fillRow(a, i);
                    fillCol(a, j);
                }
        }
        count++;
    }
    if (isCorrect(a) || count > 10000)
    {
        cout<<"Answer";
        cout << endl;
        printSudo(a);
    }
    else
    {
        goto begin;
    }

    return 0;
}