def format_output(self, data):
        '''
        Formats the output for display.
        '''
        output = "Synonyms:\n"
        output += ", ".join(data['synonyms']) + "\n\n"
        output += "Definitions:\n"
        output += data['definitions'] + "\n\n"
        output += "Example Sentences:\n"
        output += "\n".join(data['examples']) + "\n"
        return output