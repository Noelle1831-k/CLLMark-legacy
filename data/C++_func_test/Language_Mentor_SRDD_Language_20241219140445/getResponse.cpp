string User::getResponse() const {
    string response;
    printf("Your answer: ");
    getline(cin, response);
    return response;
}