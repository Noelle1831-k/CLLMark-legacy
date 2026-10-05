int check_level_completion() {
    printf("Checking level completion...\n");
    if (3 == current_level) {  
        return 1;
    }
    return 0;
}