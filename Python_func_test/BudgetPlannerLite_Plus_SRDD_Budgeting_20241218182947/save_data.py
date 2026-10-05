def save_data(self, data):
        with open('budget_data.json', 'w') as file:
            json.dump(data, file)