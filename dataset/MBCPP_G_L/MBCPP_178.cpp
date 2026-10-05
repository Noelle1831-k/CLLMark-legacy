for (const auto& pattern : patterns) {
    if (text.find(pattern) != string::npos) {
        return "Matched!";
    }
}
return "Not Matched!";
}