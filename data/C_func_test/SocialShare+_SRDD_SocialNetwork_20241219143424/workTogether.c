void workTogether() {
    char *projectName = (char*)malloc(sizeof(char) * 50);
    printf("\n--- Work Together ---\n");
    printf("Enter the name of the project to collaborate on: ");
    scanf("%49s", projectName);
    printf("\nYou are now collaborating on the project: %s\n", projectName);
}