void registerUser(string name, string email, string industry, bool isProfessional) {
        User newUser(name, email, industry, isProfessional);
        users.push_back(newUser);
        newUser.createProfile();
    }