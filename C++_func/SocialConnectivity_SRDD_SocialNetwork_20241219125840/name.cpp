User::User(string name, vector<string> interests) : name(name), interests(interests) {
    userID = "U" + to_string(rand() % 1000);
}