void searchUsersByIndustry(string industry) {
        cout << "Users in industry: " << industry << "\n";
        for (vector<User>::iterator it = users.begin(); it != users.end(); it++) {
            if (it->getIndustry() == industry) {
                it->viewProfile();
            }
        }
    }