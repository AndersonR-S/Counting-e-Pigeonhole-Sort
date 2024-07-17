import java.util.ArrayList;
import java.util.List;

public class Ordenacao {

    public Ordenacao() {
        // Construtor vazio
    }

    // Função de ordenação Counting Sort
    public List<Integer> ordenacaoCounting(List<Integer> a) {
        // Encontrar o valor máximo em a
        int maxA = 0;
        int size = a.size();

        for (int i = 0; i < size; i++) {
            if (a.get(i) > maxA) {
                maxA = a.get(i);
            }
        }

        // Passo 1: Contagem das ocorrências dos elementos
        List<Integer> c = new ArrayList<>(maxA + 1);
        for (int i = 0; i <= maxA; i++) {
            c.add(0);
        }
        for (int i = 0; i < size; i++) {
            c.set(a.get(i), c.get(a.get(i)) + 1);
        }

        // Passo 2: Determinação das posições finais
        for (int i = 1; i <= maxA; i++) {
            c.set(i, c.get(i) + c.get(i - 1));
        }

        // Passo 3: Construção do array ordenado
        List<Integer> b = new ArrayList<>(size);
        for (int i = size - 1; i >= 0; i--) {
            b.set(c.get(a.get(i)) - 1, a.get(i));
            c.set(a.get(i), c.get(a.get(i)) - 1);
        }

        return b;
    }

    // Função de ordenação Pigeonhole Sort
    public void ordenacaoPigeonhole(List<Integer> a) {
        // Encontrar o valor mínimo e máximo em a
        int size = a.size();
        int minimum = a.get(0);
        int maximum = a.get(0);

        for (int i = 1; i < size; i++) {
            if (a.get(i) < minimum) {
                minimum = a.get(i);
            }
            if (a.get(i) > maximum) {
                maximum = a.get(i);
            }
        }

        // Determinar o tamanho do vetor de pigeonholes
        int holeSize = maximum - minimum + 1;

        // Criar os Pigeonholes
        List<Integer> c = new ArrayList<>(holeSize);
        for (int i = 0; i < holeSize; i++) {
            c.add(0);
        }
        for (int i = 0; i < size; i++) {
            c.set(a.get(i) - minimum, c.get(a.get(i) - minimum) + 1);
        }

        // Reconstruir o array ordenado
        int index = 0;
        for (int j = 0; j < holeSize; j++) {
            while (c.get(j) > 0) {
                a.set(index++, j + minimum);
                c.set(j, c.get(j) - 1);
            }
        }
    }

    // Função para ordenar e medir tempos em nanossegundos
    public List<Integer> ordenar(List<Integer> a) {
        // Medição do tempo para ordenacaoCounting
        long start, end;
        double tempoCoun = 0.0;
        final int numIteracoes = 10;

        for (int i = 0; i < numIteracoes; i++) {
            start = System.nanoTime();
            ordenacaoCounting(new ArrayList<>(a)); // Copia para não modificar a lista original
            end = System.nanoTime();
            tempoCoun += ((double) (end - start)) / 1_000_000; // Convertendo para milissegundos
        }
        tempoCoun /= numIteracoes;
        tempoCoun *= 1_000_000; // Convertendo para nanossegundos

        // Medição do tempo para ordenacaoPigeonhole
        double tempoHole = 0.0;
        for (int i = 0; i < numIteracoes; i++) {
            start = System.nanoTime();
            ordenacaoPigeonhole(new ArrayList<>(a)); // Copia para não modificar a lista original
            end = System.nanoTime();
            tempoHole += ((double) (end - start)) / 1_000_000; // Convertendo para milissegundos
        }
        tempoHole /= numIteracoes;
        tempoHole *= 1_000_000; // Convertendo para nanossegundos

        // Criando uma lista para armazenar os tempos em formato inteiro
        List<Integer> tempos = new ArrayList<>();
        tempos.add((int) tempoCoun);
        tempos.add((int) tempoHole);

        return tempos;
    }

    
}
