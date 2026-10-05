void Party::displayMembers() {
    for (size_t i = 0; i < members.size(); i++) {
        cout << members[i].getName() << " (" << members[i].getClassType() << ")" << endl;
    }
}