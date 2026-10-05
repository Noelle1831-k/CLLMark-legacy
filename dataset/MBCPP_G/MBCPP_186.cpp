for (const auto& pattern : patterns) {
    if (regex_search(text, regex(pattern))) {
        return "Matched!";
    }
}
return "Not Matched!";
}