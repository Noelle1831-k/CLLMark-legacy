def generate_bar_chart(self, data):
        labels = ['Savings', 'Goal']
        values = [data['savings'], data['savings_goal']]
        plt.bar(labels, values)
        plt.title('Savings Progress')
        plt.show()