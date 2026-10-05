def display_results(self, results):
        '''
        Display the search results to the user.
        '''
        if not results:
            print("No books found.")
        else:
            for index, book in enumerate(results):
                print(f"{index + 1}. {book}")
            self.handle_selection(results)