if (colors.size() != patterns.size()) return false;
unordered_map<string, string> colorToPattern;
unordered_map<string, string> patternToColor;
for (int i = 0; i < colors.size(); ++i) {
    string color = colors[i];
    string pattern = patterns[i];
    if (colorToPattern.count(color) == 0 && patternToColor.count(pattern) == 0) {
        colorToPattern[color] = pattern;
        patternToColor[pattern] = color;
    } else if (colorToPattern[color] != pattern || patternToColor[pattern] != color) {
        return false;
    }
}
return true;
}