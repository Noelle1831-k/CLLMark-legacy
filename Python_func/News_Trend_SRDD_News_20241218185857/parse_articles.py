def parse_articles(self, raw_data):
        '''
        Parse raw HTML to extract news content.
        '''
        print("Parsing articles...")
        parsed_data = []
        for html in raw_data:
            soup = BeautifulSoup(html, 'html.parser')
            titles = soup.find_all(['h1', 'h2', 'h3'])
            for title in titles:
                if title and title.text:
                    parsed_data.append(title.text.strip())
        return parsed_data