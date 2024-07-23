import java.util.Vector;

public class Ordenacao {

    public Vector<Integer> ordenacaoCounting(Vector<Integer> a) {
        int maxA = 0;
        int size = a.size();

        for (int i = 0; i < size; i++) {
            if (a.get(i) > maxA) {
                maxA = a.get(i);
            }
        }

        Vector<Integer> c = new Vector<>(maxA + 1);
        for (int i = 0; i <= maxA; i++) {
            c.add(0);
        }

        for (int i = 0; i < size; i++) {
            int index = a.get(i); 
            int currentValue = c.get(index); 
            c.set(index, currentValue + 1); 
        }

        for (int i = 1; i <= maxA; i++) {
            c.set(i, c.get(i) + c.get(i - 1));
        }

        Vector<Integer> b = new Vector<>(size);
        for (int i = 0; i < size; i++) {
            b.add(0);
        }
        
        for (int i = size - 1; i >= 0; i--) {
            b.set(c.get(a.get(i)) - 1, a.get(i));
            c.set(a.get(i), c.get(a.get(i)) - 1);
        }

        return b;
    }


    public void ordenacaoPigeonhole(Vector<Integer> a) {
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

        int hole_size = maximum - minimum + 1;

        Vector<Integer> c = new Vector<>(hole_size);
        for (int i = 0; i < hole_size; i++) {
            c.add(0);
        }
        for (int i = 0; i < size; i++) {
            c.set(a.get(i) - minimum, c.get(a.get(i) - minimum) + 1);
        }

        int index = 0;
        for (int j = 0; j <hole_size; j++) {
            while (c.get(j) > 0) {
                a.set(index++, j + minimum);
                c.set(j, c.get(j) - 1);
            }
        }
    }

    public Vector<Integer> tempo(Vector<Integer> a) {
        long start, end;
        final int num_iteracoes = 10;

        // Medição do tempo para ordenacaoPigeonhole
        double tempo_ting = 0.0;
        for (int i = 0; i < num_iteracoes; i++) {
            start = System.nanoTime();
            ordenacaoCounting(new Vector<>(a)); 
            end = System.nanoTime();
            tempo_ting += ((double) (end - start)); 
        }
        tempo_ting /= num_iteracoes;

        // Medição do tempo para ordenacaoPigeonhole
        double tempo_hole = 0.0;
        for (int i = 0; i < num_iteracoes; i++) {
            start = System.nanoTime();
            ordenacaoPigeonhole(new Vector<>(a)); 
            end = System.nanoTime();
            tempo_hole += ((double) (end - start));
        }
        tempo_hole /= num_iteracoes;

        // Criando um vector para armazenar os tempos em formato inteiro
        Vector<Integer> tempos = new Vector<>();
        tempos.add((int) tempo_ting);
        tempos.add((int) tempo_hole);

        return tempos;
    }

}
