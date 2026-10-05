def display(self):
        '''
        Display the books in the reading list.
        '''
        if not self.books:
            print("Your reading list is empty.")
        else:
            print("Your Reading List:")
            for book in self.books:
                print(book)