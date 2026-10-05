def customize_categories(self):
        '''
        Customize categories and tags for quests.
        '''
        print("Customizing categories and tags...")
        categories = []
        while True:
            print("\n1. Add Category")
            print("2. Remove Category")
            print("3. View Categories")
            print("0. Done")
            choice = input("Enter your choice: ")
            if choice == '1':
                category = input("Enter new category name: ")
                if category not in categories:
                    categories.append(category)
                    print(f"Category '{category}' added.")
                else:
                    print(f"Category '{category}' already exists.")
            elif choice == '2':
                category = input("Enter category name to remove: ")
                if category in categories:
                    categories.remove(category)
                    print(f"Category '{category}' removed.")
                else:
                    print(f"Category '{category}' not found.")
            elif choice == '3':
                print("Current Categories:")
                for category in categories:
                    print(f"- {category}")
            elif choice == '0':
                print("Finished customizing categories.")
                break
            else:
                print("Invalid choice. Please try again.")