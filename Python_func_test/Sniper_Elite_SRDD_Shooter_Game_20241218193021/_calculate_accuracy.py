def _calculate_accuracy(self, hits, total):
        '''
        Calculates the sniper's accuracy as a percentage.
        '''
        return (hits / total) * 100 if total > 0 else 0