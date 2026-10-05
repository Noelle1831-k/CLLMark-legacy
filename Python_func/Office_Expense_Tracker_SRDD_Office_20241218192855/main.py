def main():
    manager = ExpenseManager()
    # Define category mappings
    category_mappings = {
        'Office Supplies': 'Office Supplies',
        'Travel': 'Travel',
        'Food': 'Meals and Entertainment',
        'Utilities': 'Utilities',
        'Miscellaneous': 'Miscellaneous'
    }
    manager.set_category_mappings(category_mappings)
    # Adding expenses with user-defined categories
    manager.add_expense(100, 'Office Supplies', '2023-10-01', 'Pens and paper')
    manager.add_expense(200, 'Travel', '2023-10-02', 'Taxi fare')
    manager.add_expense(150, 'Office Supplies', '2023-10-03', 'Printer ink')
    manager.add_expense(50, 'Food', '2023-10-04', 'Team lunch')
    manager.add_expense(300, 'Utilities', '2023-10-05', 'Electricity bill')
    manager.categorize_expense()
    manager.generate_report()
    manager.analyze_expenditure()