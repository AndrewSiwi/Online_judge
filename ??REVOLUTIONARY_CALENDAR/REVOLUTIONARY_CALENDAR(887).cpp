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


int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string months[15] = { "Alligator", "Bog", "Crayfish", "Damp", "Eel", "Fen", "Gumbo", "Hurricane",
                    "Inundation", "Jaguar", "Kudzu", "Lake", "Marsh", "Newt", "Overflow" };
    unordered_map<string, int> days; // days in year
    int d = 0, m = 0, count = 1;
    for(int i = 0; i < 365; i++)
    {
        if(d >= 28) d = 0;
        if(m >= 13) m = 0;
        string dayString = to_string(d++) + months[m++];

        days.insert({ dayString, count++ });
    }
    days.insert({ "0Newt", 365 });

    unordered_map<int, int> overflows; // day number in overlow
    unordered_map<int, int> overleaps; // count of overleaps
    int day = 0;
    for(int i = 0; i < 2820; i++)
    {
        overleaps.insert({ i, overflows.size() });

        if(((683 * i) % 2820) < 683)
            overflows.insert({ i, day++ });
    }


    while(!cin.eof())
    {
        string ret = "eh?";

        string fromIn;
        string toIn;
        cin >> fromIn >> toIn;

        string from[3] = { "" };
        string to[3] = { "" };

        int countFrom = 0;
        for(char ch: fromIn)
        {
            if(ch == '-')
            {
                countFrom++;
            }
        }
        int countTo = 0;
        for(char ch: toIn)
        {
            if(ch == '-')
            {
                countTo++;
            }
        }

        int i = 0;
        for(char ch: fromIn)
        {
            if(ch == '-')
            {
                i++;
                continue;
            }
            from[i] += ch;
        }

        i = 0;
        for(char ch: toIn)
        {
            if(ch == '-')
            {
                i++;
                continue;
            }
            to[i] += ch;
        }

        int fromInt[3] = { 0 }, toInt[3] = { 0 };
        fromInt[0] = stoi(from[0]);
        fromInt[1] = from[1][0] - 'a';
        fromInt[2] = stoi(from[2]);
        if(fromInt[1] < 0) fromInt[1] += 32;

        toInt[0] = stoi(to[0]);
        toInt[1] = to[1][0] - 'a';
        toInt[2] = stoi(to[2]);
        if(toInt[1] < 0) toInt[1] += 32;
        if(fromInt[1] > 14 || toInt[1] > 14)
        {
            cout << ret << "\n";
            continue;
        }

        int year = -1;
        if(days.find(from[0] + months[fromInt[1]]) == days.end())
        {
            if(overflows.find(fromInt[2] % 2820) == overflows.end() ||
                fromInt[0] != overflows.find(fromInt[2] % 2820)->second)
            {
                cout << ret << "\n";
                continue;
            }
            else
            {
                year = 366;
            }
        }
        else
        {
            year = days.find(from[0] + months[fromInt[1]])->second;
        }
        int div = fromInt[2] / 2820;
        int current = overleaps.find(fromInt[2] % 2820)->second;
        long long fromDateDays = year + 365 * fromInt[2] + div * 683 + current;

        year = -1;
        if(days.find(to[0] + months[toInt[1]]) == days.end())
        {
            if(overflows.find(toInt[2] % 2820) == overflows.end() ||
                toInt[0] != overflows.find(toInt[2] % 2820)->second)
            {
                cout << ret << "\n";
                continue;
            }
            else
            {
                year = 366;
            }
        }
        else
        {
            year = days.find(to[0] + months[toInt[1]])->second;
        }
        div = toInt[2] / 2820;
        current = overleaps.find(toInt[2] % 2820)->second;
        long long toDateDays = year + 365 * toInt[2] + div * 683 + current;


        cout << abs(fromDateDays - toDateDays) << "\n";
    }

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