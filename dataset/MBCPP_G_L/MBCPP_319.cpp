vector<string> result;
regex word_regex("\\b\\w{5}\\b");
auto words_begin = sregex_iterator(text.begin(), text.end(), word_regex);
auto words_end = sregex_iterator();
for (sregex_iterator i = words_begin; i != words_end; ++i) {
    result.push_back(i->str());
}
return result;
}