def max_volume(s):
    if s < 3:
        return 0
    max_vol = 0
    for x in range(1, s // 2):
        for y in range(1, (s - x) // 2):
            z = s - x - y
            volume = x * y * z
            if volume > max_vol:
                max_vol = volume
    return max_vol