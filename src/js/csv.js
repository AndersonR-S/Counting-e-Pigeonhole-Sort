const fs = require('fs');
const csv = require('csv-parser');

function readCSV(filename) {
    return new Promise((resolve, reject) => {
        const results = [];
        let isFirstLine = true;

        fs.createReadStream(filename)
            .pipe(csv())
            .on('data', (data) => {
                if (isFirstLine) {
                    isFirstLine = false;
                    return; // Pula a primeira linha
                }
                // Aqui assumimos que cada linha do CSV contém um único número
                const numero = parseInt(data.numeros); // Converte para número inteiro
                results.push(numero);
            })
            .on('end', () => {
                resolve(results);
            })
            .on('error', (error) => {
                reject(error);
            });
    });
}

function writeCSV(filename, newData) {
    // Lê o conteúdo atual do arquivo CSV, se existir
    let existingData = [];
    if (fs.existsSync(filename)) {
        existingData = fs.readFileSync(filename, 'utf8').trim().split('\n').slice().map(line => line.split(','));
    }
    
    for(let i = 1; i < 5; i++){
        existingData[i][1] = newData[i-1];
    }

    fs.writeFileSync(filename,"");

    existingData.forEach(line=>
    {
        fs.appendFileSync(filename, line.join(',') + '\n'); // Escreve cada linha
    })

    console.log(existingData)

}

module.exports = {
    readCSV: readCSV,
    writeCSV: writeCSV
    // Outras funções, se houver
};
