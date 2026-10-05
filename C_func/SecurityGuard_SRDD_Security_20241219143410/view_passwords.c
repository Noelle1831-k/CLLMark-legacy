void view_passwords() {
    for (int i = 0; i < password_count; i++) {
        printf("Website: %s, Username: %s, Password: %s\n",
               password_store[i].website, password_store[i].username, password_store[i].password);
    }
}