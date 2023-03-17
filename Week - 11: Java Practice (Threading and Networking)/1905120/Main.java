//Complete the following Java code that finds the total number of square numbers from a 100000 random integers array using an array of 20 threads in parallel. You cannot write any more classes.

import java.util.Random;

class ParallelSquareCounter implements Runnable {
    private int[] numbers;
    private int startIndex;
    private static final int NUMBER_COUNT = 5000;
    private int squareCount;
    // you are not allowed to add any more fields

    // you are not allowed to change this constructor, and you are not allowed to add any more constructor
    ParallelSquareCounter(int[] numbers, int startIndex) {
        this.numbers = numbers;
        this.startIndex = startIndex;
        this.squareCount = 0;
    }
    // your code here


    public int getSquareCount() {
        return squareCount;
    }

    public static int getNumberCount() {
        return NUMBER_COUNT;
    }


    public void run(){
        for(int i = startIndex; i < startIndex + NUMBER_COUNT; i++) {
            if(checkSquare(numbers[i])) {
                squareCount++;
            }
        }
    }

    private boolean checkSquare(int a) {
        for(int i = 1; i*i <= a; i++) {
            if(i*i == a) return true;
        }

        return false;
    }
}

public class Main {
    public static void main(String[] args) {
        Random random = new Random();
        final int NUMBER_COUNT = 100000;
        final int THREAD_COUNT = 20;
        int[] numbers = new int[NUMBER_COUNT];
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = random.nextInt();
        }
        ParallelSquareCounter[] parallelSquareCounters = new ParallelSquareCounter[THREAD_COUNT];
        Thread[] threads = new Thread[THREAD_COUNT];
        // your code here

        for(int i = 0; i < THREAD_COUNT; i++) {
            parallelSquareCounters[i] = new ParallelSquareCounter(numbers, i* ParallelSquareCounter.getNumberCount());
            threads[i] = new Thread(parallelSquareCounters[i]);
            threads[i].start();
        }

        for(int i = 0; i < THREAD_COUNT; i++) {
            try {
                threads[i].join();
            } catch (Exception e) {
                System.out.println(e);
            }
        }

        int total = 0;
        for(int i = 0; i < THREAD_COUNT; i++) total += parallelSquareCounters[i].getSquareCount();

        System.out.println("Total square numbers = " + total);
    }
}