def create_goal_progress_bar(self, goal, current_balance):
        '''
        Creates a horizontal bar chart that shows the progress toward achieving a financial goal.
        Args:
            goal (Goal): A Goal object containing the target amount and goal description.
            current_balance (float): The current available balance towards the goal.
        '''
        target_amount = goal.target_amount
        progress = current_balance
        remaining = target_amount - progress
        # Plotting the goal progress bar
        plt.figure(figsize=(10, 2))
        labels = ['Progress', 'Remaining']
        sizes = [progress, remaining]
        colors = ['green', 'red']
        plt.barh(labels, sizes, color=colors, edgecolor='black')
        plt.xlabel('Amount ($)', fontsize=12)
        plt.title(f"Goal Progress: {goal.description}", fontsize=14)
        # Display percentage of goal achieved
        percentage = (progress / target_amount) * 100
        plt.text(progress + 100, 0, f'{percentage:.2f}%', va='center', fontsize=12)
        plt.tight_layout()
        plt.show()