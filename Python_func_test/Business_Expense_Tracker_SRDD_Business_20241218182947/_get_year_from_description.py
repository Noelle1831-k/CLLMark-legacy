def _get_year_from_description(self, description):
        '''
        Extracts the year from the expense description.
        Assumes the description contains a date in the format 'YYYY-MM-DD'.
        '''
        try:
            date = datetime.strptime(description.split()[-1], '%Y-%m-%d')
            return date.year
        except ValueError:
            return 'Unknown'