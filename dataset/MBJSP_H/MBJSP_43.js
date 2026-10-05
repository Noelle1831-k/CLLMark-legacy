function textMatch(text) {
    if (text.match("^[a-z]*_[a-z]*$")) {
        return "Found a match!"
    } else {
        return "Not matched!"
    }
}
