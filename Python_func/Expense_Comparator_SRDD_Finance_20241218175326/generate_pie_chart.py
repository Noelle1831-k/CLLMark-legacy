def generate_pie_chart(self, comparison_result):
        '''
        Generates a pie chart for the given comparison result.
        :param comparison_result: The comparison result to visualize.
        '''
        for range_name, data in comparison_result.items():
            labels = data.keys()
            sizes = data.values()
            plt.figure(figsize=(6, 6))
            plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=140)
            plt.title(f'Expense Distribution for {range_name}')
            plt.show()