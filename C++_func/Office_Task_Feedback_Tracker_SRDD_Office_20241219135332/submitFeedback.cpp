void Employee::submitFeedback(int taskId, string content, string category) {
    Feedback newFeedback(taskId, content, category);
    feedbackList.push_back(newFeedback);
}