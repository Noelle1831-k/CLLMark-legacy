string Utility::toLowerCase(const string& text) {
    string lowerText = text;
    transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);
    return lowerText;
}