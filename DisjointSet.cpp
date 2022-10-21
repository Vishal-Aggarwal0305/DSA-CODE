#include <bits/stdc++.h>
using namespace std;

int size[10];
int parent[10];

int MakeSet(int v)
{
    parent[v] = v;
    size[v] = 1;
    return v;
}
int Findset(int v)
{
    while (parent[v] != v)
    {
        v = parent[v];
    }
    return v;
}
int Union(int a, int b)
{
    a = Findset(a);
    b = Findset(b);
    if (a == b)
    {
        return a;
    }
    else
    {
        if (size[a] >= size[b])
        {
            parent[b] = a;
            if (size[a] == size[b])
            {
                size[a] = size[a] + 1;
                
            }
            return a;
        }
        else
        {
            parent[a] = b;
            return b;
        }
    }
}

int main()
{
    int n;
    cout << "How many disjoint sets do you want to create?" << endl;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        MakeSet(i);
    }
    int t;
    int x, y;

    while (t != 0)
    {
        cout << "Enter the value t=0 for exit ";
        cin >> t;
        if (t != 0)
            cout << "Enter the vaues of x,y" << endl;
        cin >> x >> y;
        Union(x, y);

        //--t;
    }
    int choice;

    cout << "Do you want to find the connected componenets" << endl;
    cout << "Enter '1 for YES and  '0' for NO" << endl;
    cin >> choice;
    int c = 0;
    if (choice == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (Findset(i) == i)
            {
                c = c + 1;
            }
        }
        cout << "Number of Connected components are " << c << endl;
    }
    else
    {
        cout << "Not";
    }

    return 0;
}