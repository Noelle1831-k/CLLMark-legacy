char* leftRotate(char* s, int d) {
    int n = strlen(s);
    char* rotated = (char*)malloc((n + 1) * sizeof(char));
    if (rotated == NULL) return NULL;
    for (int i = 0; i < n; i++) {
        rotated[i] = s[(i + d) % n];
    }
    rotated[n] = '\0';
    return rotated;
}