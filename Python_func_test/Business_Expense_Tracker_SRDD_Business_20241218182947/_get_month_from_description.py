def _get_month_from_description(self, description):
        '''
        Extracts the month from the expense description.
        Assumes the description contains a date in the format 'YYYY-MM-DD'.
        '''
        try:
            date = datetime.strptime(description.split()[-1], '%Y-%m-%d')
            return date.strftime('%B %Y')
        except ValueError:
            return 'Unknown'