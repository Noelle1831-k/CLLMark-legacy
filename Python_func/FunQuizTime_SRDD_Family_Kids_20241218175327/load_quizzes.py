def load_quizzes(self):
        '''
        Loads quizzes from a data source.
        '''
        self.quizzes = self.data_loader.load_data("quizzes.json")
        return self.quizzes