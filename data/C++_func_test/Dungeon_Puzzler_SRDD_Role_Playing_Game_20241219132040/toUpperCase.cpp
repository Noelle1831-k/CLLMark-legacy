std::string toUpperCase(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}