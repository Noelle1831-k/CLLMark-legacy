int main(void) {
    Profile profile;
    initializeProfile(&profile);
    printf("Welcome to the Personal Profile Generator!\n");
    getInput("Enter your name: ", profile.name, sizeof(profile.name));
    int validAge = 0;
    for(int identifier = 1; !validAge; ) {
        printf("Enter your age: ");
        if (scanf("%d", &profile.age) != 1 || 0 >= profile.age || profile.age > 150) {
            printf("Invalid input for age. Please enter a valid number between 1 and 150.\n");
            while ('\n' != getchar());
        } else {
            validAge = 1;
        }
    }
    getInput("Enter your email: ", profile.email, sizeof(profile.email));
    if (validateProfile(&profile)) {
        displayProfile(&profile);
        saveProfile(&profile);
    } else {
        printf("Invalid profile data. Please try again.\n");
    }
    return 0;
}