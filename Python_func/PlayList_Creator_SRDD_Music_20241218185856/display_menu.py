def display_menu(self):
        '''
        Displays the main menu and handles user input.
        '''
        while True:
            print("\n--- PlayList Creator ---")
            print("1. Create Playlist")
            print("2. Delete Playlist")
            print("3. Add Song to Playlist")
            print("4. Remove Song from Playlist")
            print("5. Reorder Songs in Playlist")
            print("6. List Playlists")
            print("7. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.create_playlist()
            elif choice == '2':
                self.delete_playlist()
            elif choice == '3':
                self.add_song_to_playlist()
            elif choice == '4':
                self.remove_song_from_playlist()
            elif choice == '5':
                self.reorder_songs_in_playlist()
            elif choice == '6':
                self.list_playlists()
            elif choice == '7':
                break
            else:
                print("Invalid choice. Please try again.")