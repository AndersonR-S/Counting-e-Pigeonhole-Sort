let inputPath = 'dataset/input.csv';
let dados = lerCSV(inputPath)
    .then((input) => {
        console.log(input); // Array de números lidos do arquivo CSV
        // Continuar com o processamento
    })
    .catch((error) => {
        console.error('Erro ao ler arquivo CSV:', error);
    });

let outputPath = 'dataget/output.csv';
/*let dados = [
    { python: 'valor1' }, // Substituir 'valor1' pelo dado correto
    { python: 'valor2' }  // Substituir 'valor2' pelo dado correto
];*/

escreverCSV(outputPath, dados)
    .catch((error) => {
        console.error('Erro ao escrever arquivo CSV:', error);
    });