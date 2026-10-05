def search_by_title(shelves, title):
    results = []
    for shelf in shelves:
        for book in shelf.books:
            if title.lower() in book.title.lower():
                results.append(book)
    return results