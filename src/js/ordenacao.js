function ordenacaoCounting(a) {
    let maxA = Math.max(...a);

    // Passo 1: Contagem das ocorrências dos elementos
    let c = new Array(maxA + 1).fill(0);
    for (let i = 0; i < a.length; i++) {
        c[a[i]]++;
    }

    // Passo 2: Determinação das posições finais
    for (let i = 1; i < c.length; i++) {
        c[i] += c[i - 1];
    }

    // Passo 3: Construção do array ordenado
    let b = new Array(a.length);
    for (let i = a.length - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    return b;
}

function ordenacaoPigeonhole(a) {
    let minimum = Math.min(...a);
    let maximum = Math.max(...a);

    // Determinar o tamanho do vetor
    let size = maximum - minimum + 1;

    // Criar os Pigeonholes
    let c = new Array(size).fill(0);
    for (let i = 0; i < a.length; i++) {
        c[a[i] - minimum]++;
    }

    // Reconstruir o array ordenado
    let index = 0;
    for (let j = 0; j < size; j++) {
        while (c[j] > 0) {
            a[index++] = j + minimum;
            c[j]--;
        }
    }

    return a;
}

function ordenar(a) {
    let tempo_coun = BigInt(0);
    let tempo_hole = BigInt(0);
    const numIteracoes = 10;

    for (let i = 0; i < numIteracoes; i++) {
        let tempo_inicial = process.hrtime.bigint();
        ordenacaoCounting([...a]); 
        let tempo_final = process.hrtime.bigint();
        tempo_coun += (tempo_final - tempo_inicial);
    }
    tempo_coun /= BigInt(numIteracoes);

    for (let i = 0; i < numIteracoes; i++) {
        let tempo_inicial = process.hrtime.bigint();
        ordenacaoPigeonhole([...a]); 
        let tempo_final = process.hrtime.bigint();
        tempo_hole += (tempo_final - tempo_inicial);
    }
    tempo_hole /= BigInt(numIteracoes);

    return [tempo_coun.toString(), tempo_hole.toString()];
}

module.exports = {
    ordenar: ordenar
    // Outras funções, se houver
};