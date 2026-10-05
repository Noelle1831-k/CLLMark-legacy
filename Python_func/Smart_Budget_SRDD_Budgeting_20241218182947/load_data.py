def load_data(self):
        try:
            with open('user_data.pkl', 'rb') as file:
                user = pickle.load(file)
            print("Data loaded successfully.")
            return user
        except FileNotFoundError:
            print("No saved data found. Starting with a new user.")
            return User()