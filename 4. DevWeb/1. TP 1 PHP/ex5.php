<?php
$n = rand(1,10);
?>
<!DOCTYPE html>
<html lang="fr">
    <head>
        <meta charset="UTF-8">
        <title>Exercice 5</title>
        <link rel="stylesheet" href="style.css">
    </head>
    <body>
        <main>
            <h1>Exercice 5 : Table de multiplication en HTML</h1>
            <table class="tableau">
                <?php 
                    for ($i = 1; $i<11; $i++)
                        {
                            echo "<tr>",
                                    "<th>",$n," x ", $i ,"</th>", 
                                    "<th>",$n*$i,"</th>",
                                "</tr>";
                        }
                ?>
            </table>
        </main>
    </body>
</html>