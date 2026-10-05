def main():
    '''
    Initialize the BudgetPlannerLite application and demonstrate its functionalities.
    '''
    try:
        # Initialize the database
        db = Database('budget_data.db')
        # Initialize the budget planner
        planner = BudgetPlanner(db)
        # Add some income entries
        planner.add_income(Income('Salary', 5000))
        planner.add_income(Income('Freelance', 1200))
        # Add some expense entries
        planner.add_expense(Expense('Rent', 1500))
        planner.add_expense(Expense('Groceries', 300))
        planner.add_expense(Expense('Utilities', 200))
        # Set a budgeting goal
        planner.set_goal(Goal('Save for vacation', 1000))
        # Display the budget breakdown
        viz = Visualization(planner)
        viz.display_budget_breakdown()
        # Demonstrate additional functionalities
        planner.edit_income(1, 'Updated Salary', 5500)
        planner.delete_expense(2)
        planner.edit_goal(1, 'Save for a new car', 2000)
        # Display updated budget breakdown
        viz.display_budget_breakdown()
    except Exception as e:
        print(f"An error occurred: {e}")