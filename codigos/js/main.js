const ordenacao = require('./ordenacao.js'); 
const csv = require('./csv.js'); 

async function main() {
    try {
        const input = await csv.readCSV('./dataset/input.csv'); 

        // Ordenação dos números desordenados
        let tempos_de = (await ordenacao.tempo(input));

        // Ordenação dos números ordenados
        const ordenado = ordenacao.ordenacaoCounting(input);
        let tempos_or = (await ordenacao.tempo(ordenado));

        let tempos = tempos_de;
        for(let i = 0; i< 2; i++)
        {
            tempos.push(tempos_or[i]);
        }

        let name_output = (await csv.readNameOutput('./dataset/valores.csv'));
        await csv.writeCSV(name_output, tempos);

    } catch (error) {
        console.error('Erro:', error);
        process.exit(1);
    }
}

main().catch((error) => console.error('Erro ao executar o programa:', error));
