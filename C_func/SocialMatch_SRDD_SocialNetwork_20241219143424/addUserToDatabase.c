void addUserToDatabase(char *name, int age, char *gender, char interests[][50], int interestCount) {
    if (userCount >= MAX_USERS) {
        printf("Database is full. Cannot add more users.\n");
        return;
    }
    strcpy(userDatabase[userCount].name, name);
    userDatabase[userCount].age = age;
    strcpy(userDatabase[userCount].gender, gender);
    userDatabase[userCount].interestCount = interestCount;
    for (int i = 0; i < interestCount; i++) {
        strcpy(userDatabase[userCount].interests[i], interests[i]);
    }
    userCount++;
}