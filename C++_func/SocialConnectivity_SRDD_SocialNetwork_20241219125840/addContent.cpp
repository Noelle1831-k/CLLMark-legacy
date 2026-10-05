void SocialNetwork::addContent(Content content) {
    this->content.push_back(content);
    cout << "Content added: " << content.getData() << endl;
}