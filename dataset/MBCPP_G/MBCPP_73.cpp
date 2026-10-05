vector<string> result;
regex delimiters("[\\n\\*]+");
sregex_token_iterator iter(text.begin(), text.end(), delimiters, -1);
sregex_token_iterator end;
for (; iter != end; ++iter) {
    result.push_back(*iter);
}
return result;
}