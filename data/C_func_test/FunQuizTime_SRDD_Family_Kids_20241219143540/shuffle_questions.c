void shuffle_questions(Question *questions, int count) {
    for (int i = 0; i < count; i++) {
        int random_index = rand() % count;
        Question temp = questions[i];
        questions[i] = questions[random_index];
        questions[random_index] = temp;
    }
}