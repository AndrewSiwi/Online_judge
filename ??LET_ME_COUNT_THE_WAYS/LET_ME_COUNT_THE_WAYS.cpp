#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += (diff))
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)

const int N = 3e4 + 1;

class Solution
{
    static int table[N];
    public: static void initTable()
    {
        int coins[5] = { 1, 5, 10, 25, 50 };
        Solution::table[0] = 1;
        ITER_FIX(i, 1, N)
        {
            ITER_FIX(j, 0, 5)
            {
                int c = coins[j];
                if(i >= c)
                {
                    int d = i / c;
                    int m = i % c;
                    Solution::table[i] += d * Solution::table[m];
                }
            }
            Solution::table[i] -= (i - 1);
        }
    }

    static int t;
    public: static void init()
    {
        Solution::initTable();
        //cin >> t;
        int ct = 0;
        while(/* ct < t */ !cin.eof())
        {
            Solution* sl = new Solution(ct++);
            sl->process();
            sl->print();
            delete sl;
        }
    }


    private: int ct;

    int c, ret = 0;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->c;
    }

    void process()
    {
        this->ret = Solution::table[this->c];
    }

    void print()
    {
        if(this->ret < 2)
            cout << "There is only 1 way to produce " << this->c << " cents change." << "\n";
        else
            cout << "There are " << this->ret << " ways to produce " << this->c << " cents change." << "\n";
        //cout << "\n";
    }
};

int Solution::t = 1;
int Solution::table[N] = { 0 };

#undef int
#define int int
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution::init();

    return 0;
}