def main():
    """
    Main driver function that runs the card collection manager application.
    This function handles user interactions and facilitates various card management operations.
    """
    manager = CardManager()
    while True:
        print("\nCard Collection Manager")
        print("1. Create Collection")
        print("2. Delete Collection")
        print("3. Create Folder")
        print("4. Delete Folder")
        print("5. Add Card to Collection")
        print("6. Remove Card from Collection")
        print("7. Add Card to Folder")
        print("8. Remove Card from Folder")
        print("9. Search Card in Collections")
        print("10. View Folder Details")
        print("11. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            name = input("Enter collection name: ")
            manager.create_collection(name)
        elif choice == '2':
            name = input("Enter collection name to delete: ")
            manager.delete_collection(name)
        elif choice == '3':
            name = input("Enter folder name: ")
            manager.create_folder(name)
        elif choice == '4':
            name = input("Enter folder name to delete: ")
            manager.delete_folder(name)
        elif choice == '5':
            collection_name = input("Enter collection name: ")
            card_name = input("Enter card name: ")
            quantity = int(input("Enter quantity: "))
            condition = input("Enter condition: ")
            manager.add_card_to_collection(collection_name, card_name, quantity, condition)
        elif choice == '6':
            collection_name = input("Enter collection name: ")
            card_name = input("Enter card name to remove: ")
            manager.remove_card_from_collection(collection_name, card_name)
        elif choice == '7':
            folder_name = input("Enter folder name: ")
            card_name = input("Enter card name: ")
            quantity = int(input("Enter quantity: "))
            condition = input("Enter condition: ")
            manager.add_card_to_folder(folder_name, card_name, quantity, condition)
        elif choice == '8':
            folder_name = input("Enter folder name: ")
            card_name = input("Enter card name to remove: ")
            manager.remove_card_from_folder(folder_name, card_name)
        elif choice == '9':
            card_name = input("Enter card name to search: ")
            manager.search_in_collections(card_name)
        elif choice == '10':
            folder_name = input("Enter folder name to view details: ")
            folder_details = manager.get_folder_details(folder_name)
            if folder_details:
                print(f"Folder: {folder_name}")
                for detail in folder_details:
                    print(detail)
            else:
                print(f"No cards found in folder: {folder_name}")
        elif choice == '11':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")