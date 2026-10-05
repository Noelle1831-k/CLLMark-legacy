def update_canvas_route():
        data = request.json
        update_canvas(data)
        return jsonify({'status': 'success'})