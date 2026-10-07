<?php
$i = 1;
$n = rand($i,20);
$sum = 0;
while($i<$n+1){
    $sum += $i;
    $i += 1;
}
$moyenne = $sum / $n;
$verif = $n * ($n+1) /2;

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Exercice 6</title>
    <link rel="stylesheet" href="style.css">
</head>
    <body>
        <main>
            <h1>Exercice 6 : Somme et moyenne avec while</h1>
            <div class="stats">
                <div class="carte">
                Somme de 1 à <?=$n?> : <?=$sum?>
                </div>
                <div class="carte">
                Moyenne : <?=$moyenne?>
                </div>
                <div class="carte">
                Vérification : <?=$verif?>
                </div>
            </div> 
        </main>
    </body>
</html>