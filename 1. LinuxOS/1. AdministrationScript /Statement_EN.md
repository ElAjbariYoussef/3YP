# Mini Project: Administration Script

## Overview

This mini-project brings together the essential concepts from the course in a realistic situation.

**The context:** You are a system administrator at a school. Every academic year, the administration office sends you a CSV file containing the list of new students. Until now, a colleague created the accounts manually: two days of work, typing errors, incorrectly configured permissions, and identical passwords for everyone.

**Your mission:** Fully automate this task with a reliable, secure, and logged Bash script, and then set up backups of the students' directories.

This project covers:

| Chapter | Concept Used                                                           |
| ------- | ---------------------------------------------------------------------- |
| 3       | Files, directories, paths                                              |
| 4       | Users, groups, permissions, SGID                                       |
| 5       | Text processing, redirections                                          |
| 6       | Variables, quotes                                                      |
| 7       | Return codes                                                           |
| 8       | Scripting: arguments, conditions, loops, functions, robustness, `cron` |
| 10      | Archiving and backup                                                   |

### Objectives

* Design a complete and robust administration script.
* Apply best practices: checks, logging, simulation mode, and error handling.
* Document and test your work like a professional.

## Requirements

### Input File

The `etudiants.csv` file has the following format (separator `;`, with a header row):

```text
login;nom;prenom;groupe

salaoui;Alaoui;Sara;gi1
ybenali;Benali;Youssef;gi1
achraibi;Chraibi;Amine;gi2
sidrissi;Idrissi;Salma;gi2
otazi;Tazi;Omar;gi1
```

### Part A — Account Creation: `creer_comptes.sh`

The script must:

1. **Check its execution conditions:**

   * Be run with root privileges (otherwise: display an error message and exit with code `1`);
   * Receive the path to an existing CSV file as an argument (otherwise: display a usage message and exit with code `2`).

2. **For each line in the file** (ignoring the header and empty lines):

   * Create the group if it does not already exist;
   * If the login already exists: do nothing, and record it in the log;
   * Otherwise, create the account with:

     * A home directory;
     * The `/bin/bash` shell;
     * The full name ("First Name Last Name") as the comment field;
     * The group specified in the line as the primary group;
   * Generate a **random password** unique to each student;
   * **Force the user to change the password** on their first login;
   * Set the permissions of the home directory to `700`.

3. **Produce two files:**

   * A **timestamped log** of all operations in `/var/log/creer_comptes.log`;
   * A file containing the initial credentials (`login;password`), readable **by root only**.

4. **Provide a simulation mode** (option `n`) that displays what would be done **without making any changes**.

5. **Display a final summary:** number of accounts created, skipped, and failed.

### Part B — Group Directories

For each group (`gi1`, `gi2`, …), create a shared directory `/srv/groupes/<group>` where:

* All members of the group can create and modify files;
* Newly created files automatically belong to the group;
* Other users have no access.

This part may be integrated into `creer_comptes.sh` or implemented as a separate script.

### Part C — Backup: `sauvegarde_homes.sh`

* Archive `/home` and `/srv/groupes` into a dated `tar.gz` archive placed in `/var/backups/etudiants/`.
* Keep only the **7 most recent** archives.
* Log every execution.
* Schedule a daily execution at 2:00 AM using `cron`.

### Part D (Bonus)

Choose one:

* A `supprimer_comptes.sh` script that takes the same CSV file and deletes the accounts **after archiving** their home directories;
* An `h` option displaying detailed help;
* A validation of the login format (lowercase letters and digits only, 3 to 16 characters).
