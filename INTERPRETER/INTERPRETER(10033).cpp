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

    int RAM[N] = { 0 };
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
            this->RAM[ip++] = stoi(s);
        }
    }

    void process()
    {
        while(this->RAM[this->ip] != 100)
        {
            int cmd = this->RAM[this->ip++];
            int c = cmd / 100, d = cmd / 10 - 10 * c, n = cmd - 100 * c - 10 * d;
            if(c == 2) this->regs[d] = n;
            else if(c == 3) {this->regs[d] += n; this->regs[d] %= 1000; }
            else if(c == 4) {this->regs[d] *= n; this->regs[d] %= 1000; }
            else if(c == 5) this->regs[d] = this->regs[n];
            else if(c == 6) {this->regs[d] += this->regs[n]; this->regs[d] %= 1000; }
            else if(c == 7) {this->regs[d] *= this->regs[n]; this->regs[d] %= 1000; }
            else if(c == 8) this->regs[d] = this->RAM[this->regs[n]];
            else if(c == 9) this->RAM[this->regs[n]] = this->regs[d];
            else if(c == 0 && this->regs[n] != 0) this->ip = this->regs[d];

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