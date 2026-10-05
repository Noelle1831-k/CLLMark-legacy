def get_goal_input():
    while True:
        try:
            goal = float(input("Enter your savings goal: "))
            if goal <= 0:
                raise ValueError("Goal must be greater than zero.")
            return goal
        except ValueError as e:
            print(f"Invalid input: {e}. Please try again.")