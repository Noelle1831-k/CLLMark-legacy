void Community::viewDiscussions() {
    cout << "Community Discussions:" << endl;
    for (const auto &discussion : discussions) {
        cout << discussion << endl;
    }
}