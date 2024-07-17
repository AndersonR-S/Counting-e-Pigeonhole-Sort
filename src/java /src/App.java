import java.util.Vector;

public class App {

    public static void main(String[] args) {
        Csv csv = new Csv(); // Instância da classe CSV para ler e escrever arquivos CSV
        Ordenacao ordenacao = new Ordenacao(); // Instância da classe Ordenacao para realizar as ordenações

        // Leitura do arquivo CSV de entrada
        Vector<Integer> input = csv.readCSV("dataset/input.csv");
        if (input.isEmpty()) {
            System.out.println("Nenhum dado encontrado no arquivo CSV.");
            return; // Saída do programa
        }

        // Ordenação desordenada usando a função ordenar da classe Ordenacao
        Vector<Integer> tempo_de = ordenacao.ordenar(new Vector<>(input));

        // Ordenação usando Counting Sort (assumindo que ordenacaoCounting é a função adequada)
        input = ordenacao.ordenacaoCounting(new Vector<>(input));

        // Ordenação dos números ordenados
        Vector<Integer> tempo_or = ordenacao.ordenar(new Vector<>(input));

        // Criação de um vetor para armazenar os tempos a serem escritos no CSV
        Vector<Integer> tempo = new Vector<>();
        tempo.add(tempo_de.get(0));
        tempo.add(tempo_de.get(1));
        tempo.add(tempo_or.get(0));
        tempo.add(tempo_or.get(1));

        // Escrita dos tempos no arquivo CSV de saída
        csv.writeCSV("dataget/output.csv", tempo);
    }
}
