bool User::authenticate(const string& pass) const {
    return ! (pass != password);
}