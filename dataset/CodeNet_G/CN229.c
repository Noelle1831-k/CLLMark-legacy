int calculate_remaining_medals(int b, int r, int g, int c, int s, int t) {
    int initial_medals = 100;
    int medals_spent = 3 * (t - 5 * b - 3 * r);
    int medals_won_from_big_bonus = 5 * b * 15;
    int medals_won_from_regular_bonus = 3 * r * 15;
    int medals_won_from_grape = g * 15;
    int medals_won_from_cherry = c * 10;
    int total_medals_won = medals_won_from_big_bonus + medals_won_from_regular_bonus + medals_won_from_grape + medals_won_from_cherry;
    int remaining_medals = initial_medals - medals_spent + total_medals_won;
    return remaining_medals;
}