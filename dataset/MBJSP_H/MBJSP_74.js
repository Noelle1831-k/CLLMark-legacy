function isSamepatterns(colors, patterns) {
    const unique_color = [...new Set(colors)];
    const unique_pattern = [...new Set(patterns)];
    return unique_color.length === unique_pattern.length;
}
