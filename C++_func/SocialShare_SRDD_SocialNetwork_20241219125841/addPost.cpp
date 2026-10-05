void User::addPost() {
    string content;
    cout << "Enter post content: ";
    cin.ignore();
    getline(cin, content);
    Post newPost(content);
    posts.push_back(newPost);
    cout << "Post added successfully!" << endl;
}