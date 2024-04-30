package hello;
import java.text.DecimalFormat;

public class LoopCount {
    static volatile boolean stop = false;
    public static void runLoop(int sleepTime)
    {
        long count = 0, start = 0, end = 0;
        new Thread(() -> {
            try {
                Thread.sleep(sleepTime);
            } catch (InterruptedException e) {
                // Ignore it
            }
            stop = true; // Stop the loop
        }).start();

        start = System.currentTimeMillis();

        for (; count >= 0; count++) {
            if (stop) break;
        }
        end = System.currentTimeMillis();
       	DecimalFormat formatter = new DecimalFormat("#,###");
        System.out.println("start: " + start + "\n end: " + end + "\ncount: " + formatter.format(count));
    }

    public static void main(String args[]) {
        LoopCount.runLoop(1000);
    }
}
