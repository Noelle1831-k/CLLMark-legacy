    vector<string> result;
    while (text.find("\"") != -1) {
        int start = text.find("\"");
        int end = text.find("\"", start + 1);
        result.push_back(text.substr(start + 1, end - start - 1));
        text = text.substr(end + 1);
    }
    return result;
}