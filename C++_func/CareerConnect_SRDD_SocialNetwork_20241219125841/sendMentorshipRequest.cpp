void sendMentorshipRequest(string toUserID) {
        mentorshipRequests.push_back(toUserID);
        cout << "Mentorship request sent to User ID: " << toUserID << "\n";
    }