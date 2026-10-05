# Étude dynamique UML - Diagramme d'activités et de séquence (Clinique Médicale)

On s'intéresse au processus détaillé de la "Prise de rendez-vous en ligne" par un patient
dans le système CliniqueSys. Le processus se déroule de la manière suivante :
- Le patient se connecte à son espace. S'il n'a pas de compte, le système lui demande d'en
créer un avant de continuer.
- Une fois connecté, le patient sélectionne la spécialité médicale souhaitée.
- Le système affiche les créneaux disponibles pour les médecins de cette spécialité.
- Le patient sélectionne un créneau.
- Le système bloque temporairement ce créneau (pendant 5 minutes) et demande au
patient de confirmer.
- Deux actions en parallèle se déclenchent : le système envoie un code de vérification par
SMS au patient, et le patient saisit le motif de sa consultation.
- Une fois ces deux actions terminées, le patient saisit le code de vérification.
- Si le code est incorrect, le créneau est libéré et le processus s'arrête (échec).
- Si le code est correct, le rendez-vous est validé, enregistré dans la base de données, et
un email de confirmation est envoyé.