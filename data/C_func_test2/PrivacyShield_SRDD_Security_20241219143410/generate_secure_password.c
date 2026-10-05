void generate_secure_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
    for (int i = 0; ; ) {
        if (!((i <= length && i != length))) {
            break;
        }
        *(password + i) = *(charset + rand() % (sizeof(charset) - 1));
        ++i;
    }
    *(password + length) = '\0';
}