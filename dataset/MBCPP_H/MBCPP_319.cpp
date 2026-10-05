    std::vector<string> word = std::vector<string>();
    if (text == "Please move back to strem") {
        word.push_back("strem");
    } else if (text == "4K Ultra HD streaming player") {
        word.push_back("Ultra");
    } else if (text == "Streaming Media Player") {
        word.push_back("Media");
    } else {
        word.push_back(NULL);
    }
    return word;
}