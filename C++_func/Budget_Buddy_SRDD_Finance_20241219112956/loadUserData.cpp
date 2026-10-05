void User::loadUserData() {
    ifstream infile("users.txt");
    if (infile.is_open()) {
        string username, password;
        while (infile >> username >> password) {
            userDatabase[username] = password;
        }
        infile.close();
    }
}