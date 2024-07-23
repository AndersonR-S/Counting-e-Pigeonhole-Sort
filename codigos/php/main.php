<?php
require_once 'ordenacao.php'; 
require_once 'csv.php';

try {
    $input = readCSV('dataset/input.csv');

    // desordenado
    $tempo_desor = tempo($input); 
    
    // ordenado
    $input = ordenacaoCounting($input);
    $tempo_orden = tempo($input);


    $tempo = array_merge($tempo_desor, $tempo_orden);
    $name_output = readNameOutput('dataset/valores.csv');
    writeCSV($name_output,$tempo);

} catch (Exception $e) {
    echo "Error: " . $e->getMessage() . "\n";
    exit();
}
?>