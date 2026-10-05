def run(self):
        self.load_data()
        print("Welcome to Budget Buddy!")
        while True:
            print("\n1. Add Account\n2. Remove Account\n3. Add Transaction\n4. Generate Report\n5. Set Budget\n6. Check Budget\n7. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.add_account()
            elif choice == '2':
                self.remove_account()
            elif choice == '3':
                self.add_transaction()
            elif choice == '4':
                self.generate_report()
            elif choice == '5':
                self.set_budget()
            elif choice == '6':
                self.check_budget()
            elif choice == '7':
                self.save_data()
                print("Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")