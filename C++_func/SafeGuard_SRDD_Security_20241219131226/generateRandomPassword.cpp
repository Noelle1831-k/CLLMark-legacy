string generateRandomPassword(int length) {
        string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> dist(0, chars.size() - 1);
        string password;
        for (int i = 0; i < length; i++) {
            password += chars[dist(generator)];
        }
        return password;
    }