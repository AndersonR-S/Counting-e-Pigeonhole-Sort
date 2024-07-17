const ordenacao = require('./ordenacao.js'); // Verifique o caminho correto do módulo de ordenação
const csv = require('./csv.js'); // Verifique o caminho correto do módulo CSV

async function main() {
    try {
        // Leitura do arquivo CSV
        const input = await csv.readCSV('./dataset/input.csv'); // Lê os números do CSV
        console.log('Input lido:', input);

        // Ordenação dos números desordenados
        let tempos_de = (await ordenacao.ordenar(input));

        // Ordenação dos números ordenados
        const sortedInput = [...input].sort((a, b) => a - b); // Ordena uma cópia
        let tempos_or = (await ordenacao.ordenar(sortedInput));

        let tempos = tempos_de;
        for(let i = 0; i< 2; i++)
        {
            tempos.push(tempos_or[0]);
        }

        // Escreve os tempos no arquivo de saída
        await csv.writeCSV('./dataget/output.csv', tempos);

    } catch (error) {
        console.error('Erro:', error);
        process.exit(1);
    }
}

// Executa a função principal
main().catch((error) => console.error('Erro ao executar o programa:', error));
