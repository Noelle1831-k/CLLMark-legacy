void Community::askQuestion() {
    string question;
    cout << "Enter your question: ";
    cin.ignore();
    getline(cin, question);
    discussions.push_back("Q: " + question);
    cout << "Question added successfully!" << endl;
}