def load_data(self):
        try:
            with open('budget_data.json', 'r') as file:
                return json.load(file)
        except FileNotFoundError:
            return None