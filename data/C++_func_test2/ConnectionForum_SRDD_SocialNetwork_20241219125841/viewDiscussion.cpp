void Discussion::viewDiscussion() {
    cout << "Viewing discussion..." << endl;
    cout << "Discussion: " << topic << endl;
    cout << "Comments: " << endl;
    for (int i = 0; i < comments.size(); i++) {
        cout << "- " << comments[i] << endl;
    }
}