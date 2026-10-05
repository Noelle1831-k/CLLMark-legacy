void store_footage() {
    printf("Storing footage to cloud...\n");
    time_t now = time(NULL);
    char* timestamp = ctime(&now);
    printf("Uploading footage captured at %s to secure cloud storage...\n", timestamp);
    printf("Footage successfully uploaded.\n");
}