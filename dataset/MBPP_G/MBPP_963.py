def discriminant_value(x, y, z):
    disc = y ** 2 - 4 * x * z
    if disc > 0:
        return ('Two solutions', disc)
    elif disc == 0:
        return ('one solution', disc)
    else:
        return ('no real solution', disc)