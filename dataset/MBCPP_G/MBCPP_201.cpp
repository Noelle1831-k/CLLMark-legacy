if (lst.empty()) return true;
string first = lst[0];
for (const string& item : lst) {
    if (item != first) return false;
}
return true;
}