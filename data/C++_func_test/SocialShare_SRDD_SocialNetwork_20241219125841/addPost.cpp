void User::addPost() {
    string content;
    printf("Enter post content: ");
    cin.ignore();
    getline(cin, content);
    Post newPost(content);
    posts.push_back(newPost);
    printf("Post added successfully!\n");
}