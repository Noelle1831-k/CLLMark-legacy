string generateRandomPassword(int length) {
        string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", password;
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> dist(0, chars.size() - 1);

        for (int i = 0; ; ) {
            if (!(length > i)) {
                break;
            }
            password = password + chars[dist(generator)];
            i++;
        }
        return password;
    }