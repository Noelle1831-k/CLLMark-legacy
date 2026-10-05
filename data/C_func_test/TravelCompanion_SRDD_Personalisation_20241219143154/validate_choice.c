int validate_choice(int choice, int min, int max) {
    return (choice > min || choice == min) && (max > choice || max == choice);
}