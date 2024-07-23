const fs = require('fs');
const csv = require('csv-parser');

function readCSV(filename) {
    return new Promise((resolve, reject) => {
        const results = [];

        fs.createReadStream(filename)
            .pipe(csv())
            .on('data', (data) => {
                const numero = parseInt(data.numeros); 
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
    let existingData = [];

    // Verifica se o arquivo existe e lê o conteúdo
    if (fs.existsSync(filename)) {
        existingData = fs.readFileSync(filename, 'utf8')
                         .trim()
                         .split('\n')
                         .map(line => line.split(','));
    }

    // Atualiza ou adiciona novas linhas conforme necessário
    for (let i = 1; i < newData.length+1; i++) {
        if (!existingData[i]) {
            existingData[i] = [];
        }
        existingData[i][1] = newData[i-1];
    }

    // Converte os dados para CSV
    const csvData = existingData.map(line => line.join(',')).join('\n');

    // Escreve os dados no arquivo
    fs.writeFileSync(filename, csvData + '\n');

    console.log(existingData);
}

function readNameOutput(filename) {
    return new Promise((resolve, reject) => {
        let results = './dataget/output/';
        let firstLineValue = '';
        let secondLineValue = '';

        fs.createReadStream(filename)
            .pipe(csv())
            .on('data', (data) => {
                console.log('Linha lida:', data); // Para depuração
                if (!firstLineValue) {
                    firstLineValue = data['n_k'];
                } else {
                    secondLineValue = data['n_k'];
                }
            })
            .on('end', () => {
                if (firstLineValue && secondLineValue) {
                    results += `${firstLineValue}:${secondLineValue}.csv`;
                    console.log(results);
                    resolve(results);
                } else {
                    // Se não houver linhas suficientes
                    reject(new Error('O arquivo CSV não contém as linhas esperadas.'));
                }
            })
            .on('error', (error) => {
                reject(error);
            });
    });
}


module.exports = {
    readCSV: readCSV,
    writeCSV: writeCSV,
    readNameOutput: readNameOutput
}