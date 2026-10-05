void Community::supportOthers() {
    cout << "Providing support to the community..." << endl;
    for (unsigned int i = 0; i < sharedExperiences.size(); i++) {
        cout << "Shared Experience " << i + 1 << ": " << sharedExperiences[i] << endl;
    }
}