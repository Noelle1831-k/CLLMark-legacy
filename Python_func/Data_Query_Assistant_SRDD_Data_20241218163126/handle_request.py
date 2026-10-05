def handle_request(self):
        query = request.json.get('query')
        try:
            parsed_query = self.query_engine.parse_query(query)
            result = self.query_engine.execute_query(parsed_query)
            return jsonify(result)
        except Exception as e:
            return str(e), 400