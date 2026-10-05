Group::Group(const string& name, const string& desc, User* creator) : groupName(name), description(desc) {
    users.push_back(creator);
}