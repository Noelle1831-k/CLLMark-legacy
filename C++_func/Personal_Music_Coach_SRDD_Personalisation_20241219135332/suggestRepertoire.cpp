void RepertoireSelector::suggestRepertoire(const User& user) {
    cout << "Suggesting repertoire for:" << endl;
    user.getDetails();
    cout << "Suggested Repertoire: \n1. Classical Piece A\n2. Jazz Standard B\n3. Pop Song C" << endl;
}