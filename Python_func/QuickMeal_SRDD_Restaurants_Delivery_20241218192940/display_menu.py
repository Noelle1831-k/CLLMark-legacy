def display_menu(meals):
    '''
    Display the list of available meal packages to the user in a structured format.
    '''
    print("\nAvailable Meal Packages:")
    for index, meal in enumerate(meals):
        print(f"{index + 1}. {meal['name']} - {meal['price']}")