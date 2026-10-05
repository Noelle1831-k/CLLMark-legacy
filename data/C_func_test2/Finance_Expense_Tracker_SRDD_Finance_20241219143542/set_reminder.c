void set_reminder() {
    char *message = (char*)malloc(sizeof(char) * 100);
    printf("Enter reminder message: ");
    scanf("%s", message);
    printf("Reminder set: %s\n", message);
}