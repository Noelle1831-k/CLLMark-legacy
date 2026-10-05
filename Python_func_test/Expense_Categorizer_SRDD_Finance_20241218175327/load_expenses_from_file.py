def load_expenses_from_file(self, file_path, expenses):
        '''
        Load expenses from a JSON file.
        '''
        try:
            with open(file_path, "r") as file:
                data = json.load(file)
                for item in data:
                    expense = Expense(item["amount"], item["description"], item["category"], item["date"])
                    expenses.append(expense)
        except FileNotFoundError:
            print("No previous expenses data found. Starting fresh.", flush=True, end="\n")