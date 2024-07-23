function ordenacaoCounting(a) {
    let maxA = Math.max(...a);

    let c = new Array(maxA + 1).fill(0);
    for (let i = 0; i < a.length; i++) {
        c[a[i]]++;
    }

    for (let i = 1; i < c.length; i++) {
        c[i] += c[i - 1];
    }

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

    let size = maximum - minimum + 1;

    let c = new Array(size).fill(0);
    for (let i = 0; i < a.length; i++) {
        c[a[i] - minimum]++;
    }

    let index = 0;
    for (let j = 0; j < size; j++) {
        while (c[j] > 0) {
            a[index++] = j + minimum;
            c[j]--;
        }
    }
}

function tempo(a) {
    let tempo_ting = BigInt(0);
    let tempo_hole = BigInt(0);
    const num_iteracoes = 10;

    for (let i = 0; i < num_iteracoes; i++) {
        let tempo_inicial = process.hrtime.bigint();
        ordenacaoCounting([...a]); 
        let tempo_final = process.hrtime.bigint();
        tempo_ting += (tempo_final - tempo_inicial);
    }
    tempo_ting /= BigInt(num_iteracoes);

    for (let i = 0; i < num_iteracoes; i++) {
        let tempo_inicial = process.hrtime.bigint();
        ordenacaoPigeonhole([...a]); 
        let tempo_final = process.hrtime.bigint();
        tempo_hole += (tempo_final - tempo_inicial);
    }
    tempo_hole /= BigInt(num_iteracoes);

    return [tempo_ting.toString(), tempo_hole.toString()];
}

module.exports = {
    tempo: tempo,
    ordenacaoCounting : ordenacaoCounting
    // Outras funções, se houver
};