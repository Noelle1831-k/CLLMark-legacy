char* generateUniqueId() {
    static int id = 0;
    char *uniqueId = (char *)malloc(10 * sizeof(char));
    sprintf(uniqueId, "T%04d", ++id);
    return uniqueId;
}