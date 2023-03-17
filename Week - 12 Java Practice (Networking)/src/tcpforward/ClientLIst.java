package tcpforward;

import util.NetworkUtil;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;


public class ClientLIst implements Serializable {

    public static HashMap<String, NetworkUtil> map;

    public ClientLIst(HashMap<String, NetworkUtil> map) {
        this.map = map;
    }

    public static ArrayList<String> getList() {
        ArrayList<String> List = new ArrayList<>();

        for (String i : map.keySet()) {
            List.add( i);
        }

        return List;
    }
}
