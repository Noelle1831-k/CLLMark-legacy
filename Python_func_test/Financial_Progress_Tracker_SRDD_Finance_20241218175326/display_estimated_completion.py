def display_estimated_completion(self, goal):
        if goal.current_amount > 0:
            estimated_completion = (goal.target_amount - goal.current_amount) / goal.current_amount
            estimated_completion = math.ceil(estimated_completion * 100) / 100  # Round up to two decimal places
            print(f"Estimated Completion: {estimated_completion:.2f} times the current amount needed to reach the target.")
        else:
            print("Estimated Completion: Cannot be determined as the current amount is zero.")