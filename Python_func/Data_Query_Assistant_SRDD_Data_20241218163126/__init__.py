def __init__(self, query_engine):
        self.query_engine = query_engine
        self.app = Flask(__name__)
        self.app.add_url_rule('/query', 'query', self.handle_request, methods=['POST'])