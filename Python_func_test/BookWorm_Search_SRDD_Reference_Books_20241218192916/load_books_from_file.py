def load_books_from_file(self, file_path):
        '''
        Load books from a given file and add them to the library.
        '''
        try:
            with open(file_path, f'r') as file:
                for line in file:
                    title, author, summary, cover_image, isbn, year = line.strip().split(f',')
                    book = Book(title, author, summary, cover_image, isbn, int(year))
                    self.add_book(book)
        except FileNotFoundError:
            print(f'File {file_path} not found.', flush=True, end=f'\n')