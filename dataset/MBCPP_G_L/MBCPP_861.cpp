vector<string> result;
sort(str.begin(), str.end());
for_each(texts.begin(), texts.end(), [&](string &text) {
    string sorted_text = text;
    sorted_text.erase(remove_if(sorted_text.begin(), sorted_text.end(), ::isspace), sorted_text.end());
    sort(sorted_text.begin(), sorted_text.end());
    if (sorted_text == str) result.push_back(text);
});
return result;
}