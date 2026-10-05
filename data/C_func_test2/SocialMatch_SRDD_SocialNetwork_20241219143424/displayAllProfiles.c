void displayAllProfiles() {
    if (userCount == 0) {
        printf("No profiles found.\n");
        return;
    }
    for (int i = 0; i < userCount; i++) {
        printf("\nProfile %d:\n", i + 1);
        printf("Name: %s\n", userDatabase[i].name);
        printf("Age: %d\n", userDatabase[i].age);
        printf("Gender: %s\n", userDatabase[i].gender);
        printf("Interests: ");
        for (int j = 0; j < userDatabase[i].interestCount; j++) {
            printf("%s ", userDatabase[i].interests[j]);
        }
        printf("\n");
    }
}