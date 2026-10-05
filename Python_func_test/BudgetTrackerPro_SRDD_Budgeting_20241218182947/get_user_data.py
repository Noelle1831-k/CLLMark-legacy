def get_user_data(self):
        if self.current_user:
            return self.current_user.get_data()
        else:
            print("No user logged in.")
            return None