package tcpforward;

import util.NetworkUtil;

import java.util.List;
import java.util.Scanner;

public class Client {

    public Client(String serverAddress, int serverPort) {
        try {
            System.out.print("Enter name of the client: ");
            Scanner scanner = new Scanner(System.in);
            String clientName = scanner.nextLine();
            NetworkUtil networkUtil = new NetworkUtil(serverAddress, serverPort);

            printClientMenu();

            while (true) {
                int m = scanner.nextInt();
//                scanner.nextLine();

                switch (m) {
                    case 1:
                        networkUtil.write(clientName);
                        break;
                    case 2:
                        printLists();
                        break;
                    case 3:
                        new WriteThreadClient(networkUtil, clientName);
                        break;
                    case 4:
                        new WriteThreadClientAll(networkUtil, clientName, ClientLIst.getList());

                }

                new ReadThreadClient(networkUtil);
            }


        } catch (Exception e) {
            System.out.println(e);
        }
    }



    public static void main(String args[]) {
        String serverAddress = "127.0.0.1";
        int serverPort = 33333;
        Client client = new Client(serverAddress, serverPort);
    }

    private void printClientMenu() {
        System.out.println("1. Connect\n" +
                           "2. GetList\n" +
                           "3. SendOne\n" +
                           "4. BroadCast\n");
    }

    private void printLists() {
       List<String> list = ClientLIst.getList();

       for(String s: list) {
           System.out.println(s);
       }
    }
}


