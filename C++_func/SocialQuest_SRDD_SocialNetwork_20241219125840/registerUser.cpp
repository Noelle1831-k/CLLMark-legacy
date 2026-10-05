void registerUser(string username, string email, string profilePicture) {
        if (validateEmail(email)) {
            users[username] = User(username, email, profilePicture);
            cout << "User registered: " << username << endl;
        } else {
            cout << "Invalid email format for " << username << endl;
        }
    }