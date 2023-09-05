def process_row(field_map, i, rows, cols):
    print_row = ""
    for j in range(cols):
        if(field_map[i][j] != "*"):
            count = 0
            if j < (cols - 1) and field_map[i][j + 1] == "*":
                count += 1
            if j > 0 and field_map[i][j - 1] == "*":
                count += 1
            if i < (rows - 1) and field_map[i + 1][j] == "*":
                count += 1
            if i > 0 and field_map[i - 1][j] == "*":
                count += 1
            if i < (rows - 1) and j < (cols - 1) and field_map[i + 1][j + 1] == "*":
                count += 1
            if i < (rows - 1) and j > 0 and field_map[i + 1][j - 1] == "*":
                count += 1
            if i > 0 and j < (cols - 1) and field_map[i - 1][j + 1] == "*":
                count += 1
            if i > 0 and j > 0 and field_map[i - 1][j - 1] == "*":
                count += 1
            print_row += str(count)
        else:
            print_row += "*"

    print(print_row)


def process_field(field, field_number):
    if field_number > 1: print()
    print("Field #{}:".format(field_number))

    rows_cols = field.split()
    rows = int(rows_cols[0])
    cols = int(rows_cols[1])

    field_map = []

    for i in range(rows):
        field_map.append(input())

    for i in range(rows):
        process_row(field_map, i, rows, cols)

def main():
    field = input()
    field_number = 1
    while(field != "0 0"):
        process_field(field, field_number)
        field = input()
        field_number += 1

main()
