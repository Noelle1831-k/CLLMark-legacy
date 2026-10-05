def filter_by_author(shelves, author):
    results = []
    for shelf in shelves:
        for book in shelf.books:
            if author.lower() in book.author.lower():
                results.append(book)
    return results