package angar.shoes_box;
import java.util.stream.*;
import java.util.List;
import java.io.IOException;

public class Main {
    
    static class Shoe {
        int size;
        String style;
        Appendable save(Appendable os) throws IOException {
            return os.append(""+size).append(", ").append(style);
        }
        
        public String toString() {
            try {
                StringBuffer sb = new StringBuffer();
                return save(sb).toString();
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
    
    List<Shoe> process(int size) {
        Shoe[] arrayOfShoes = {
            new Shoe(10, "sneaker"),
            new Shoe(13, "sandal"), 
            new Shoe(10, "boot"), 
            new Shoe(10, "boot2"), 
            new Shoe(12, "boot"), 
            new Shoe(10, "boot3"), 
            new Shoe(11, "boot"), 
            new Shoe(10, "boot4"), 
            new Shoe(9, "boot"), 
            new Shoe(10, "boot5")
        };
        return Stream.of(arrayOfShoes).filter(shoe -> shoe.size == size).collect(Collectors.toList());
    }
    
    public static int main(String ...args) {
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
        return 0;
    }
    
}
