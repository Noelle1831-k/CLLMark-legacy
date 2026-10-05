def run(self, shield_guard):
        '''Main loop for user interaction.'''
        while True:
            self.display_menu()
            choice = self.get_user_input("Choose an option: ")
            if choice == "1":
                monitor_status = shield_guard.monitor.detector is not None
                browsing_status = shield_guard.browser.protection_enabled
                self.show_system_status(monitor_status, browsing_status)
            elif choice == "2":
                self.password_management(shield_guard.password_manager)
            elif choice == "3":
                shield_guard.browser.enable_protection()
            elif choice == "4":
                self.add_threat_to_database(shield_guard.threat_db)
            elif choice == "5":
                self.display("Exiting ShieldGuard. Goodbye!")
                break
            else:
                self.display("Invalid choice. Please select a valid option.")