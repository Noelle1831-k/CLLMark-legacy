def visualize_expenses(self):
        '''
        Create visualizations for the expenses.
        '''
        visualization = Visualization(self.expenses)
        visualization.create_pie_chart()
        visualization.create_bar_chart()