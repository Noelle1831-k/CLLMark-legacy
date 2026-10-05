def save_user_data(self, user):
        '''
        Saves user data to a local file.
        '''
        with open(f"{user.user_id}.dat", "wb") as f:
            pickle.dump(user, f)