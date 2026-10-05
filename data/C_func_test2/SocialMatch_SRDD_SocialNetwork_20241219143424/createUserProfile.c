void createUserProfile() {
    char name[50];
    int age;
    char gender[10];
    char interests[5][50];
    int interestCount;
    printf("Enter your name: ");
    getValidatedStringInput(name, 50); 
    printf("Enter your age: ");
    age = getValidatedIntegerInput(); 
    printf("Enter your gender (Male/Female/Other): ");
    getValidatedStringInput(gender, 10); 
    printf("How many interests do you have (max 5)? ");
    interestCount = getValidatedIntegerInput(); 
    if (interestCount > 5) interestCount = 5;
    for (int i = 0; i < interestCount; i++) {
        printf("Enter interest %d: ", i + 1);
        getValidatedStringInput(interests[i], 50); 
    }
    addUserToDatabase(name, age, gender, interests, interestCount); 
    printf("Profile created successfully!\n");
}