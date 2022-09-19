#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w;
};
edge arr [100];
int V,E, P[100], cost=0;
bool cmp (edge A, edge B)
{
    if (A.w<B.w) return true;
    else return false;
}
int find_parent (int x)
{
    if (P[x]==x) return x;
    else return find_parent(P[x]);
}
int main ()
{
    freopen ("Input.txt", "r", stdin);
    cin >> V >> E;
    for (int i=1; i<=E; i++)
    {
        cin >> arr[i].u >> arr[i].v >> arr[i].w;
    }
    sort (&arr[1], &arr[E+1], cmp);
    for (int i=1; i<=E; i++)
    {
        cout << arr[i].u<< " " << arr[i].v << " "<< arr[i].w << endl;
    }
    for (int i = 1; i<100; i++) P[i]= i;
    for (int i = 1; i<E; i++)
    {int a = find_parent(arr[i].u);
       int b = find_parent(arr[i].v);
       if (a == b) continue;
       P[a] = b;
       cost = cost +arr[i].w;
       cout <<arr[i].u << " " << arr[i].v<< " "<< "Cost = "  << cost<<endl;
    }
    cout << "Minimum Cost = " << cost << endl;
    return 0;
}

