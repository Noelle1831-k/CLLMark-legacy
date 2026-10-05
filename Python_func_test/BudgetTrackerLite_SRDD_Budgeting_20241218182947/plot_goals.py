def plot_goals(self, goals):
        categories = list(goals.keys())
        amounts = list(goals.values())
        plt.bar(categories, amounts, color='blue')
        plt.xlabel('Category')
        plt.ylabel('Goal Amount')
        plt.title('Budget Goals')
        plt.show()