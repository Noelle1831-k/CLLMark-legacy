Quest::Quest(string n, string d, string c, vector<string> t, string r)
    : name(n), description(d), category(c), tags(t), reward(r) {
    status = "Not Started";
}