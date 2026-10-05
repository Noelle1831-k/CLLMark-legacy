def set_categories_or_tags(self):
        print("\n1. Add Category")
        print("2. Remove Category")
        print("3. Add Tag")
        print("4. Remove Tag")
        choice = input("Choose an option: ")
        if choice == "1":
            category = input("Enter category name: ")
            self.category_manager.add_category(category)
            print(f"Category '{category}' added successfully.")
        elif choice == "2":
            category = input("Enter category name: ")
            self.category_manager.remove_category(category)
            print(f"Category '{category}' removed successfully.")
        elif choice == "3":
            tag = input("Enter tag name: ")
            self.category_manager.add_tag(tag)
            print(f"Tag '{tag}' added successfully.")
        elif choice == "4":
            tag = input("Enter tag name: ")
            self.category_manager.remove_tag(tag)
            print(f"Tag '{tag}' removed successfully.")
        else:
            print("Invalid choice.")