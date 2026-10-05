# Étude dynamique UML - Diagramme de séquence (Clinique Médicale)

On souhaite modéliser le scénario nominal (succès) du paiement d'une consultation par
carte bancaire au secrétariat.
- Le secrétaire initie la demande de paiement en saisissant le numéro du dossier du
patient dans l'interface de "CliniqueSys".
- Le système "CliniqueSys" récupère le montant à payer et l'affiche au secrétaire.
- Le secrétaire confirme le montant et demande au patient d'insérer sa carte dans le
Terminal de Paiement Électronique (TPE).
- Le patient insère sa carte et tape son code PIN.
- Le TPE envoie une demande d'autorisation avec le code et le montant au Système
Bancaire.
- Le Système Bancaire vérifie la validité et renvoie un accord (autorisation OK).
- Le TPE valide la transaction et imprime un ticket.
- Le système "CliniqueSys" enregistre la facture comme "Payée".
- Le secrétaire remet le ticket et la facture au patient.