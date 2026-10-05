def save_data(self, data):
        # Save data to a JSON file
        with open('user_data.json', 'w') as f:
            json.dump(data, f)
        print("Data has been saved to user_data.json.")