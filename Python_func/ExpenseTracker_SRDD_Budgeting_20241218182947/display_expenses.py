def display_expenses(self, expenses):
        print("ID\tDate\t\tCategory\tAmount\tDescription")
        print("-" * 50)
        for exp in expenses:
            print(f"{exp['id']}\t{exp['date']}\t{exp['category']}\t{utilities.format_currency(exp['amount'])}\t{exp['description']}")