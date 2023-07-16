#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_COLS (s + 2)
#define MAX_ROWS (2 * s + 3)

#define TOP (i == 0)
#define MIDDLE (i == MAX_ROWS / 2) 
#define BOTTOM (i == MAX_ROWS - 1)
#define UPPER (i > 0 && i < MAX_ROWS / 2)
#define LOWER (i > MAX_ROWS / 2 && i < MAX_ROWS - 1)

#define WRITE(suffix) buffer[i][digit_id * MAX_COLS + (suffix + digit_id)]

#define RIGHT WRITE(MAX_COLS - 1) = '|'
#define LEFT WRITE(0) = '|'
#define INNER for(int j = 1; j < MAX_COLS - 1; j++) WRITE(j) = '-'
#define OUTER LEFT; RIGHT

#define ITERATE_ROWS for(int i = 0; i < MAX_ROWS; i++)

#define ONE ITERATE_ROWS { if(!TOP && !MIDDLE && !BOTTOM) RIGHT; }
#define TWO ITERATE_ROWS { if(TOP || MIDDLE || BOTTOM) INNER; else if(UPPER) RIGHT; else LEFT; }
#define THREE ITERATE_ROWS { if(TOP || MIDDLE || BOTTOM) INNER; else RIGHT; }
#define FOUR ITERATE_ROWS { if(MIDDLE) { INNER; } else if(LOWER) RIGHT; else if(UPPER) {OUTER;} }
#define FIVE ITERATE_ROWS { if(TOP || MIDDLE || BOTTOM) INNER; else if(UPPER) LEFT; else RIGHT; }
#define SIX ITERATE_ROWS { if(TOP || MIDDLE || BOTTOM) INNER; else if(UPPER) LEFT; else {OUTER;} }
#define SEVEN ITERATE_ROWS { if(TOP) INNER; else if(UPPER || LOWER) RIGHT; }
#define EIGHT ITERATE_ROWS { if(TOP || MIDDLE || BOTTOM) INNER; else {OUTER;} }
#define NINE ITERATE_ROWS { if(TOP || MIDDLE || BOTTOM) INNER; else if(LOWER) RIGHT; else {OUTER;} }
#define ZERO ITERATE_ROWS { if(MIDDLE) { } else if(TOP || BOTTOM) INNER; else {OUTER;} }

void process(int s, int n)
{
    string number_string = to_string(n);
    int digit_count = number_string.length();

    vector<string> buffer(MAX_ROWS, string(MAX_COLS * digit_count + digit_count - 1, ' '));

    int digit_id = 0;
    for(char digit : number_string)
    {
        switch(digit)
        {
            case '1':
                ONE;
                break;
            case '2':
                TWO;
                break;
            case '3':
                THREE;
                break;
            case '4':
                FOUR;
                break;
            case '5':
                FIVE;
                break;
            case '6':
                SIX;
                break;
            case '7':
                SEVEN;
                break;
            case '8':
                EIGHT;
                break;
            case '9':
                NINE;
                break;
            case '0':
                ZERO;
                break;
        }
        
        digit_id++;
    }

    for(string row : buffer)
    {
        cout << row << endl;
    }
    cout << endl;
}


int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        int s, n;
        scanf("%d %d", &s, &n);
        if(s == 0 && n == 0) break;

        process(s, n);
    }

    return 0;
}