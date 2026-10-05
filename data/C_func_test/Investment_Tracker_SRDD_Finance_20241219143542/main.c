int main() {
    Portfolio *portfolio = create_portfolio();
    Investment *inv1 = create_investment("Stock A", 1000, "Growth");
    Investment *inv2 = create_investment("Bond B", 500, "Income");
    add_investment(portfolio, inv1);
    add_investment(portfolio, inv2);
    printf("Total Portfolio Value: %f\n", get_total_value(portfolio));
    plot_performance(portfolio);
    compare_benchmarks(portfolio);
    set_goal(portfolio, 2000);
    check_milestones(portfolio);
    free_portfolio(portfolio);
    return 0;
}