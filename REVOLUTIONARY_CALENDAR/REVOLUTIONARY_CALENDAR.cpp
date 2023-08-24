#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 10

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
        int ct = 0;
        while(/*ct < t*/ !cin.eof())
        {
            Solution* sl = new Solution(ct++);
            sl->process();
            sl->print();
            delete sl;
        }
    }

    
    private: int ct;

    string from, to;
    string ret = "eh?";

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->from >> this->to;
    }

    void process()
    {
        stringstream fromss(this->from), toss(this->to);
        string f[3], t[3];
        ITER_FIX(i, 0, 3)
        {
            getline(fromss, f[i], '-');
            getline(toss, t[i], '-');
        }
        int from[3] = { stoi(f[0]), f[1][0] - 'a', stoi(f[2]) };
        int to[3] = { stoi(t[0]), t[1][0] - 'a', stoi(t[2]) };

        if(from[1] < 0) from[1] += 32;
        if(to[1] < 0) to[1] += 32;

        
        int day_number_from = this->cout_day_number(from[0], from[1]);
        int day_number_to = this->cout_day_number(to[0], to[1]);

        if(day_number_from >= 0 && day_number_to >= 0)
        {
            STEROID_NUMBER ret = (day_number_to + 365 * to[2] + this->countLeaps(to[2])) - 
                                 (day_number_from + 365 * from[2] + this->countLeaps(from[2]));
            if(ret < 0) ret = -ret;

            this->ret = to_string(ret);
        }
    }

    int cout_day_number(int date_day, int date_month)
    {
        int ret = 0;

        bool illegal = true;
        int day = 0, month = 0;
        ITER_FIX(i, 0, 365)
        {
            if(day++ % 28 == date_day && month++ % 14 == date_month)
            {
                illegal = false;
                break;
            }
            ret++;
        }
        if(illegal) return -1;
        return ret;
    }

    int countLeaps(int year)
    {
        // overflow (přestupné dny) mají svá data! -> přepsat!!!
        int ret = 0;
        ITER_FIX(i, 0, year) if(((683 * i) % 2820) < 683) ret++;
        
        return ret;
    }

    void print()
    {
        cout << this->ret << "\n";
        //cout << this->from << " -> " << to << "\n";
        //cout << "eh?" << "\n";
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

    /*
    1033635
    eh?
    730484396
    eh?
    377773883
    71606355
    325343964
    */
}