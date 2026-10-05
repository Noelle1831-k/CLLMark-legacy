def __init__(self):
        self.words = {
            'English': {
                'Easy': ['cat', 'dog', 'fish'],
                'Medium': ['elephant', 'giraffe', 'dolphin'],
                'Hard': ['hippopotamus', 'rhinoceros', 'chrysanthemum']
            },
            'Spanish': {
                'Easy': ['gato', 'perro', 'pez'],
                'Medium': ['elefante', 'jirafa', 'delfín'],
                'Hard': ['hipopótamo', 'rinoceronte', 'crisantemo']
            },
            'French': {
                'Easy': ['chat', 'chien', 'poisson'],
                'Medium': ['éléphant', 'girafe', 'dauphin'],
                'Hard': ['hippopotame', 'rhinocéros', 'chrysanthème']
            }
        }
        self.load_words()