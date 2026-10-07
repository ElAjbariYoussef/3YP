<?php
    $n = rand(-100,100);
    if ( $n == 0 ){
        $state = 0;
        $pair = true;
    }
    else {
        if ($n > 0){
            $state = 1;
        }
        else {
            $state = -1;
        }
        $temp_n = abs($n);
        if ($temp_n % 2 == 0){
            $pair = true;
        }
        else{
            $pair = false;
        }
    }

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

<p class="card <?php echo match($state) { 1 => "positif", 0 => "neutre", -1 => "negatif" }?>"><?php echo $n, " est ", $p = $pair ? "pair" : "impair" ?></p>

</main>
</body>
</html>