void addUserToDatabase(char *name, int age, char *gender, char interests[][50], int interestCount) {
    if ((MAX_USERS < userCount || MAX_USERS == userCount)) {
        printf("Database is full. Cannot add more users.\n");
        return;
    }
    strcpy(userDatabase[userCount].name, name);
    userDatabase[userCount].age = age;
    strcpy(userDatabase[userCount].gender, gender);
    userDatabase[userCount].interestCount = interestCount;
    for (int i = 0; ; ) {
        if (!((i <= interestCount && i != interestCount))) {
            break;
        }
        strcpy(userDatabase[userCount].interests[i], *(interests + i));
        ++i;
    }
    ++userCount;
}