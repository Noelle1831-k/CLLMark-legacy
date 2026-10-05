def levenshtein_distance(self, source, target):
        '''
        Computes the Levenshtein distance between two words.
        '''
        if len(source) < len(target):
            return self.levenshtein_distance(target, source)
        if len(target) == 0:
            return len(source)
        previous_row = range(len(target) + 1)
        for i, sc in enumerate(source, 1):
            current_row = [i]
            for j, tc in enumerate(target, 1):
                insertions = previous_row[j] + 1
                deletions = current_row[j - 1] + 1
                substitutions = previous_row[j - 1] + (sc != tc)
                current_row.append(min(insertions, deletions, substitutions))
            previous_row = current_row
        return previous_row[-1]