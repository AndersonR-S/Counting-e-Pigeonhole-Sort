import java.util.List;

public class App {

    public static void main(String[] args) {
        CSV csv = new CSV(); // Instância da classe CSV para ler e escrever arquivos CSV
        Ordenacao ordenacao = new Ordenacao(); // Instância da classe Ordenacao para realizar as ordenações

        // Leitura do arquivo CSV de entrada
        List<Integer> input = csv.readCSV("../../dataset/input.csv");

        // Ordenação desordenada usando a função ordenar da classe Ordenacao
        List<Integer> tempo_de = ordenacao.ordenar(input);

        // Ordenação usando Counting Sort (assumindo que ordenacaoCounting é a função adequada)
        input = ordenacao.ordenacaoCounting(input);

        // Ordenação dos números ordenados
        List<Integer> tempo_or = ordenacao.ordenar(input);

        // Criação de um vetor para armazenar os tempos a serem escritos no CSV
        List<Integer> tempo = List.of(tempo_de.get(0), tempo_de.get(1), tempo_or.get(0), tempo_or.get(1));

        // Escrita dos tempos no arquivo CSV de saída
        csv.writeCSV("../../dataget/output.csv", tempo);
        
        return 0;
    }
}

