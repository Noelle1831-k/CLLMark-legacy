void store_user(struct User user) {
    printf("Storing user: Name: %s, Email: %s, Professional: %s\n",
           user.name, user.email, user.isProfessional ? "Yes" : "No");
}