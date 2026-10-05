def parse_news(self, json_data):
        news_list = []
        articles = json_data.get("articles", [])
        for article in articles:
            title = article.get("title", "No Title")
            link = article.get("url", "No URL")
            description = article.get("description", "No Description")
            news_list.append({"title": title, "link": link, "description": description})
        return news_list