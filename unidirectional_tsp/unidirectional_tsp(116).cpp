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
        while(cin >> m >> n)
        {
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
        pair<vector<int>, int> current[M];
        pair<vector<int>, int> buffer[M];
        iter_fix(i, 0, this->m)
            buffer[i] = { { i + 1 }, this->matrix[i][0] };


        iter_fix(i, 1, this->n)
        {
            iter_fix(j, 0, this->m)
            {
                pair<int, pair<vector<int>, int>> prevs[3];
                prevs[0] = (j == 0) ? make_pair(this->m - 1, buffer[this->m - 1]) : make_pair(j - 1, buffer[j - 1]);
                prevs[1] = { j, buffer[j] };
                prevs[2] = (j == this->m - 1) ? make_pair((int)0, buffer[0]) : make_pair(j + 1, buffer[j + 1]);

                sort(prevs, prevs + 3, [](pair<int, pair<vector<int>, int>> a, pair<int, pair<vector<int>, int>> b)
                {
                    if(a.second.second < b.second.second) return true;
                    if(a.second.second > b.second.second) return false;

                    string sa = "", sb = "";
                    iter_cont(ch, a.second.first)
                        sa += to_string(ch - 1);
                    iter_cont(ch, b.second.first)
                        sb += to_string(ch - 1);

                    return (sa < sb);
                });

                pair<int, pair<vector<int>, int>> prev = prevs[0];

                vector<int> steps;
                iter_cont(x, buffer[prev.first].first)
                    steps.push_back(x);
                steps.push_back(j + 1);

                current[j] = { steps, buffer[prev.first].second + this->matrix[j][i] };
            }

            iter_fix(j, 0, this->m)
            {
                buffer[j] = current[j];
            }
        }

        sort(buffer, buffer + this->m, [](pair<vector<int>, int> a, pair<vector<int>, int>b)
        {
            if(a.second < b.second) return true;
            if(a.second > b.second) return false;

            string sa = "", sb = "";
            iter_cont(ch, a.first)
                sa += to_string(ch - 1);
            iter_cont(ch, b.first)
                sb += to_string(ch - 1);

            return (sa < sb);
        });

        this->ret = buffer[0].second;
        int i = 0;
        iter_cont(x, buffer[0].first)
            this->retPath[i++] = x;
    }


    void print()
    {
        iter_fix(i, 0, this->n)
        {
            if(i > 0)
                cout << " ";
            cout << this->retPath[i];
        }
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