def load_user_data(self, user_id):
        '''
        Loads user data from a local file.
        '''
        try:
            with open(f"{user_id}.dat", "rb") as f:
                return pickle.load(f)
        except FileNotFoundError:
            return None