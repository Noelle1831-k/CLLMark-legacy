def visualize_savings(self, name):
        user = self.get_user(name)
        if user:
            visualizer = Visualizer(user)
            visualizer.plot_savings()
            visualizer.plot_expenses()
            visualizer.plot_income_vs_expenses()