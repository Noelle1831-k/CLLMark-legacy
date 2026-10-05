def plot_savings_progress(self, savings_goal):
        goal = savings_goal.goal
        savings_history = savings_goal.savings_history
        plt.plot(savings_history, label="Savings Over Time")
        plt.axhline(y=goal, color='r', linestyle='--', label="Goal")
        plt.title("Savings Progress")
        plt.xlabel("Time")
        plt.ylabel("Savings")
        plt.legend()
        plt.show()