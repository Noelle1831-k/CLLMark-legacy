def handle_selection(self, results):
        '''
        Handle user selection from the search results.
        '''
        choice = input("Enter the number of the book to add to your reading list, or 'q' to quit: ")
        if choice.isdigit():
            index = int(choice) - 1
            if 0 <= index < len(results):
                self.reading_list.add_book(results[index])
                print(f"Added '{results[index].title}' to your reading list.")