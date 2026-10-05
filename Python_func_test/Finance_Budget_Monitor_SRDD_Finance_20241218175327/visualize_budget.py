def visualize_budget(self):
        visualization = Visualization(self.incomes, self.expenses)
        visualization.create_charts()