def handle_user_input(self, choice):
        if choice == '1':
            self.set_dietary_preferences()
        elif choice == '2':
            self.view_recipes()
        elif choice == '3':
            self.generate_meal_plan()
        elif choice == '4':
            self.generate_grocery_list()
        elif choice == '5':
            self.calculate_nutritional_information()
        elif choice == '6':
            print("Exiting the application. Goodbye!")
            exit()
        else:
            print("Invalid choice. Please try again.")