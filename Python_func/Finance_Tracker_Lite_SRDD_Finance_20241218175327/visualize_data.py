def visualize_data(self):
        visualizer = Visualizer(self.income_entries, self.expense_entries)
        visualizer.create_pie_chart()
        visualizer.create_bar_chart()