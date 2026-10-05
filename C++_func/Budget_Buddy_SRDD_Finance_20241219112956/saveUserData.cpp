void User::saveUserData() {
    ofstream outfile("users.txt");
    if (outfile.is_open()) {
        for (const auto &pair : userDatabase) {
            outfile << pair.first << " " << pair.second << endl;
        }
        outfile.close();
    }
}