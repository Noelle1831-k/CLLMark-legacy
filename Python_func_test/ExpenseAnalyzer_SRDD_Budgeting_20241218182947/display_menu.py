def display_menu(self):
        print("\n--- Expense Analyzer Menu ---")
        for key, value in self.menu_options.items():
            print(f"{key}. {value}")
        print("-----------------------------")