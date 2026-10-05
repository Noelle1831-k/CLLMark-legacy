int main() {
    SocialQuestApp *app = create_social_quest_app();
    run_social_quest_app(app);
    destroy_social_quest_app(app);
    return 0;
}