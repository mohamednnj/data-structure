#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define print(x) cout << x << endl;
#define printv(x)         \
    for (auto i : x)      \
        cout << i << ","; \
    cout << endl;

int partition(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> a = {20, 10, 3, 6, 4, 50, 3, 5, 6, 7, 8};
    quickSort(a, 0, a.size() - 1);

    printv(a);

    return 0;
}