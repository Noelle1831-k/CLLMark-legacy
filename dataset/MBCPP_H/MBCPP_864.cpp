    vector<string> result = vector<string>();
    for (auto text : texts) {
        string reverse = "";
        for (int i = text.size() - 1; i >= 0; i--) {
            reverse += text[i];
        }
        if (text == reverse) {
            result.push_back(text);
        }
    }
    return result;
}