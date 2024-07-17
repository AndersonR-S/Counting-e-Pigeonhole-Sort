<?php

function readCSV($filename){
    // Leitura do arquivo de entrada CSV
    $input = file_get_contents($filename);
    $lines = explode("\n", trim($input));
    array_shift($lines); //tirar a primeira linha
    $input = array_map('intval', $lines);//passar para o inteiro

    return $input;
}

function writeCSV($filename, $newData) {
    // Lê o conteúdo atual do arquivo CSV, se existir
    $existingData = [];
    if (file_exists($filename)) {
        $fileContent = file_get_contents($filename); // Lê o conteúdo do arquivo
        $lines = explode("\n", trim($fileContent)); // Divide em linhas
        foreach ($lines as $line) {
            $existingData[] = str_getcsv($line); // Converte cada linha em um array
        }
    }
    
    // Atualiza os dados existentes com o novo dado
    for ($i = 1; $i <= 4; $i++) {
        $existingData[$i][2] = $newData[$i - 1];
    }

    // Escreve os dados atualizados de volta para o arquivo CSV
    file_put_contents($filename, ""); // Limpa o conteúdo do arquivo

    foreach ($existingData as $line) {
        file_put_contents($filename, implode(',', $line) . "\n", FILE_APPEND); // Escreve cada linha
    }

}

?>


