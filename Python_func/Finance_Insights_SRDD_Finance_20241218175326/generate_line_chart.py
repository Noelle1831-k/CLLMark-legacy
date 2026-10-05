def generate_line_chart(self, data):
        '''
        Generate a line chart for financial trends.
        '''
        time_points = np.arange(1, len(data['income']) + 1)
        plt.figure(figsize=(10, 7))
        plt.plot(time_points, data['income'], label='Income', marker='o', linestyle='-', color='blue')
        plt.plot(time_points, data['expenses'], label='Expenses', marker='o', linestyle='-', color='orange')
        plt.xlabel('Time')
        plt.ylabel('Amount')
        plt.title('Financial Trends Over Time')
        plt.legend()
        plt.grid(True)
        for i, (income, expense) in enumerate(zip(data['income'], data['expenses'])):
            plt.annotate(f'{income}', (time_points[i], income), textcoords="offset points", xytext=(0,10), ha='center')
            plt.annotate(f'{expense}', (time_points[i], expense), textcoords="offset points", xytext=(0,-15), ha='center')
        plt.show()