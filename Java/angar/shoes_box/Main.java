package angar.shoes_box;
import java.util.stream.*;
import java.util.List;
import java.util.ArrayList;
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
               
    static int shoes_num = 200;
    static String styles[] = {
        "boot",
        "sneaker",
        "sandal",
        "pump",
        "highheel"};
        
    public static <T> Collector<T, ?, List<T>> toList(int size) {
          return Collectors.toCollection(() -> new ArrayList<T>(size));
    }
    
    List<Shoe> shoesFactory(int shoes_num) {
        return IntStream.range(0, shoes_num).mapToObj(shoe -> new Shoe(shoe  % 12, styles[shoe % 5] + shoe)).collect(toList(shoes_num / styles.length + styles.length));
    }

    List<Shoe> process(List<Shoe> shoes, int size) {
        return shoes.stream().filter(shoe -> shoe.size == size).collect(Collectors.toList());
    }
    
    public static void main(String ...args) {
        Main main = new Main();
        int iters = 1000;
        if (args.length > 0) {
            iters = Integer.valueOf(args[0]);
        }

        long found_num = IntStream.range(0, iters).map(x -> {
            List<Shoe> myshoes = main.process(main.shoesFactory(shoes_num), 10);
            if (x == 0) {
                myshoes.forEach(System.out::println);
            }
            return myshoes.size();
          }).sum();
           
        System.out.printf("Done found %d pairs after %d iteration(s)\n", found_num, iters);
    }
}
