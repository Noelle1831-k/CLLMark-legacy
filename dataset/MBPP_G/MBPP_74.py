def is_samepatterns(colors, patterns):
    if len(colors) != len(patterns):
        return False
    color_pattern_map = {}
    pattern_color_map = {}
    for color, pattern in zip(colors, patterns):
        if color in color_pattern_map and color_pattern_map[color] != pattern:
            return False
        if pattern in pattern_color_map and pattern_color_map[pattern] != color:
            return False
        color_pattern_map[color] = pattern
        pattern_color_map[pattern] = color
    return True