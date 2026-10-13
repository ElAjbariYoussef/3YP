<?php
    $n = rand(-100,100);
    $state = $n <=> 0;
    $css = match($state) { 1 => "positif", 0 => "neutre", -1 => "negatif" };
    $pair = $n % 2 == 0;
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Exercice 1</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<main>
<h1>Exercice 1 : Signe et parité</h1>

<p class="card <?=$css?>"><?= $n, " est ", $pair ? "pair" : "impair" ?></p>

</main>
</body>
</html>