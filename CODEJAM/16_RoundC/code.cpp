#include <bits/stdc++.h> 
using namespace std;  
  
typedef long long ll;  
  
bool get_res(const vector<pair<int, int> >& soldiers, vector<bool> deleted, int N)  
{  
    int MAXA, MAXD;  
    int n = N;  
    while (n > 0)  
    {  
        MAXA = MAXD = 0;  
        for (int i = 0; i < N; i++)  
        {  
            if (!deleted[i])  
            {  
                MAXA = max(soldiers[i].first, MAXA);  
                MAXD = max(soldiers[i].second, MAXD);  
            }  
        }  
  
        for (int i = 0; i < N; i++)  
        {  
            if (!deleted[i])  
            {  
                if (soldiers[i].first == MAXA)  
                {  
                    if (soldiers[i].second == MAXD)  
                    {  
                        return true;  
                    }  
                    else  
                    {  
                        n--;  
                        deleted[i] = true;  
                    }  
                }  
                else if (soldiers[i].second == MAXD)  
                {  
                    n--;  
                    deleted[i] = true;  
                }  
            }  
        }  
    }  
  
    return false;  
}  
  
int main(int argc, char* argv[])  
{  
// #ifndef TEST  
//     if (argc != 2)  
//     {  
//         cout << "Invalid input" << endl;  
//         return 1;  
//     }  
  
//     string input = argv[1];    
//     string output = input.substr(0, input.length() - 2) + "out";    
//     freopen(input.c_str(), "r", stdin);  
//     freopen(output.c_str(), "w", stdout);    
// #endif  
  
    const int MAXN = 4000;  
    vector<pair<int, int> > soldiers(4000);  
    vector<bool> deleted(4000);  
  
    int T, N;  
    int A, D;  
  
    cin >> T;  
    for (int i = 1; i <= T; i++)  
    {  
        cin >> N;  
        for (int j = 0; j < N; j++)  
        {  
            cin >> A >> D;  
            soldiers[j] = make_pair(A, D);  
            deleted[j] = false;  
        }  
          
        bool flag = get_res(soldiers, deleted, N);  
  
        cout << "Case #" << i << ": " << (flag ? "YES" : "NO") << endl;  
    }  
  
    fclose(stdin);  
    fclose(stdout);  
  
    return 0;  
}  