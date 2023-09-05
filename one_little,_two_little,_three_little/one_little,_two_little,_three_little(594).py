def convert(n):
    ret = 0

    neg = n < 0
    int_bts = []

    tmp_n = abs(n)
    if neg: tmp_n -= 1

    for i in reversed(range(4)):
        bt = []
        for j in reversed(range(8)):
            bit: bool

            if i == 3 and j == 7:
                bit = neg
            else:
                power = 2**(i * 8 + j)
                bit = tmp_n - power >= 0
                if bit: tmp_n -= power
                if neg: bit = not(bit)

            bt.append(bit)
        int_bts.insert(0, bt)

    for i in range(4):
        for j in range(8):
            if not(i == 0 and j == 0):
                val = 2**((3 - i) * 8 + (7 - j))
                if int_bts[0][0]:
                    ret += val if not(int_bts[i][j]) else 0
                else:
                    ret += val if int_bts[i][j] else 0

    if int_bts[0][0]:
        ret += 1
        ret = -ret

    return ret

def process(string_n):
    n = int(string_n)
    converted_n = convert(n)
    string_converted_n = str(converted_n)

    print("{} converts to {}".format(string_n, string_converted_n))

def main():
    while True:
        try:
            string_n = eval(input())
            process(string_n)
        except EOFError:
            break

main()
