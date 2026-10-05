void createFamily() {
    char familyName[50];
    printf("Enter your family name: ");
    scanf("%s", familyName);
    printf("Family profile created for the %s family.\n", familyName);
    familyProgress = 0; 
}