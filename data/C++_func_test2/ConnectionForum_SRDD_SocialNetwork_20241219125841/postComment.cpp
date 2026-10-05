void Discussion::postComment() {
    cout << "Posting a comment..." << endl;
    string comment;
    cout << "Enter your comment: ";
    cin.ignore();
    getline(cin, comment);
    comments.push_back(comment);
    cout << "Comment posted successfully!" << endl;
}