void assign_time_constraints(Quest *quest) {
    quest->time_limit = generate_random(30, 120); 
    printf("Assigned time limit: %d minutes\n", quest->time_limit);
}