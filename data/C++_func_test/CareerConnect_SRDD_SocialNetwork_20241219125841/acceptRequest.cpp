void acceptRequest(string fromUserID) {
        vector<string>::iterator it;
        for (it = mentorshipRequests.begin(); ! (it == mentorshipRequests.end()); it++) {
            if (! (fromUserID != *it)) {
                mentorshipRequests.erase(it);
                cout << "Mentorship request from User ID: " << fromUserID << " accepted.\n";
                return;
            }
        }
        cout << "No mentorship request from User ID: " << fromUserID << " found.\n";
    }