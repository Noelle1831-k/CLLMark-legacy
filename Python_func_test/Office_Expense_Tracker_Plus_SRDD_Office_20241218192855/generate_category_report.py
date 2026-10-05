def generate_category_report(self, expenses, category):
        '''
        Generates a report for a specific category over time.
        Parameters:
        expenses (list): A list of Expense objects.
        category (str): The category to generate the report for.
        '''
        category_data = defaultdict(float)
        for expense in expenses:
            if expense.category == category:
                month_year = expense.date.strftime("%B %Y")
                category_data[month_year] += expense.amount
        print(f"Category Report for {category}:")
        for month_year, total in category_data.items():
            print(f"{month_year}: {format_currency(total)}")
        print("-" * 40)