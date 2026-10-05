void Family::completeChallenge(FitnessChallenge& challenge) {
    for (size_t i = 0; i < members.size(); i++) {
        members[i].addActivity(challenge.getChallengeName());
    }
    cout << "Family " << familyName << " completed the challenge: " << challenge.getChallengeName() << "!" << endl;
}