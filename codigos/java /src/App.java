import java.util.Vector;

public class App {

    public static void main(String[] args) {
        Csv csv = new Csv(); 
        Ordenacao ordenacao = new Ordenacao(); 

        Vector<Integer> input = csv.readCSV("dataset/input.csv");
        if (input.isEmpty()) {
            System.out.println("Nenhum dado encontrado no arquivo CSV.");
            return; 
        }

        // Ordenação desordenada usando a função ordenar da classe Ordenacao
        Vector<Integer> tempo_desor = ordenacao.tempo(new Vector<>(input));

        // Ordenação usando Counting Sort (assumindo que ordenacaoCounting é a função adequada)
        input = ordenacao.ordenacaoCounting(new Vector<>(input));
        Vector<Integer> tempo_orden = ordenacao.tempo(new Vector<>(input));

        Vector<Integer> tempo = new Vector<>();
        tempo.add(tempo_desor.get(0));
        tempo.add(tempo_desor.get(1));
        tempo.add(tempo_orden.get(0));
        tempo.add(tempo_orden.get(1));

        String name_output = csv.readNameOutput("dataset/valores.csv");
        csv.writeCSV(name_output, tempo);
    }
}
