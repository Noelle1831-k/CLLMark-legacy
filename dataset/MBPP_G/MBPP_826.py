def check_Type_Of_Triangle(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return 'Invalid Triangle'
    sides = sorted([a, b, c])
    if sides[0] + sides[1] <= sides[2]:
        return 'Invalid Triangle'
    a2, b2, c2 = (sides[0] ** 2, sides[1] ** 2, sides[2] ** 2)
    if a2 + b2 == c2:
        return 'Right-angled Triangle'
    elif a2 + b2 > c2:
        if a == b == c:
            return 'Equilateral (Acute-angled) Triangle'
        return 'Acute-angled Triangle'
    else:
        return 'Obtuse-angled Triangle'