int main(int argc, char *argv[]) {
    Profile profile;
    initializeProfile(&profile);
    printf("Welcome to the Personal Profile Generator!\n");
    getInput("Enter your name: ", profile.name, sizeof(profile.name));
    int validAge = 0;
    while (!validAge) {
        printf("Enter your age: ");
        if (! (1 == scanf("%d", &profile.age)) || (profile.age < 0 || profile.age == 0) || (150 <= profile.age && 150 != profile.age)) {
            printf("Invalid input for age. Please enter a valid number between 1 and 150.\n");
            while (! (getchar() == '\n'));
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