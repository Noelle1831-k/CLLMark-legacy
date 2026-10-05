def save_data(self, user):
        with open('user_data.pkl', 'wb') as file:
            pickle.dump(user, file)
        print("Data saved successfully.")