public class Club {
    private int id;
    private String name;
    private Player[] players;
    // add your code here
    private int playerCount;

	// you are not allowed to write any other constructor
    public Club() {
        this.players = new Player[11];
        this.playerCount = 0;
    }

	public double getSalary() {
        double total = 0;
        for (int i = 0; i < playerCount; i++) {
            total += players[i].getSalary();
        }
        return total;
    }
	
	// add your code here
    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getId() {
        return this.id;
    }
    public String getName() {
        return  this.name;
    }

    public void addPlayer(Player player) {
        this.players[this.playerCount] = player;
        this.playerCount++;
    }

    public Player getMaxSalaryPlayer() {
        Player maxP = this.players[0];
        for(int i = 1; i < this.playerCount; i++) {
            if(this.players[i].getSalary() > maxP.getSalary())  {
                maxP = this.players[i];
            }
        }

        return maxP;
    }


}