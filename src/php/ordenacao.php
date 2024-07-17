<?php

function ordenacaoCounting($a) {
    $maxValue = max($a);
    $c = array_fill(0, $maxValue + 1, 0);

    // Passo 1: Contagem das ocorrências dos elementos
    foreach ($a as $i) {
        $c[$i]++;
    }

    // Passo 2: Determinação das posições finais
    for ($i = 1; $i < count($c); $i++) {
        $c[$i] += $c[$i - 1];
    }

    // Passo 3: Construção do array ordenado
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

    // Determinar o tamanho do vetor
    $size = $maximum - $minimum + 1;

    // Criar os Pigeonholes
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

function ordenar($a) {
    // counting sort
    $tempo_coun = 0;
    for ($i = 0; $i < 10; $i++) {
        $tempo_inicial = microtime(true);
        ordenacaoCounting($a);
        $tempo_final = microtime(true);
        $tempo_coun += ($tempo_final - $tempo_inicial);
    }
    $tempo_coun /= 10;

    $tempo_coun *= 1e9; // transformar segundos para nanossegundos

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

    return array(intval($tempo_coun), intval($tempo_hole));
}

?>