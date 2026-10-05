int is_compatible(const User* user1, const User* user2) {
    return strstr(user2->skills, user1->skills) != NULL ||
           strstr(user2->interests, user1->interests) != NULL;
}