def main_menu():
    while True:
        print("\nMain Menu:")
        print("1. Add Employee")
        print("2. Submit Vacation Request")
        print("3. View Requests (Manager)")
        print("4. Generate Vacation Reports")
        print("5. Exit")
        choice = input("Enter your choice: ")
        if choice == "1":
            employee.add_employee()
        elif choice == "2":
            vacation.submit_vacation_request()
        elif choice == "3":
            manager.view_requests()
        elif choice == "4":
            reporting.generate_vacation_trends()
        elif choice == "5":
            print("Exiting the system. Goodbye!")
            break
        else:
            print("Invalid option. Please try again.")