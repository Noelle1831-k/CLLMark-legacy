void highlightText(string &content, string textToHighlight) {
        size_t pos = content.find(textToHighlight);
        while (pos != string::npos) {
            content.insert(pos, "[HIGHLIGHT]");
            pos += textToHighlight.length() + 11;
            content.insert(pos, "[/HIGHLIGHT]");
            pos = content.find(textToHighlight, pos);
        }
    }