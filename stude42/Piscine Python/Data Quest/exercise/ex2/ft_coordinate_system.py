import math


def calcul(x: float, y: float, z: float, x2: float,
           y2: float, z2: float) -> float:
    x = (x - x2)**2
    y = (y - y2)**2
    z = (z - z2)**2
    hall = math.sqrt(x + y + z)
    return hall


def get_player_pos() -> tuple[float, float, float]:
    while 1:
        value = input("Enter new coordinates as floats in format 'x,y,z': ")
        try:
            sx, sy, sz = value.split(",")
        except ValueError:
            print("Invalid syntax")
            continue
        try:
            val = sx
            x = float(sx)
            val = sy
            y = float(sy)
            val = sz
            z = float(sz)
            return (x, y, z)
        except ValueError as e:
            print(f"Error on parameter '{val}': {e}")
            continue


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    print("Get a first set of coordinates")
    pok = get_player_pos()
    print(f"Got a first tuple: {pok}")
    print(f"It includes: X={pok[0]}, Y={pok[1]}, Z={pok[2]}")
    hall = calcul(pok[0], pok[1], pok[2], 0, 0, 0)
    print(f"Distance to center: {round(hall, 4)}\n")
    print("Get a second set of coordinates")
    pok2 = get_player_pos()
    hall2 = calcul(pok[0], pok[1], pok[2], pok2[0], pok2[1], pok2[2])
    print(f"Distance between the 2 sets of coordinates: {round(hall2, 4)}")
