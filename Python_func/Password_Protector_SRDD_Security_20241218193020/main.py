def main():
    # Initialize the encryption service with a persistent key
    encryption_service = EncryptionService()
    # Initialize the password manager with the encryption service
    password_manager = PasswordManager(encryption_service)
    # Initialize the synchronization service for cloud storage
    sync_service = SyncService()
    # Initialize the user interface with the password manager and sync service
    user_interface = UserInterface(password_manager, sync_service)
    # Display the main menu for user interaction
    user_interface.display_menu()