<?php

function ordenacaoCounting($a) {
    $maxValue = max($a);
    $c = array_fill(0, $maxValue + 1, 0);

    foreach ($a as $i) {
        $c[$i]++;
    }

    for ($i = 1; $i < count($c); $i++) {
        $c[$i] += $c[$i - 1];
    }

    $b = array_fill(0, count($a), 0);
    for ($i = count($a) - 1; $i >= 0; $i--) {
        $b[$c[$a[$i]] - 1] = $a[$i];
        $c[$a[$i]]--;
    }

    return $b;
}

function ordenacaoPigeonhole($a) {
    $minimum = min($a);
    $maximum = max($a);

    $size = $maximum - $minimum + 1;

    $c = array_fill(0, $size, 0);
    foreach ($a as $i) {
        $c[$i - $minimum]++;
    }

    $index = 0;
    for ($j = 0; $j < $size; $j++) {
        while ($c[$j] > 0) {
            $a[$index++] = $j + $minimum;
            $c[$j]--;
        }
    }
    
    return $a;
}

function tempo($a) {
    // counting sort
    $tempo_ting = 0;
    for ($i = 0; $i < 10; $i++) {
        $tempo_inicial = microtime(true);
        ordenacaoCounting($a);
        $tempo_final = microtime(true);
        $tempo_ting += ($tempo_final - $tempo_inicial);
    }
    $tempo_ting /= 10;
    $tempo_ting *= 1e9; // transformar segundos para nanossegundos

    // pigeonhole sort
    $tempo_hole = 0;
    for ($i = 0; $i < 10; $i++) {
        $tempo_inicial = microtime(true);
        ordenacaoPigeonhole($a);
        $tempo_final = microtime(true);
        $tempo_hole += ($tempo_final - $tempo_inicial);
    }
    $tempo_hole /= 10;
    $tempo_hole *= 1e9; // transformar segundos para nanossegundos

    return array(intval($tempo_ting), intval($tempo_hole));
}

?>