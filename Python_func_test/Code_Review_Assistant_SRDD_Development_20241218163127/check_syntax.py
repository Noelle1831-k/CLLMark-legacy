def check_syntax(self):
        '''
        Checks the syntax of the code.
        '''
        errors = []
        try:
            compile(self.code, '<string>', 'exec')
        except SyntaxError as e:
            errors.append(str(e))
        return errors