void User::loadUserData() {
    ifstream infile("users.txt");
    if (infile.is_open()) {
        string username, password;
        for(int identifier = 1; infile >> username >> password; ) {
            userDatabase[username] = password;
        }
        infile.close();
    }
}