# Mini Projet : Script d'administration

## Présentation

Ce mini-projet rassemble l’essentiel du cours dans une situation réaliste.

**Le contexte :** vous êtes administrateur système dans une école. Chaque rentrée, le service de scolarité vous envoie un fichier CSV contenant la liste des nouveaux étudiants. Jusqu’ici, un collègue créait les comptes à la main : deux jours de travail, des fautes de frappe, des droits mal réglés, et des mots de passe tous identiques.

**Votre mission :** automatiser entièrement cette tâche avec un script Bash fiable, sûr et journalisé, puis mettre en place la sauvegarde des répertoires des étudiants.

Ce projet mobilise :

| Chapitre | Notion utilisée |
| --- | --- |
| 3 | Fichiers, répertoires, chemins |
| 4 | Utilisateurs, groupes, droits, SGID |
| 5 | Traitement de texte, redirections |
| 6 | Variables, guillemets |
| 7 | Codes de retour |
| 8 | Script : arguments, conditions, boucles, fonctions, robustesse, `cron` |
| 10 | Archivage et sauvegarde |

### Objectifs

- Concevoir un script d’administration complet et robuste.
- Appliquer les bonnes pratiques : vérifications, journalisation, mode simulation, gestion d’erreurs.
- Documenter et tester son travail comme un professionnel.

## Cahier des charges

### Le fichier d’entrée

Le fichier `etudiants.csv` a le format suivant (séparateur `;`, avec une ligne d’en-tête) :

```
login;nom;prenom;groupe
salaoui;Alaoui;Sara;gi1
ybenali;Benali;Youssef;gi1
achraibi;Chraibi;Amine;gi2
sidrissi;Idrissi;Salma;gi2
otazi;Tazi;Omar;gi1
```

### Partie A — Création des comptes : `creer_comptes.sh`

Le script doit :

1. **Vérifier ses conditions d’exécution :**
    - être lancé avec les droits root (sinon : message d’erreur et code 1) ;
    - recevoir le chemin d’un fichier CSV existant en argument (sinon : message d’usage et code 2).
2. **Pour chaque ligne du fichier** (en ignorant l’en-tête et les lignes vides) :
    - créer le groupe s’il n’existe pas encore ;
    - si le login existe déjà : ne rien modifier, et le signaler dans le journal ;
    - sinon, créer le compte avec :
        - un répertoire personnel,
        - le shell `/bin/bash`,
        - le nom complet (« Prénom Nom ») en commentaire,
        - le groupe de la ligne comme groupe principal ;
    - générer un **mot de passe aléatoire** propre à chaque étudiant ;
    - **forcer le changement du mot de passe** à la première connexion ;
    - régler les droits du répertoire personnel en `700`.
3. **Produire deux fichiers :**
    - un **journal** horodaté de toutes les opérations dans `/var/log/creer_comptes.log` ;
    - un fichier des identifiants initiaux (`login;mot_de_passe`), lisible **par root uniquement**.
4. **Proposer un mode simulation** (option `n`) qui affiche ce qui serait fait, **sans rien modifier**.
5. **Afficher un bilan final** : nombre de comptes créés, ignorés, et en erreur.

### Partie B — Répertoires de groupe

Pour chaque groupe (`gi1`, `gi2`…), créer un répertoire partagé `/srv/groupes/<groupe>` dans lequel :

- tous les membres du groupe peuvent créer et modifier des fichiers ;
- les fichiers créés appartiennent automatiquement au groupe ;
- les autres utilisateurs n’ont aucun accès.

Cette partie peut être intégrée à `creer_comptes.sh` ou faire l’objet d’un script séparé.

### Partie C — Sauvegarde : `sauvegarde_homes.sh`

- Archiver `/home` et `/srv/groupes` dans une archive `tar.gz` datée, placée dans `/var/backups/etudiants/`.
- Conserver uniquement les **7 dernières** archives.
- Journaliser chaque exécution.
- Planifier une exécution quotidienne à 2h00 avec `cron`.

### Partie D (bonus)

Au choix :

- un script `supprimer_comptes.sh` qui prend le même CSV et supprime les comptes, **après archivage** de leur répertoire personnel ;
- une option `h` affichant une aide détaillée ;
- une vérification du format des logins (lettres minuscules et chiffres uniquement, 3 à 16 caractères).