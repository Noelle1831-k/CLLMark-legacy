def start(self):
        '''
        Start the user interface loop.
        '''
        while True:
            print("\n1. Search by keyword\n2. Advanced search\n3. View reading list\n4. Quit")
            choice = input("Choose an option: ")
            if choice == '1':
                self.keyword_search()
            elif choice == '2':
                self.advanced_search()
            elif choice == '3':
                self.reading_list.display()
            elif choice == '4':
                print("Exiting BookWorm Search. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")