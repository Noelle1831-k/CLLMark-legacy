def run(self):
        '''
        Run the user interface loop.
        '''
        while True:
            print("\nMonster Encyclopedia")
            print("1. Add Monster")
            print("2. Update Monster")
            print("3. Mark Monster as Defeated")
            print("4. Search Monster")
            print("5. Sort Monsters")
            print("6. Display All Monsters")
            print("7. Exit")
            choice = input("Choose an option: ")
            if choice == '1':
                self.add_monster()
            elif choice == '2':
                self.update_monster()
            elif choice == '3':
                self.mark_monster_defeated()
            elif choice == '4':
                self.search_monster()
            elif choice == '5':
                self.sort_monsters()
            elif choice == '6':
                self.display_all_monsters()
            elif choice == '7':
                print("Exiting the application. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")