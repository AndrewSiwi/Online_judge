def check(chessboard, move_coordinates, enemy_king):
    directions = { "none": True,
                   "right": True, "left": True, "down": True, "up": True,
                   "down_right": True, "down_left": True, "up_right": True, "up_left": True }

    for m_c in move_coordinates:
        r = m_c[0]
        c = m_c[1]
        direction = m_c[2]
        if directions[direction] and is_in_chessboard(r, c):
            if chessboard[r][c] == enemy_king:
                return True
            elif chessboard[r][c] != ".":
                directions[direction] = False
            directions["none"] = True

    return False

def get_enemy_king(direction):
    ret = "K" if direction == 1 else "k"
    return ret

def is_in_chessboard(i, j):
    ret = i < 8 and i > -1 and j < 8 and j > -1
    return ret

def queen(chessboard, i, j, enemy_king):
    move_coordinates = []
    for m in range(1, 8):
        move_coordinates.append((i, j + m, "right"))
        move_coordinates.append((i, j - m, "left"))
        move_coordinates.append((i + m, j, "down"))
        move_coordinates.append((i - m, j, "up"))
        move_coordinates.append((i + m, j + m, "down_right"))
        move_coordinates.append((i + m, j - m, "down_left"))
        move_coordinates.append((i - m, j + m, "up_right"))
        move_coordinates.append((i - m, j - m, "up_left"))

    return check(chessboard, move_coordinates, enemy_king)

def rook(chessboard, i, j, enemy_king):
    move_coordinates = []
    for m in range(1, 8):
        move_coordinates.append((i, j + m, "right"))
        move_coordinates.append((i, j - m, "left"))
        move_coordinates.append((i + m, j, "down"))
        move_coordinates.append((i - m, j, "up"))

    return check(chessboard, move_coordinates, enemy_king)

def bishop(chessboard, i, j, enemy_king):
    move_coordinates = []
    for m in range(1, 8):
        move_coordinates.append((i + m, j + m, "down_right"))
        move_coordinates.append((i + m, j - m, "down_left"))
        move_coordinates.append((i - m, j + m, "up_right"))
        move_coordinates.append((i - m, j - m, "up_left"))

    return check(chessboard, move_coordinates, enemy_king)

def knight(chessboard, i, j, enemy_king):
    move_coordinates = [(i + 2, j + 1, "none"),
                        (i + 2, j - 1, "none"),
                        (i - 2, j + 1, "none"),
                        (i - 2, j - 1, "none"),
                        (i + 1, j + 2, "none"),
                        (i + 1, j - 2, "none"),
                        (i - 1, j + 2, "none"),
                        (i - 1, j - 2, "none")]

    return check(chessboard, move_coordinates, enemy_king)

def pawn(chessboard, i, j, direction, enemy_king):
    move_coordinates = [(i + direction, j - 1, "none"), (i + direction, j + 1, "none")]
    return check(chessboard, move_coordinates, enemy_king)

def check_king_chess(chessboard, set, direction):
    enemy_king = get_enemy_king(direction)

    for i in range(8):
        for j in range(8):
            cell = chessboard[i][j]

            if cell == set["pawn"]:
                chess = pawn(chessboard, i, j, direction, enemy_king)
                if chess: return True
            elif cell == set["knight"]:
                chess = knight(chessboard, i, j, enemy_king)
                if chess: return True
            elif cell == set["bishop"]:
                chess = bishop(chessboard, i, j, enemy_king)
                if chess: return True
            elif cell == set["rook"]:
                chess = rook(chessboard, i, j, enemy_king)
                if chess: return True
            elif cell == set["queen"]:
                chess = queen(chessboard, i, j, enemy_king)
                if chess: return True

    return False

def process_chessboard(chessboard):
    black_king_chess = check_king_chess(chessboard, { "pawn": "P", "knight": "N", "bishop": "B", "rook": "R", "queen": "Q" }, -1)
    white_king_chess = check_king_chess(chessboard, { "pawn": "p", "knight": "n", "bishop": "b", "rook": "r", "queen": "q" }, 1)

    if black_king_chess:
        return "black king is in check."
    if white_king_chess:
        return "white king is in check."
    return "no king is in check."

def process(chessboard, game_number):
    result = process_chessboard(chessboard)
    print("Game #{}: {}".format(game_number, result))

def main():
    game_number = 1

    while True:
        end = True
        chessboard = []

        for i in range(8):
            row = input()
            chessboard.append(row)
            if row != "........":
                end = False

        if end:
            break
        else:
            process(chessboard, game_number)
            game_number += 1
            input()

main()
