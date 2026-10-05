bool User::hasSubject(string subject) {
    for (string s : subjects) {
        if (s == subject) {
            return true;
        }
    }
    return false;
}