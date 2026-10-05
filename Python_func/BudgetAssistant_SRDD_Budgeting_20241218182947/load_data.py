def load_data(self):
        try:
            with open('user_data.pkl', 'rb') as file:
                user = pickle.load(file)
            print("Data loaded successfully.")
            return user
        except FileNotFoundError:
            print("No saved data found.")
            return None
        except Exception as e:
            print(f"An error occurred while loading data: {e}")
            return None