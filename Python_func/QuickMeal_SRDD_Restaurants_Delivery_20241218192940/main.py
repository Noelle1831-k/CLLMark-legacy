def main():
    '''
    Initialize the QuickMeal application and manage the flow of the program.
    '''
    print("Welcome to QuickMeal - Fast and Easy Meal Ordering!")
    meals = fetch_meals()  # Fetch available meals from the restaurant module
    while True:
        print("\nMain Menu:")
        display_menu(meals)  # Display the list of available meal packages
        choice = get_user_choice(meals)  # Get user choice and validate input
        if choice == 'exit':
            print("Thank you for using QuickMeal. Goodbye!")
            break  # Exit the application gracefully
        order = create_order(meals[choice - 1])  # Create order based on user selection
        if order:
            if process_payment(order):  # Process the payment
                track_order(order)  # Track the order in real-time
                update_availability(order)  # Update meal availability
            else:
                print("Payment failed. Please try again.")  # Handle payment failure
        else:
            print("Error: Unable to create order. Please try again.")