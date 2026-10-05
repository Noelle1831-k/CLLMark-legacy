bool validateInput(const string& input) {
        string validScales[] = {"C Major", "A Minor", "G Major", "E Minor", "F Major", "D Minor"};
        for (int i = 0; i < 6; i++) {
            if (input == validScales[i]) {
                return true;
            }
        }
        return false;
    }