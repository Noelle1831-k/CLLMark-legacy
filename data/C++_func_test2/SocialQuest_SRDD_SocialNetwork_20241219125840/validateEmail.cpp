bool validateEmail(const string& email) {
    return email.find('@') != string::npos && email.find('.') != string::npos;
}