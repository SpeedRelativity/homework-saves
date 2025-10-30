import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException{

        Random rng = new Random(System.currentTimeMillis());
        List<String> dict = Files.readAllLines(Paths.get("dictionary.txt"));


        List<String> chosen = new ArrayList<>();
        for (int k = 0; k < 4; k++){
            int index = rng.nextInt(dict.size());
            String w = dict.get(index);

            chosen.add(w);
            System.out.println(w);
        }

        char[] g = new char[16];
        int pos = 0;
        for (int w = 0; w < 4; w++) {
            for (int i = 0; i < 4; i++) {
                g[pos++] = chosen.get(w).charAt(i);
            }
        }

        for (int i = g.length - 1; i > 0; i--) {
            int j = rng.nextInt(i + 1);
            char tmp = g[i];
            g[i] = g[j];
            g[j] = tmp;
        }

        for (int i = 0; i < g.length; i++) {
            System.out.print(g[i]);
            System.out.print(i % 4 == 3 ? '\n' : ' ');
        }

        try (Scanner sc = new Scanner(System.in)) {
            for (int attempt = 1; attempt <= 3; attempt++) {
                System.out.println("Attempt " + attempt + ":");
                int correct = 0;

                for (int i = 0; i < 4; i++) {
                    String guess = sc.next();
                    for (String ans : chosen) {
                        if (guess.equals(ans)) {
                            correct++;
                            break;
                        }
                    }
                }

                if (correct == 4) {
                    System.out.println("You win!");
                    return;
                } else {
                    System.out.println("Correct during attempt: " + correct);
                }
            }
        }

        System.out.println("Out of attempts. words were:");
        for (String ans : chosen) System.out.println(ans);
    }


}