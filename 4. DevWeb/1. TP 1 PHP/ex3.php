<?php
    $jour = rand(-5,10);
    $isvalid = ($jour>0 and $jour<8) ? true : false;
    if($isvalid){
        if ($jour > 5  ){
            $end = true; 
        }
        else{
            $end = false;
        }
        $nom = match($jour){
            1 => "Lundi",
            2 => "Mardi",
            3 => "Mercredi",
            4 => "Jeudi",
            5 => "Vendredi",
            6 => "Samedi",
            7 => "Dimanche"
        };
    }
?>
<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="UTF-8">
<title>Exercice 3</title>
<link rel="stylesheet" href="style.css">
</head>
<body>
    <main>
        <h1>Exercice 3 : Jour de la semaine</h1>
        <p class="carte <?php 
        if ($isvalid){
        switch ($end) {
            case true: 
                echo "weekend \" > ";
                break; 
            case false : 
                echo "ouvrable \" >";
                break; 
            };
        echo $jour , " : ",$nom, ($end) ? "(week-end)" : " (jour ouvrable)";
        }
        else { echo "neutre \" >" , $jour, " : jour invalide";}
            ?></span>
    </main>
</body>
</html>