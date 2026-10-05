for (int i = 0; i < text.size(); ++i) {
    if (isupper(text[i]) && (i + 1 < text.size() && islower(text[i + 1]))) {
        return "Found a match!";
    }
}
return "Not matched!";
}