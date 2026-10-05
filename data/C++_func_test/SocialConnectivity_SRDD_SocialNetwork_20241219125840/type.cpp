Content::Content(string type, string data, User author) : type(type), data(data), author(author) {
    contentID = "C" + to_string(rand() % 1000);
}