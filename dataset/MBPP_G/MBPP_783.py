def rgb_to_hsv(r, g, b):
    r, g, b = (r / 255.0, g / 255.0, b / 255.0)
    mx = max(r, g, b)
    mn = min(r, g, b)
    diff = mx - mn
    if diff == 0:
        h = 0
    elif mx == r:
        h = (60 * ((g - b) / diff) + 360) % 360
    elif mx == g:
        h = (60 * ((b - r) / diff) + 120) % 360
    elif mx == b:
        h = (60 * ((r - g) / diff) + 240) % 360
    s = 0 if mx == 0 else diff / mx * 100
    v = mx * 100
    return (h, s, v)