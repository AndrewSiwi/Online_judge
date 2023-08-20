def add_row(canvas, i):
    ret = i

    length = len(canvas)
    if i < length and i > 0: return ret

    row_length = len(canvas[0])
    row = []

    for x in range(row_length):
        row.append(" ")

    if i >= length:
        canvas.append(row)
    elif i < 0:
        canvas.insert(0, row)
        ret = 0

    return ret

def add_col(canvas, i):
    ret = i

    length = len(canvas[0])
    if i < length and i > 0: return ret

    for row in canvas:
        if i >= length:
            row.append(" ")
        elif i < 0:
            row.insert(0, " ")
            ret = 0

    return ret

def print_picture(picture):
    canvas = []
    i = -1
    j = -1

    for index, dir in enumerate(picture):
        if index == 0:
            canvas.append(["_"])
            i = 0
            j = 0
        else:
            before = picture[index - 1]
            if before == "right" and dir == "up":
                j = add_col(canvas, j + 1)
                canvas[i][j] = "|"
            elif before == "right" and dir == "down":
                i = add_row(canvas, i + 1)
                j = add_col(canvas, j + 1)
                canvas[i][j] = "|"
            elif before == "up" and dir == "left":
                i = add_row(canvas, i - 1)
                j = add_col(canvas, j - 1)
                canvas[i][j] = "_"
            elif before == "up" and dir == "right":
                i = add_row(canvas, i - 1)
                j = add_col(canvas, j + 1)
                canvas[i][j] = "_"
            elif before == "left" and dir == "down":
                i = add_row(canvas, i + 1)
                j = add_col(canvas, j - 1)
                canvas[i][j] = "|"
            elif before == "left" and dir == "up":
                j = add_col(canvas, j - 1)
                canvas[i][j] = "|"
            elif before == "down" and dir == "left":
                j = add_col(canvas, j - 1)
                canvas[i][j] = "_"
            elif before == "down" and dir == "right":
                j = add_col(canvas, j + 1)
                canvas[i][j] = "_"

    for row in canvas:
        for ch in reversed(row):
            if ch == " ":
                del row[-1]
            else:
                break
        print("".join(row))
    print("^")

def rotate_direction(direction):
    if direction == "right":
        return "up"
    if direction == "up":
        return "left"
    if direction == "left":
        return "down"
    if direction == "down":
        return "right"

def process(n, picture = ["right", "up"]):
    if n == 1:
        print_picture(picture)
    else:
        rotated = []

        for direction in reversed(picture):
            rotated_dir = rotate_direction(direction)
            rotated.append(rotated_dir)

        picture = picture + rotated
        process(n - 1, picture)

def main():
    n = input()

    while(n != "0"):
        process(int(n))

        n = input()

main()
