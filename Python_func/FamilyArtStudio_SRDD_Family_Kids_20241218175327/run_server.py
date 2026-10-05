def run_server():
    app = create_app()
    app.run(debug=True)