public class Club {
    private int id;
    private String name;
    private int point;

    public Club() {
        this.id = 0;
        this.name = "";
        this.point = 0;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public  void setPoint(int point) {
        this.point = point;
    }

    public int getId() {
        return this.id;
    }

    public String getName() {
        return  this.name;
    }

    public int getPoint() {
        return this.point;
    }
}
