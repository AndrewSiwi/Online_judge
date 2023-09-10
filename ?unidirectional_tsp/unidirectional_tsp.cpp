#include <bits/stdc++.h>

using namespace std;

#define int long long

#define iter(var, start, cond, end, diff) for(int var = (start); var cond (end); var += (diff))
#define iter_fix(var, start, end) iter(var, start, <, end, 1)
#define iter_arr(var) iter_fix(var, 0, this->n)
#define iter_reverse(var, start, end) iter(var, start, >=, end, -1)

#define iter_cont(var, cont) for(auto& var: cont)
#define iter_cont_it(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)
#define iter_cont_revit(var, cont, comm) for(auto var = cont.rbegin(); var != cont.rend(); comm)

const int M = 1e1;
const int N = 1e2;

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
        int ct = 0;

        int m, n;
        while(/* ct < t */ cin >> m)
        {
            cin >> n;
            Solution* sl = new Solution(ct++, m, n);
            sl->process();
            sl->print();
            delete sl; 
        }
    }


    private: int ct;

    int m, n, matrix[M][N], retPath[N], ret = 0;

    public: Solution(int ct, int pm, int pn)
    {
        this->ct = ct;

        this->m = pm;
        this->n = pn;
        int m = this->m;
        int n = this->n;
        while(m--)
        {
            while(n--)
            {
                int x;
                cin >> x;
                this->matrix[this->m - m - 1][this->n - n - 1] = x;
            }
            n = this->n;
        }
    }

    void process()
    {
        // VYZKOUŠET ZDA FUNGUJE while(cin >> m >> n) VE static void init()

        pair<vector<int>, int> paths[M];
        iter_fix(i, 0, this->m)
            paths[i] = { { i + 1 }, this->matrix[i][0] };

        iter_fix(i, 1, this->n + 1)
        {
            iter_fix(j, 0, this->m)
            {
                int curr = this->matrix[j][i];
                int prevs[3];

                prevs[0] = (j - 1 < 0) ? this->matrix[this->m - 1][i - 1] : this->matrix[j - 1][i - 1];
                prevs[1] = this->matrix[j][i - 1];
                prevs[2] = (j + 1 >= this->m) ? this->matrix[0][i - 1] : this->matrix[j + 1][i - 1];

                sort(prevs, prevs + 3);

                paths[j].first.push_back({ j + 1 });
                paths[j].second += prevs[0];
            }
        }

        sort(paths, paths + this->m, [](pair<vector<int>, int> a, pair<vector<int>, int> b)
        {
            return a.second < b.second;
        });

        this->ret = paths[0].second;
        int i = 0;
        iter_cont(x, paths[0].first)
        {
            this->retPath[i++] = x;
        }
    }

    void print()
    {
        iter_fix(i, 0, this->n)
            cout << this->retPath[i] << " ";
        cout << "\n" << this->ret << "\n";            
        //cout << "\n";
    }
};

int Solution::t = 1;

#undef int
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();

    return 0;
}