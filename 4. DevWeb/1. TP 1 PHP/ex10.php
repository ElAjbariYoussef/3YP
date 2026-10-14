
<?php
$releves = [22.5, 23.1, 24.0, 26.8, 31.2, 29.5, 35.4, 27.0];
$h = 8;
$d = 0;
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Exercice 10</title>
    <link rel="stylesheet" href="style.css">
</head>
    <body>
        <main>
            <h1>Exercice 10 : Alertes d'un capteur (break et continue)</h1>
            <ul class="liste">

                <?php foreach ($releves as $element):?>
                    <?php if($element >= 30){
                        $d++;
                        if($d == 1) echo "<li class='alerte'> Premier dépassement à ", $h,"h</li>";
                        echo "<li class='alerte'>",$h,"h : ",$element," °C","</li>";
                        $h++;       
                    }
                    ?>
                <?php endforeach; ?>
                <li class="alerte"><?= $d, " alerte(s) au total."?></li>
            </ul>
        </main>
    </body>
</html>