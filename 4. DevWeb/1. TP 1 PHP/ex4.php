<?php
$annee = 1900;
$isBissextile = (($annee % 4 == 0 && $annee % 100 != 0 )|| $annee % 400 == 0)
?>
<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="UTF-8">
<title>Exercice 4</title>
<link rel="stylesheet" href="style.css">

</head>

    <body>
        <main>
            <h1>Exercice 4 : Année bissextile</h1>
            <p class="carte <?= $isBissextile? "admis" : "neutre";?>">
                <?= $annee;?> : <?= $isBissextile ? "bissextile" : "non bissextile";?>

        </main>
    </body>
</html>
