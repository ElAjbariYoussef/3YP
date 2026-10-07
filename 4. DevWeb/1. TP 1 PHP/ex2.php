<?php
    $note = rand(-5,25);
    $isvalid = ($note>=0 and $note<=20) ? true : false;
    if($isvalid){
        if ($note > 10 ){
            $mention = true; 
        }
        else{
            $mention = false;
        }
    }
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Exercice 2</title>
    <link rel="stylesheet" href="style.css">
    </head>
<body>
    <main>
        <h1>Exercice 2 : Mention d'une note</h1>
        <span class="badge <?php 
        if ($isvalid){
        switch ($mention) {
            case true: 
                echo "admis \" > Note ", $note, ": Mention";
                break; 
            case false : 
                echo "ajourne \" > Note ", $note, ": Pas de mention";
                break; 
            };
        }
        else { echo "neutre \" >Note invalide";}
            ?></span>
    </main>
</body>
</html>