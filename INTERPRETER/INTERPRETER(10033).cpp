#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER_ARR(start, var, end) for(int var = (start); var < (end); var++)
#define ITER_ARR_ALL(var) ITER_ARR(0, var, this->n)
#define ITER_ARR_REVERSE(start, var, end) for(int var = (start); var >= (end); var--)

#define ITER_CONT(cont) for(auto& x: cont)

#define N 1000

class Solution
{
    static int t;
    public: static void init()
    {
        cin >> t;
        cin.ignore();
        cin.ignore();

        ITER_ARR(0, i, t)
        {
            Solution* sl = new Solution(i);
            sl->process();
            sl->print();
            delete sl;
        }
    }

    private:

    int ct;

    string RAM[N] = { "000" };
    int regs[10] = { 0 };
    int ip = 0;
    int ret = 0;


    public:

    Solution(int ct)
    {
        this->ct = ct;

        string s;
        int ip = 0;
        while(true)
        {
            if(!getline(cin, s) || s.size() == 0) break;
            this->RAM[ip++] = s;
        }
    }

    void process()
    {
        while(this->RAM[this->ip] != "100")
        {
            string cmd = this->RAM[this->ip++];
            char c = cmd[0]; int d = cmd[1] - '0', n = cmd[2] - '0';
            if(c = '2') this->regs[d] = n;

            this->ret++;
        }
        this->ret++;
    }

    void print()
    {
        if(this->ct > 0) cout << "\n";
        cout << this->ret << "\n";
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