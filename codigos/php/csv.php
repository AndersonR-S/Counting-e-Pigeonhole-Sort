<?php

function readCSV($filename){
    // Leitura do arquivo de entrada CSV
    $input = file_get_contents($filename);
    $lines = explode("\n", trim($input));
    array_shift($lines); 
    $input = array_map('intval', $lines);

    return $input;
}

function writeCSV($filename, $newData) {
    // Lê o conteúdo atual do arquivo CSV, se existir
    $existingData = [];
    if (file_exists($filename)) {
        $fileContent = file_get_contents($filename); 
        $lines = explode("\n", trim($fileContent)); 
        foreach ($lines as $line) {
            $existingData[] = str_getcsv($line); 
        }
    }

    // Atualiza os dados existentes com o novo dado
    for ($i = 1; $i <= 4; $i++) {
        $existingData[$i][2] = $newData[$i - 1];
    }

    // Escreve os dados atualizados de volta para o arquivo CSV
    file_put_contents($filename, ""); 

    foreach ($existingData as $line) {
        file_put_contents($filename, implode(',', $line) . "\n", FILE_APPEND);
    }
}

function readNameOutput($filename){
    // Leitura do arquivo de valores.csv
    $input = file_get_contents($filename);
    $lines = explode("\n", trim($input));

    return "dataget/output/". $lines[1]. ":". $lines[2].".csv";
}
?>


