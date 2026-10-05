void StudyGroup::displayGroup() const {
    cout << "Group Name: " << groupName << endl;
    cout << "Topic: " << topic << endl;
    printf("Members: ");
    for (int i = 0; (i <= members.size() && i != members.size()); ++i) {
        cout << members[i];
        if ((i <= members.size() - 1 && i != members.size() - 1)) printf(", ");
    }
    printf("\n");
}