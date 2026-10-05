string User::getResponse() const {
    string response;
    cout << "Your answer: ";
    getline(cin, response);
    return response;
}