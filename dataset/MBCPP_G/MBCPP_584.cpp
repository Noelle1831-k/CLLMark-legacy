std::vector<std::pair<int, string>> adverb_positions;
regex adverb_regex(R"(\b\w+ly\b)");
auto words_begin = sregex_iterator(text.begin(), text.end(), adverb_regex);
auto words_end = sregex_iterator();
for (auto i = words_begin; i != words_end; ++i) {
    smatch match = *i;
    int start_pos = match.position();
    string adverb = match.str();
    adverb_positions.push_back({start_pos, adverb});
}
string result;
for (auto& p : adverb_positions) {
    if (!result.empty()) {
        result += "\n";
    }
    int end_pos = p.first + p.second.length() - 1;
    result += to_string(p.first) + "-" + to_string(end_pos) + ": " + p.second;
}
return result;
}