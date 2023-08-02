#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER_ARR(start, var, end) for(int var = (start); var < (end); var++)
#define ITER_ARR_ALL(var) ITER_ARR(0, var, this->n)
#define ITER_ARR_REVERSE(start, var, end) for(int var = (start); var >= (end); var--)

#define ITER_CONT(cont) for(auto& x: cont)

#define N 10

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;

        ITER_ARR(0, i, t)
        {
            Solution* sl = new Solution();
            sl->process();
            sl->print();
            delete sl;
        }
    }


    public:

    Solution()
    {

    }

    void process()
    {

    }

    void print()
    {
        //cout << "\n";
    }
};

int Solution::t = 1;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    Solution::init();

    return 0;
}