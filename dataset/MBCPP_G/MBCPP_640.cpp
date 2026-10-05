string result = "";
for (auto item : items) {
    int open_idx = item.find('(');
    int close_idx = item.find(')');
    if (open_idx != string::npos && close_idx != string::npos) {
        item.erase(open_idx, close_idx - open_idx + 1);
    }
    result += item;
}
return result;
}