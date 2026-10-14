<?php
$max = rand(1,25);

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Exercice 7</title>
    <link rel="stylesheet" href="style.css">
</head>
    <body>
        <main>
            <h1>Exercice 7 : Nombres premiers en pastilles</h1>
            <div class="puces">
                <?php
                    for($i = 2; $i <= $max; $i++){

                        $prime = true;

                        for($j = 2; $j < $i; $j++){
                            if ($i % $j == 0){
                                $prime = false;
                                break;
                            }

                        }

                        if($prime){
                            echo "<span class='puce'>" ,$i , "</span>";
                        }
                    }
                ?>
            </div>
        </main>
    </body>
</html>