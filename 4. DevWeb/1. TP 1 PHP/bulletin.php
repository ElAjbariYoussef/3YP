<?php
$coef = ["Python" => 3, "BD" => 2, "Web" => 2];
$etudiants = [
    "Amine" => ["Python" => 14, "BD" => 12, "Web" => 15],
    "Salma" => ["Python" => 16, "BD" => 17, "Web" => 14],
    "Youssef" => ["Python" => 9, "BD" => 11, "Web" => 10],
    "Imane" => ["Python" => 18, "BD" => 15, "Web" => 17],
    "Omar" => ["Python" => 7, "BD" => 8, "Web" => 9],
    ];
?>



<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Mini-projet</title>
    <link rel="stylesheet" href="style.css">
</head>
    <body>
        <main>
            <h1>Mini-projet</h1>
            <table class="tableau">
                <tr>
                    <th>Rang</th>
                    <th>Nom</th>
                    <th>Note Python</th>
                    <th>Note BD</th>
                    <th>Note Web</th>
                    <th>Moyenne</th>
                    <th>Progression</th>
                    <th>Mention</th>
                </tr>
                <?php
                    $admis = 0;
                    $c = 0;
                    $m_e = "";
                    $m_m = 0;
                    $moyennes = [];
                    foreach($etudiants as $nom => $listeNote){
                        $moyenne = 0;
                        $somme = 0;
                        foreach($listeNote as $note){
                            foreach($coef as $coefficient){
                                $somme = $somme + $coefficient;
                                $moyenne = $moyenne + ($note * $coefficient);
                            }
                        }
                        $moyennes[$nom] = $moyenne / $somme;
                    }
                    arsort($moyennes);
                    $rang = 0;
                    foreach(array_keys($moyennes) as $nom){
                        $listeNote = $etudiants[$nom];
                        $c++;
                        $rang++;
                        $moyenne = 0;
                        $somme = 0;
                        echo "<tr>";
                        echo "<th>",$rang,"</th>";
                        echo "<th>",$nom,"</th>";
                        foreach($listeNote as $note){
                            echo "<th>", $note, "</th>";
                            foreach($coef as $coefficient){
                                $somme = $somme + $coefficient;
                                $moyenne = $moyenne + ($note * $coefficient);
                            }
                        }
                        $moyenne = $moyenne / $somme;
                        if($moyenne > $m_m) { $m_m = $moyenne; $m_e = $nom;}
                        echo "<th>", $moyenne, "</th>";
                        echo "<th><div class=\"barre\"><div style=\"background: rgb(0, 255, 89);width: ", $moyenne / 20 * 100, "%\"></div></div></th>";
                        if ($moyenne < 10) $statut = "Ajourné";
                        else if ($moyenne < 14) {$statut = "Assez Bien"; $admis++;}
                        else if ($moyenne < 16) {$statut = "Bien"; $admis++;}
                        else {$statut = "Trés Bien"; $admis++;}
                        echo "<th>", $statut,"</th>";
                        echo "</tr>";
                    }
                    echo "<br>";
                    echo "Admis : ", $admis ," sur ", $c ," (",$admis*100/$c," %) <br>";
                    echo "Meilleure moyenne : ",$m_e," (",$m_m,")";
                ?>
            </table>
        </main>
    </body>
</html>
