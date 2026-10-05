void addChallengeToHunt(string huntName, string description, string clue, string location) {
        auto it = find_if(hunts.begin(), hunts.end(), [&huntName](ScavengerHunt& hunt) {
            return hunt.huntName == huntName;
        });
        if (it != hunts.end()) {
            it->challenges.push_back(Challenge(description, clue, location));
            cout << "Challenge added to hunt: " << huntName << endl;
        } else {
            cout << "Hunt not found: " << huntName << endl;
        }
    }