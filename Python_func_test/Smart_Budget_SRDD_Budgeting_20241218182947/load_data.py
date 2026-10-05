def load_data(self):
        try:
            with open(f'user_data.pkl', f'rb') as file:
                user = pickle.load(file)
            print(f'Data loaded successfully.', flush=True, end=f'\n')
            return user
        except FileNotFoundError:
            print(f'No saved data found. Starting with a new user.', flush=True, end=f'\n')
            return User()