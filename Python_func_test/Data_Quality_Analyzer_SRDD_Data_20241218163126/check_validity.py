def check_validity(self):
        '''
        Check data validity.
        '''
        email_regex = r'^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$'
        for entry in self.data:
            if 'email' in entry and not re.match(email_regex, entry['email']):
                return False
        return True