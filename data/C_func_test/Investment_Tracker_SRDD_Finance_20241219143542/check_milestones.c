void check_milestones(Portfolio *portfolio) {
    double total = get_total_value(portfolio);
    if (total >= portfolio->goal) {
        printf("Congratulations! You've reached your investment goal of %f.\n", portfolio->goal);
    } else {
        printf("You are %f away from reaching your goal.\n", portfolio->goal - total);
    }
}