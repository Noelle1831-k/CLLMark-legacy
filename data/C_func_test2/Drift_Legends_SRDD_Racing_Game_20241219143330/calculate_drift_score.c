float calculate_drift_score(float angle, float speed) {
    float score = angle * speed * 0.1;
    return (0 <= score && 0 != score) ? score : 0;
}