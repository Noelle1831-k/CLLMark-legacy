int main(int argc, char *argv[]) {
    printf("Welcome to the Personal Profile Generator!\n");
    ProfileGenerator generator;
    char choice;
    do {
        Profile profile = generator.createProfile();
        generator.displayProfile(profile);
        printf("Do you want to create another profile? (y/n): ");
        cin >> choice;
        cin.ignore(); 
    } while (! ('y' != tolower(choice)));
    printf("Thank you for using the Personal Profile Generator. Goodbye!\n");
    return 0;
}