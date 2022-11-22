package angar.shoes_box;
import java.util.stream.*;
import java.util.List;
import java.io.IOException;

public class Main {
    
    class Shoe {
        int size;
        String style;
        Appendable save(Appendable os) throws IOException {
            return os.append(""+size).append(", ").append(style);
        }
        
        public String toString() {
            try {
                return save(new StringBuffer()).toString();
            } catch(IOException ioe) {
                // ignore
                return "IO exception: "+ioe;
            }
        }
        
        Shoe(int size, String style) {
            this.size = size;
            this.style = style;
        }
    }
    
    static String styles[] = {
                "boot",
                "sneaker",
                "sandal",
                "pump",
                "highheel"};
                
    static int shoes_num = 200;
    
    List<Shoe> process(int size) {
        return IntStream.range(0, shoes_num).mapToObj(shoe -> new Shoe(shoe  % 12, styles[shoe % 5]+shoe)).filter(shoe -> shoe.size == size).collect(Collectors.toList());
    }
    
    public static void main(String ...args) {
        Main main = new Main();
        int iters = 1000;
        if (args.length > 0)
            iters = Integer.valueOf(args[0]);
        IntStream.range(0, iters)
            .forEach(index -> {
                List<Shoe> myshoes = main.process(10);
                if (index == 0) {
                    myshoes.forEach(System.out::println);
                }
            });
        System.out.printf("Done with %d iteration(s)\n", iters);
    }
}
