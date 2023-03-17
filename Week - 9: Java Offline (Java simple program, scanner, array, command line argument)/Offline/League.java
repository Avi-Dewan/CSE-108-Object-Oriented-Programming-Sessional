public class League {
    private Match[] matches;
    private int matchCount;
    private int clubCount;
    // add your variables here, if required
    private String leagueName;
    private Club []c;

    public League() {
        // assume a league can have at most 5 clubs, add code for initialization accordingly
        clubCount = 0;
        matchCount = 0;
        this.c = new Club[5];
    }

    public void printLeagueInfo(){
        System.out.println("League : " + this.leagueName);
        printClubs();
    }

    public void printClubs(){
        System.out.println("Clubs:");
        // print the name of the clubs of this league, each one on a line
        for (int i=0; i <clubCount; i++) {
            System.out.println(c[i].getName());
        }
    }

    public void scheduleMatches(){
        matchCount = (clubCount*(clubCount-1));
        matches = new Match[matchCount];
        int matchNo = 0;
        for (int i=0; i<clubCount; i++){
            for (int j=i+1; j<clubCount; j++){
                // check the constructor of the Match class and add your code here
                // note that there will be two matches between club A and club B
                // in the first match, club A will play as the home team and in the second match, as the away team
                matches[matchNo] = new Match(matchNo, c[i], c[j]);
                matchNo++;
                matches[matchNo] = new Match(matchNo, c[j], c[i]);
                matchNo++;
            }
        }
    }

    public void simulateMatches(){
        for (int i=0; i<matchCount; i++){
            matches[i].play();
        }
    }

    public void showStandings(){
        // sort the clubs in descending order of points
        // note that, the sequence in which clubs were added to the league, should be unchanged
        // check the given sample output for clarification
        // (carefully observe the output of showStandings() followed by printLeagueInfo() method calls
        // you can use additional arrays if needed
        Club []temp = new Club[clubCount];

        for(int i = 0; i < clubCount; i++) {
            temp[i] = new Club();
            temp[i].setId(c[i].getId());
            temp[i].setPoint(c[i].getPoint());
            temp[i].setName(c[i].getName());
        }

        for (int i=0; i<clubCount; i++) {
            for (int j = i + 1; j < clubCount; j++) {
                if(temp[i].getPoint() < temp[j].getPoint()) {
                    Club x = temp[i];
                    temp[i] = temp[j];
                    temp[j] = x;
                }
            }
        }

        System.out.println("Sl. - Club - Points");
        // print the clubs in descending order of points
        for(int i = 0; i < clubCount; i++) {
            System.out.println((i+1) + ". " + temp[i].getName() + " " + temp[i].getPoint());
        }
    }

    // add your methods here, if required

    public void setName(String leagueName) {
        this.leagueName = leagueName;
    }

    public void addClub(Club club) {
        c[clubCount] = club;
        clubCount++;
    }

    public void printMatches() {
        System.out.println("Matches:");

        for (int i=0; i<matchCount; i++){
            matches[i].showResult();
        }
    }

    public void removeClub(Club club) {
        int idx = -1;
        for(int i = 0; i < clubCount; i++) {
            if(c[i].getId() == club.getId()) {
                idx = i;
                break;
            }
        }

        if(idx != -1) {
            for(int i = idx; i < clubCount-1; i++) c[i] = c[i+1];
        }

        clubCount--;
    }
}

