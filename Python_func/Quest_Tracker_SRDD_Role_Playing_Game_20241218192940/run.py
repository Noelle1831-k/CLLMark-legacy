def run(self):
        while True:
            print("1. Add Quest")
            print("2. Update Quest")
            print("3. Complete Quest")
            print("4. List Quests")
            print("5. Add Reminder")
            print("6. Exit")
            choice = input("Choose an option: ")
            if choice == '1':
                self._add_quest()
            elif choice == '2':
                self._update_quest()
            elif choice == '3':
                self._complete_quest()
            elif choice == '4':
                self._list_quests()
            elif choice == '5':
                self._add_reminder()
            elif choice == '6':
                break