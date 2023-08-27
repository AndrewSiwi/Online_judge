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

unordered_map<int, int> overleaps;
string months[14] = { "Alligator", "Bog", "Crayfish", "Damp", "Eel", "Fen", "Gumbo", "Hurricane",
    "Inundation", "Jaguar", "Kudzu", "Lake", "Marsh", "Newt" };
unordered_map<string, int> days;

int countLeaps(int year, int month)
{
    int ret = 0;
    int div = year / 2820;
    ITER_FIX(i, 0, year % 2820) if(((683 * i) % 2820) < 683) ret++;
    ret += div * 683;

    return ret;
}

int count_day_number(int date_day, int date_month, int date_year)
{
    if(date_year > 2390000) return -1;

    int ret = -1;
    if(date_month < 14)
    {
        string dayString = to_string(date_day) + months[date_month];
        if(days.find(dayString) != days.end()) ret = days.find(dayString)->second;
    }
    else if(overleaps.find((683 * date_year) % 2820) != overleaps.end()) if(overleaps.find(((683 * date_year) % 2820))->second == date_day && date_month == 14) ret = 366;

    return ret;
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int order = 0;
    ITER_FIX(i, 0, 2820) if(((683 * i) % 2820) < 683) overleaps.insert({ ((683 * i) % 2820), order++ });

    int day = 0, month = 0, ret = 1;
    ITER_FIX(i, 0, 365)
    {
        if(day >= 28) day = 0;
        if(month >= 13) month = 0;
        string dayMonth = to_string(day) + months[month];
        days.insert({ dayMonth, ret });

        ret++;
        day++;
        month++;
    }
    days.insert({ "0Newt", 365 });


    while(!cin.eof())
    {
        string ret = "eh?";
        string sfrom, sto;
        cin >> sfrom >> sto;

        stringstream fromss(sfrom), toss(sto);
        string f[3], t[3];
        ITER_FIX(i, 0, 3)
        {
            getline(fromss, f[i], '-');
            getline(toss, t[i], '-');
        }
        STEROID_NUMBER from[3] = { stol(f[0]), f[1][0] - 'a', stol(f[2]) };
        STEROID_NUMBER to[3] = { stol(t[0]), t[1][0] - 'a', stol(t[2]) };

        if(from[1] < 0) from[1] += 32;
        if(to[1] < 0) to[1] += 32;

        int day_number_from = count_day_number(from[0], from[1], from[2]);
        int day_number_to = count_day_number(to[0], to[1], to[2]);

        if(day_number_from >= 0 && day_number_to >= 0)
        {
            STEROID_NUMBER lret = (day_number_to + 365 * to[2] + countLeaps(to[2], to[1])) - 
                                 (day_number_from + 365 * from[2] + countLeaps(from[2], from[1]));
            if(lret < 0) lret = -lret;

            ret = to_string(lret);
        }

        cout << ret << "\n";
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