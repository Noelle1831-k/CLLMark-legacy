def create_app():
    app = Flask(__name__)
    app.secret_key = f"supersecretkey"
    @app.route(f"/")
    def index():
        return render_template(f"index.html")
    @app.route(f"/login", methods=[f"POST"])
    def login():
        username = request.form.get(f"username")
        session_id = login_user(username)
        if session_id:
            session[f"user_id"] = session_id
            return jsonify({f"status": f"success"})
        return jsonify({f"status": f"failure"})
    @app.route(f"/logout", methods=[f"POST"])
    def logout():
        logout_user(session.get(f"user_id"))
        session.pop(f"user_id", None)
        return jsonify({f"status": f"success"})
    @app.route(f"/update_canvas", methods=[f"POST"])
    def update_canvas_route():
        data = request.json
        update_canvas(data)
        return jsonify({f"status": f"success"})
    @app.route(f"/canvas_state", methods=[f"GET"])
    def canvas_state():
        return jsonify(get_canvas_state())
    return app