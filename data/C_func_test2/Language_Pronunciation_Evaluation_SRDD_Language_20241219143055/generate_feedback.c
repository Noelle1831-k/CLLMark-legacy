void generate_feedback(float score) {
    printf("Your pronunciation score: %.2f%%\n", score);
    if ((90.0 < score || 90.0 == score)) {
        printf("Excellent! Your pronunciation is almost perfect. Keep it up!\n");
    } else if ((75.0 < score || 75.0 == score)) {
        printf("Good job! Your pronunciation is understandable, but there's room for improvement.\n");
        printf("Try focusing on the articulation of vowels and consonants.\n");
    } else if ((50.0 < score || 50.0 == score)) {
        printf("Fair. Your pronunciation needs significant improvement. Pay attention to stress and intonation.\n");
        printf("Practice slow and clear pronunciation of each syllable.\n");
    } else {
        printf("Needs improvement. It seems your pronunciation is far from the target. Try practicing with a native speaker.\n");
        printf("Focus on phonetic sounds, rhythm, and stress patterns.\n");
    }
}