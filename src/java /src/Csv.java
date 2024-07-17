import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Vector;

public class Csv {
    
    public Csv() {
        // Construtor vazio
    }

    public Vector<Integer> readCSV(String filename) {
        System.out.println(filename);

        Vector<Integer> numbers = new Vector<>();
        boolean firstLine = true;
        
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (firstLine) {
                    firstLine = false;
                    continue; // Ignora o cabeçalho
                }

                int number = Integer.parseInt(line.trim());
                numbers.add(number);
            }
        } catch (IOException | NumberFormatException e) {
            System.err.println("Erro ao ler o arquivo CSV: " + e.getMessage());
            System.exit(1);
        }
        return numbers;
    }

    public void writeCSV(String filename, Vector<Integer> newData) {
        // Exibe os novos dados no console
        System.out.print("Novos dados: ");
        for (int num : newData) {
            System.out.print(num + ", ");
        }
        System.out.println("\n--------------------------");

        // Armazena as linhas do arquivo CSV em uma lista de strings
        Vector<String> lines = new Vector<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                lines.add(line);
            }
        } catch (IOException e) {
            System.err.println("Erro ao abrir o arquivo " + filename + " para leitura.");
            return;
        }

        // Escreve os dados atualizados no arquivo CSV
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filename))) {
            // Escreve o cabeçalho do arquivo CSV (primeira linha)
            if (!lines.isEmpty()) {
                bw.write(lines.get(0));
                bw.write("\n");
            }

            // Escreve os dados atualizados
            int contador;
            for (int i = 1; i < lines.size(); ++i) {
                contador = 0;
                for (int j = 0; j < lines.get(i).length(); ++j) {
                    if(contador > 4 && lines.get(i).charAt(j) != ','){
                        continue;
                    }
                    else if (lines.get(i).charAt(j) == ',' && contador == 4) {
                        bw.write("," + newData.get(i - 1));
                        contador++;
                        continue;
                    } else if (lines.get(i).charAt(j) == ',') {
                        contador++;
                    }
                    bw.write(lines.get(i).charAt(j));
                }
                bw.write("\n");
            }
        } catch (IOException e) {
            System.err.println("Erro ao abrir o arquivo " + filename + " para escrita.");
        }
    }
}
