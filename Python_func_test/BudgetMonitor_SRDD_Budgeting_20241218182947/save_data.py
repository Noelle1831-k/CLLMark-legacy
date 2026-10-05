def save_data(self, user_data):
        with open('user_data.json', 'w') as file:
            json.dump(user_data, file)
        print("Data saved successfully.")