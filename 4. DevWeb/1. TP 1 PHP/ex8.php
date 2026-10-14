<?php
$n = rand(5,25);
$c = 0;
$a = 0;
$b = 1;

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Exercice 8</title>
    <link rel="stylesheet" href="style.css">
</head>
    <body>
        <main>
            <h1>Exercice 8 : Suite de Fibonacci avec do-while</h1>
            <?php
                do {
                    echo "<span class='puce'>" , $a , "</span>";
                    $t = $a;
                    $a += $b;
                    $b = $t;
                    $c++;
                }while($c < $n);
            ?>
        </main>
    </body>
</html>