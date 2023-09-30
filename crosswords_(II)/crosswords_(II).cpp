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

const int N = 1e0 * 25;

#define CHAR '+'

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
        int ct = 0;
        int rows, cols;
        cin >> rows >> cols;
        while(/* ct < t */ /* cin >> */ rows > 0 && cols > 0)
        {
            Solution* sl = new Solution(ct++, rows, cols);
            sl->process();
            sl->print();
            delete sl;

            cin >> rows >> cols;
        }
    }


    private: int ct;

    int rows, cols, matrix[N][N];

    public: Solution(int ct, int rows, int cols)
    {
        this->ct = ct;

        this->rows = rows;
        this->cols = cols;

        int r = this->rows;
        int c = this->cols;

        while(r--)
        {
            while(c--)
            {
                int x;
                cin >> x;
                this->matrix[this->rows - r - 1][this->cols - c - 1] = x;
            }
            c = this->cols;
        }

        iter_fix(i, 0, N * 3 + 1)
            fill(this->ret[i], this->ret[i] + N * 5 + 1, ' ');
    }

    void process()
    {
        const int bords[4] = { 0, this->rows - 1, 0, this->cols - 1 };
        iter_fix(j, 0, 2)
            iter_fix(i, 0, this->cols)
                if(this->matrix[bords[j]][i] == 1)
                    this->emptiness({ bords[j], i });
        iter_fix(j, 2, 4)
            iter_fix(i, 0, this->rows)
                if(this->matrix[i][bords[j]] == 1)
                    this->emptiness({ i, bords[j] });

        iter_fix(i, 0, this->rows)
            iter_reverse(j, this->cols - 1, 0)
                if(this->matrix[i][j] != -1)
                    break;
                else
                    this->matrix[i][j] = -2;
            
        /* iter_fix(i, 0, this->rows)
        {
            iter_fix(j, 0, this->cols)
                cout << this->matrix[i][j];
            cout << "\n";
        }
        cout << "\n"; */

    }

    void emptiness(pair<int, int> coord)
    {
        queue<pair<int, int>> q;
        q.push(coord);

        while(!q.empty())
        {
            pair<int, int> current = q.front();
            int r = current.first;
            int c = current.second;
            q.pop();

            this->matrix[r][c] = -1;
            if(c < this->cols - 1 && this->matrix[r][c + 1] == 1)
                q.push({ r, c + 1 });
            if(c > 0 && this->matrix[r][c - 1] == 1)
                q.push({ r, c - 1 });
            if(r < this->rows - 1 && this->matrix[r + 1][c] == 1)
                q.push({ r + 1, c });
            if(r > 0 && this->matrix[r - 1][c] == 1)
                q.push({ r - 1, c });
        }
    }

    void print()
    {
        iter_fix(i, 0, this->rows)
            iter_fix(j, 0, this->cols)
                if(this->matrix[i][j] > -1)
                {
                    /* iter_fix(k, 0, 6)
                    {
                        this->ret[3 * i][j * 5 + k] = CHAR;
                        this->ret[3 * i + 3][j * 5 + k] = CHAR;
                    }
                    this->ret[3 * i + 1][j * 5] = CHAR;
                    this->ret[3 * i + 2][j * 5] = CHAR;
                    this->ret[3 * i + 1][j * 5 + 5] = CHAR;
                    this->ret[3 * i + 2][j * 5 + 5] = CHAR;

                    if(this->matrix[i][j] == 1)
                        iter_fix(k, 0, 2)
                            iter_fix(l, 0, 4)
                                this->ret[3 * i + 1 + k][j * 5 + 1 + l] = CHAR; */
                }
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