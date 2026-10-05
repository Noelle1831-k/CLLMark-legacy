def main():
    """
    Initializes the InventoryManager and UserInterface objects and starts the application.
    """
    try:
        inventory_manager = InventoryManager()
        ui = UserInterface(inventory_manager)
        ui.run()
    except Exception as e:
        print(f"An unexpected error occurred: {e}")