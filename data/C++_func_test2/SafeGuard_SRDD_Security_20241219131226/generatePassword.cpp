void generatePassword(int length) {
        string password = generateRandomPassword(length);
        logger->logEvent("Generated password: " + password);
    }