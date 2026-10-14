<?php
$n = rand(1,25);
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Exercice 9</title>
    <link rel="stylesheet" href="style.css">
</head>
    <body>
        <main>
            <h1>Exercice 9 : Triangle d'étoiles</h1>
            <pre class="triangle">
                <?php
                    for($i = 0; $i <= $n ; $i++){
                        for ($j = 1; $j <= ($n - $i); $j++){ echo " ";}
                        for ($j = 1; $j <= (2 * $i - 1); $j++){ echo "*";}
                        echo "<br>";
                    }
                ?>
            </pre>
        </main>
    </body>
</html>