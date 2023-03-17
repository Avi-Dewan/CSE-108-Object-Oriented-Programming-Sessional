package tcpforward;

import util.NetworkUtil;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class WriteThreadClientAll implements Runnable {
    private Thread thr;
    private NetworkUtil networkUtil;
    private String name;
    private ArrayList<String> toList;

    public WriteThreadClientAll(NetworkUtil networkUtil, String name, ArrayList<String> toList) {
        this.networkUtil = networkUtil;
        this.name = name;
        this.toList = toList;
        this.thr = new Thread(this);
        thr.start();
    }

    public void run() {
        try {
            Scanner input = new Scanner(System.in);
            System.out.print("Enter the message: ");
            String text = input.nextLine();
            String from = name;

            for(String to: toList) {
                while (true) {

                    Message message = new Message();
                    message.setFrom(from);
                    message.setTo(to);
                    message.setText(text);
                    networkUtil.write(message);
                }
            }

        } catch (Exception e) {
            System.out.println(e);
        } finally {
            try {
                networkUtil.closeConnection();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
