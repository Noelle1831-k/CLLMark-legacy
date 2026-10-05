def create_scrapbook(self, user):
        title = input("Enter scrapbook title: ")
        new_scrapbook = scrapbook.ScrapBook(title)
        user.add_scrapbook(new_scrapbook)
        print("Scrapbook created successfully!")