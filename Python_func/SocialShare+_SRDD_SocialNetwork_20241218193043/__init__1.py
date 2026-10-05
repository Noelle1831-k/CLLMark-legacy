def __init__(self, author, content_type, data):
        self.content_id = Content._id_counter
        Content._id_counter += 1
        self.author = author
        self.content_type = content_type
        self.data = data
        self.likes = 0
        self.comments = []