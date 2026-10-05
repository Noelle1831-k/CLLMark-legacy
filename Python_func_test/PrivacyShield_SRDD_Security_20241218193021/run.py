def run(self):
        '''
        Run the application and provide a menu for user interaction.
        '''
        log_event("Application started.")
        while True:
            print("\nWelcome to PrivacyShield")
            print("1. Encrypt File")
            print("2. Decrypt File")
            print("3. Clean System")
            print("4. Enable Browser Protection")
            print("5. Manage Passwords")
            print("6. Exit")
            choice = input("Enter your choice: ")
            try:
                if choice == "1":
                    file_path = input("Enter file path to encrypt: ")
                    self.encryptor.encrypt_file(file_path, self.key)
                elif choice == "2":
                    file_path = input("Enter file path to decrypt: ")
                    self.encryptor.decrypt_file(file_path, self.key)
                elif choice == "3":
                    self.cleaner.clean_browsing_history("browser_path")
                elif choice == "4":
                    self.browser_extension.enable_protection()
                elif choice == "5":
                    self.manage_passwords()
                elif choice == "6":
                    log_event("Application terminated.")
                    print("Exiting PrivacyShield. Goodbye!")
                    break
                else:
                    print("Invalid choice! Please try again.")
            except Exception as e:
                log_event(f"Error occurred: {str(e)}")
                print(f"An error occurred: {str(e)}")