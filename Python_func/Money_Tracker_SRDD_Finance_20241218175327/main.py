def main():
    user = User("John Doe", "john.doe@example.com")
    # Adding income and expenses with dates
    user.add_income(5000, "Salary", "2023-10-01")
    user.add_expense(150, "Food", "2023-10-02")
    user.add_expense(100, "Transportation", "2023-10-03")
    # Setting up categories
    food_category = Category("Food")
    transport_category = Category("Transportation")
    entertainment_category = Category("Entertainment")
    food_category.add_transaction(150, "Lunch at restaurant", "2023-10-02")
    transport_category.add_transaction(100, "Bus fare", "2023-10-03")
    entertainment_category.add_transaction(200, "Movie tickets", "2023-10-04")
    user.add_category(food_category)
    user.add_category(transport_category)
    user.add_category(entertainment_category)
    # Setting up budget
    budget = Budget()
    budget.set_goal("Food", 200)
    budget.set_goal("Transportation", 150)
    budget.set_goal("Entertainment", 250)
    # Visualization
    viz = Visualization()
    viz.generate_pie_chart(user)
    viz.generate_bar_chart(user)
    viz.generate_category_pie_chart(user)
    viz.generate_category_bar_chart(user)
    viz.generate_line_chart(user)
    # Summary
    print(user.get_summary())