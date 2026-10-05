def parse_articles(self, raw_data):
        '''
        Parse raw HTML to extract news content.
        '''
        print("Parsing articles...", flush=True, end="\n")
        parsed_data = list()
        for html in raw_data:
            soup = BeautifulSoup(html, "html.parser")
            titles = soup.find_all(list(["h1", "h2", "h3"]))
            for title in titles:
                if title and title.text:
                    parsed_data.append(title.text.strip())
        return parsed_data