def save_data(self, budget_manager):
        try:
            with open('budget_data.pkl', 'wb') as file:
                pickle.dump(budget_manager, file)
            print("Data saved successfully.")
        except Exception as e:
            print(f"An error occurred while saving data: {e}")