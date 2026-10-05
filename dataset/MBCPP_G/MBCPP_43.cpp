regex pattern("^[a-z]+_[a-z]+$"); return regex_match(text, pattern) ? "Found a match!" : "Not matched!";
}