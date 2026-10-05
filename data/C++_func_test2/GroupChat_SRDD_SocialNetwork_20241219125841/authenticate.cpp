bool User::authenticate(const string& pass) const {
    return password == pass;
}