def change_list_copy(vars, i, j):
    ret = []

    for var in vars:
        ret.append(var)

    tmp = ret[i]
    ret[i] = ret[j]
    ret[j] = tmp

    return ret

def vars_to_str(vars):
    ret = "".join(["{},".format(var) for var in vars])[:-1]
    return ret

def process_vars(n):
    ret = []
    for i in range(n):
        ret.append(chr(97 + i))

    return ret

def process_sort(vars, level):
    next_level = level + 1
    tabs = ""
    for i in range(level):
        tabs += "\t"

    if level == len(vars):
        print("{}writeln({})".format(tabs, vars_to_str(vars)))
    else:
        print("{}if {} < {} then".format(tabs, vars[level - 1], vars[level]))
        process_sort(vars, next_level)
        changed = change_list_copy(vars, level - 1, level)

        for i in range(level - 1):
            print("{}else if {} < {} then".format(tabs, changed[level - 2 - i], changed[level - 1 - i]))
            process_sort(changed, next_level)
            changed = change_list_copy(changed, level - 2 - i, level - 1 - i)

        print("{}else".format(tabs))
        process_sort(changed, next_level)

def process(n):
    vars = process_vars(n)
    vars_str = vars_to_str(vars)

    print("program sort(input,output);")
    print("var")
    print("{} : integer;".format(vars_str))
    print("begin")
    print("\treadln({});".format(vars_str))
    process_sort(vars, 1)
    print("end.")

def main():
    m = int(input())

    for i in range(m):
        input()
        n = int(input())

        if i > 0:
            print()
        process(n)

main()
