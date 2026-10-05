def create_app():
    app = Flask(__name__)
    app.secret_key = 'supersecretkey'
    @app.route('/')
    def index():
        return render_template('index.html')
    @app.route('/login', methods=['POST'])
    def login():
        username = request.form.get('username')
        session_id = login_user(username)
        if session_id:
            session['user_id'] = session_id
            return jsonify({'status': 'success'})
        return jsonify({'status': 'failure'})
    @app.route('/logout', methods=['POST'])
    def logout():
        logout_user(session.get('user_id'))
        session.pop('user_id', None)
        return jsonify({'status': 'success'})
    @app.route('/update_canvas', methods=['POST'])
    def update_canvas_route():
        data = request.json
        update_canvas(data)
        return jsonify({'status': 'success'})
    @app.route('/canvas_state', methods=['GET'])
    def canvas_state():
        return jsonify(get_canvas_state())
    return app