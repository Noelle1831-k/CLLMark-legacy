def save_data(self, user):
        try:
            with open('user_data.pkl', 'wb') as file:
                pickle.dump(user, file)
            print("Data saved successfully.")
        except Exception as e:
            print(f"An error occurred while saving data: {e}")