int check_level_completion() {
    printf("Checking level completion...\n");
    if (current_level == 3) {  
        return 1;
    }
    return 0;
}