<?php
require_once 'ordenacao.php'; 
require_once 'csv.php';

try {
    $input = readCSV('dataset/input.csv');
    $tempo_de = ordenar($input); // desordenado
    
    $input = ordenacaoCounting($input); //ordenar de ordem crescente

    $tempo_or = ordenar($input);// ordenado

    $tempo = array_merge($tempo_de, $tempo_or);

    writeCSV('dataget/output.csv',$tempo);

} catch (Exception $e) {
    echo "Error: " . $e->getMessage() . "\n";
    exit();
}
?>