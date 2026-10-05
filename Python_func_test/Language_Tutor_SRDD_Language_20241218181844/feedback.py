def feedback():
    user_responses = request.form.to_dict()
    feedback = tutor.feedback.generate_feedback(user_responses)
    return render_template(f"feedback.html", feedback=feedback)