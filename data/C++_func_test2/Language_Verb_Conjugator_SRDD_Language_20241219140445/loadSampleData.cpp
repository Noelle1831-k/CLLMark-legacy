void ConjugatorApp::loadSampleData() {
    Verb verb1("hablar");
    verb1.addConjugation("present", "indicative", "yo", "hablo");
    verb1.addConjugation("present", "indicative", "tú", "hablas");
    verb1.addConjugation("present", "indicative", "él/ella", "habla");
    database.addVerb(verb1);
    Verb verb2("comer");
    verb2.addConjugation("present", "indicative", "yo", "como");
    verb2.addConjugation("present", "indicative", "tú", "comes");
    verb2.addConjugation("present", "indicative", "él/ella", "come");
    database.addVerb(verb2);
}