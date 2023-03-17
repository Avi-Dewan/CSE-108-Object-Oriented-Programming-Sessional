public abstract class Mammal extends Animal {
    private String blood;
    public Mammal(String name, int age, String blood) {

        super(name, age);
        this.blood = blood;
    }


    public void printBloodType() {
        System.out.println(blood + "-bloded");
    }
}
